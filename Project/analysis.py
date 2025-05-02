#!/usr/bin/env python
import ROOT
import numpy as np
import re

SIGNAL_FILE = "GenData/signal.out"
NOISE_FILE = "GenData/noise.out"
SIGNAL_ROOT = "GenData/signal.root"
NOISE_ROOT = "GenData/noise.root"

def smearedVector(pT, theta, phi, e, smear):
    ptSmear = smear.Gaus(pT, pT*0.01)
    phiSmear = smear.Gaus(phi, 0.002)
    thetaSmear = smear.Gaus(theta, 0.002)
    eta = -np.log(np.tan(theta/2))
    return ROOT.Math.PtEtaPhiEVector(ptSmear, eta, phiSmear, e)

def getWeight(fileName):
    sigma_re = re.compile(r"Weighted Cross Section: (?P<sig>\S+) fb")
    with open(fileName) as file:
        for line in file:
            match = sigma_re.search(line)
            if match:
                sigma = float(match.group("sig"))
                return sigma
    print("FAILED TO FIND WEIGHT")
    return 1
                
def getEvents(minPt, maxPionCharge, tree, verbose):
    events = {}
    smear = ROOT.TRandom3()

    for i in range(tree.GetEntries()):
        tree.GetEntry(i)
        # Settiing muon properties
        muonPt = getattr(tree, "muonPt")
        muonPhi = getattr(tree, "muonPhi")
        muonTheta = getattr(tree, "muonTheta")
        muonE = getattr(tree, "muonE")
        muonEta = -np.log(np.tan(muonTheta/2))
        muonVector = smearedVector(muonPt, muonTheta, muonPhi, muonE, smear)
        # Setting nearby pion charge and event number
        pionP = getattr(tree, "pionP")
        eventNumber = getattr(tree, "eventNumber")
        # Cut offs
        if(muonPt > minPt and pionP < maxPionCharge):
            if(eventNumber not in events):
                events[eventNumber] = [muonVector]
            else:
                events[eventNumber].append(muonVector)
            if(verbose):
                printMuonInfo(eventNumber, muonVector, pionP)
    return events
    
def printMuonInfo(eventNumber, muonVector, pionP):
    print("{}\t\t{:.4f}\t\t{:.4f}\t\t{:.4f}\t\t{:.4f}\t\t{:.4f}".format(eventNumber,
                                                                        muonVector.pt(),
                                                                        muonVector.Eta(),
                                                                        muonVector.Phi(),
                                                                        muonVector.E(),
                                                                        pionP))

def main():
    minPt = 30
    maxPionCharge = 1.5
    verbose = False
    
    # Signal Info
    signalFile = ROOT.TFile.Open(SIGNAL_ROOT, "READ")
    signalTree = signalFile.Get("signal")
    signalWeight = getWeight(SIGNAL_FILE)
    
    # Noise Info
    noiseFile = ROOT.TFile.Open(NOISE_ROOT, "READ")
    noiseTree = noiseFile.Get("noise")
    noiseWeight = getWeight(SIGNAL_FILE)
    
    # Selecting Candidates
    if(verbose): print("Muon data")
    if(verbose): print("event\t\tpT\t\teta\t\tphi\t\tE\t\tpionP")
    signalEvents = getEvents(minPt, maxPionCharge, signalTree, verbose)
    noiseEvents = getEvents(minPt, maxPionCharge, noiseTree, verbose)
    
    # Drawing signal histogram
    xmin = 0
    xmax = 180
    bins = 150
    hist = ROOT.TH1F("Invariant Mass", "Mass Distribution", bins, xmin, xmax)
    histNoise = ROOT.TH1F("Invariant Mass Noise", "Mass Distribution", bins, xmin, xmax)
    for i in signalEvents:
        if len(signalEvents[i]) == 2:
            mass = abs((signalEvents[i][0] + signalEvents[i][1]).M())
            hist.Fill(mass, signalWeight)
    for i in noiseEvents:
        if len(noiseEvents[i]) == 2:
            mass = abs((noiseEvents[i][0] + noiseEvents[i][1]).M())
            hist.Fill(mass, noiseWeight)
            histNoise.Fill(mass, noiseWeight)
    
    c1 = ROOT.TCanvas("c", "Canvas", 1600, 1200)
    # Fitting Signal + Background and drawing
    gaus = ROOT.TF1("gaus", "gaus", 85, 100)
    gaus.SetLineColor(ROOT.kBlue)
    gaus.SetLineWidth(3)
    gaus.SetNpx(5000)
    hist.Fit(gaus, "RQ")
    gaus.SetRange(xmin, xmax)
    
    gausNoise = ROOT.TF1("gaus2", "gaus", xmin, xmax)
    gausNoise.SetNpx(1000)
    gausNoise.SetLineColor(ROOT.kRed)
    gausNoise.SetLineWidth(3)
    histNoise.Fit(gausNoise, "RQ+")
    
    # Integrating Events
    signalCount = gaus.Integral(89, 93)
    noiseCount = gausNoise.Integral(0, 180)
    
    # Adding labels
    hist.GetXaxis().SetTitle("Invariant Mass (GeV)")
    hist.GetYaxis().SetTitle("Events (fb)")
    
    # Statistical significance
    print()
    sigma = signalCount/np.sqrt(noiseCount)
    print("Signal Events: {:.3f}".format(signalCount))
    print("Noise Events: {:.3f}".format(noiseCount))
    print("Statistical significance is: {:.3f}".format(sigma))
    
    hist.Draw("HIST")
    gaus.Draw("SAME")
    gausNoise.Draw("SAME")
    
    # Drawing legend
    legend = ROOT.TLegend(0.15, 0.7, 0.4, 0.85)
    legend.AddEntry(gaus, "Signal Fit", "l")
    legend.AddEntry(gausNoise, "Background Fit", "l")
    legend.Draw()
    
    # Adding stats to histogrma
    legend.AddEntry(0, "Signal    {:.3f}".format(signalCount), "")
    legend.AddEntry(0, "Noise    {:.3f}".format(noiseCount), "")
    legend.AddEntry(0, "Sigma    {:.3f}".format(sigma), "")
    
    c1.SaveAs("Graphs/Mass Distribution.png")
    c1.SaveAs("Graphs/Mass Distribution.C")
    c1.SaveAs("Graphs/Mass Distribution.pdf")

main()











