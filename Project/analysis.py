#!/usr/bin/env python 

import ROOT
import numpy as np
import re

def smearedVector(pT, theta, phi, eT, smear):
    ptSmear = smear.Gaus(pT, pT*0.01)
    phiSmear = smear.Gaus(phi, phi + 0.002)
    thetaSmear = smear.Gaus(theta, theta + 0.002)
    eta = -np.log(np.tan(theta/2))
    return ROOT.Math.PtEtaPhiEVector(ptSmear, eta, phiSmear, eT)

def getWeight(fileName):
    sigma_re = re.compile(r"Weighted Cross Section: (?P<sig>\S+) fb")
    with open(fileName) as file:
        for line in file:
            match = sigma_re.search(line)
            if match:
                sigma = float(match.group("sig"))
                return sigma
                
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
        muonVector = smearedVector(muonPt, muonTheta, muonPhi, muonE, smear)
        # Setting nearby pion charge and event number
        pionP = getattr(tree, "pionP")
        eventNumber = getattr(tree, "eventNumber")
        
        if(muonPt > 30 and pionP < 1.5):
            if(eventNumber not in events):
                events[eventNumber] = [muonVector]
            else:
                events[eventNumber].append(muonVector)
            if(verbose):
                print("{}\t\t{:.4f}\t\t{:.4f}\t\t{:.4f}\t\t{:.4f}\t\t{:.4f}".format(eventNumber,
                                                                             muonVector.pt(),
                                                                             muonVector.Eta(),
                                                                             muonVector.Phi(),
                                                                             muonVector.E(),
                                                                             pionP))
    return events

def main():
    minPt = 30
    maxPionCharge = 1.5
    verbose = False
    selectedEvents = 0
    
    # Signal Info
    signalFile = ROOT.TFile.Open("signal.root", "READ")
    signalTree = signalFile.Get("signal")
    signalWeight = getWeight("signal.out")
    
    # Noise Info
    noiseFile = ROOT.TFile.Open("noise.root", "READ")
    noiseTree = noiseFile.Get("noise")
    noiseWeight = getWeight("noise.out")
    
    # Selecting Candidates
    if(verbose): print("Muon data")
    if(verbose): print("event\t\tpT\t\teta\t\tphi\t\tE\t\tpionP")
    signalEvents = getEvents(minPt, maxPionCharge, signalTree, verbose)
    noiseEvents = getEvents(minPt, maxPionCharge, noiseTree, verbose)
    
    # Drawing signal histogram
    hist = ROOT.TH1F("Invariant Mass", "Mass Distribution", 100, 0, 100)
    for i in signalEvents:
        if len(signalEvents[i]) == 2:
            selectedEvents += 1
            mass = abs((signalEvents[i][0] + signalEvents[i][1]).M())
            hist.Fill(mass, signalWeight)
    for i in noiseEvents:
        if len(noiseEvents[i]) == 2:
            selectedEvents += 1
            mass = abs((noiseEvents[i][0] + noiseEvents[i][1]).M())
            hist.Fill(mass, noiseWeight)

    canvas = ROOT.TCanvas("canvas", "Invariant Mass Distribution", 800, 600)
    gaus = ROOT.TF1("gaus", "gaus", 0, 100)
    
    hist.Draw("HIST")
    canvas.SaveAs("Mass Distribution.png")
    
    print("Number of Selected Events: {}".format(selectedEvents))

main()











