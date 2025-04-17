#!/usr/bin/env python                                                                                                                

import sys
import os
import re
import math
import ROOT

def usage():
    print("\n### Usage:  ",os.path.basename(sys.argv[0])," <pythia output file>\n")
    sys.exit()

def main():
    if len(sys.argv) < 2:
        usage()

    if not os.path.exists(sys.argv[1]):
        usage()

    momentum_re = re.compile(r"Muon pt,eta,phi (?P<pt>\S+) +(?P<eta>\S+) +(?P<phi>\S+)")
    nev_re = re.compile(r"Number of events (?P<N>\d+)")

    nbins = 50
    h_pt  = ROOT.TH1F("h_pt","",nbins,0,10)
    h_eta = ROOT.TH1F("h_eta","",nbins,-5,5)

    genEvents     = 0
    allMuonEvents = 0
    passedEvents  = 0

    fIN = open(sys.argv[1])
    for line in fIN:
        nev_match = nev_re.search(line)
        if nev_match:
            genEvents = int(nev_match.group("N"))
        match = momentum_re.search(line)
        if match:
            pt  = float(match.group("pt"))
            eta = float(match.group("eta"))

            h_pt.Fill(pt)
            h_eta.Fill(eta)

            allMuonEvents += 1
            if pt > 5 and math.fabs(eta) < 2.5:
                passedEvents += 1

    canvas = ROOT.TCanvas("canvas","",700,500)
    canvas.SetFillColor(0)
    canvas.Divide(2,1)

    canvas.cd(1)
    h_pt.SetStats(0)
    h_pt.SetFillColor(5)
    h_pt.GetXaxis().SetTitle("muon p_{T} [GeV]")
    h_pt.Draw()

    canvas.cd(2)
    h_eta.SetStats(0)
    h_eta.SetFillColor(5)
    h_eta.GetXaxis().SetTitle("muon #eta")
    h_eta.Draw()

    canvas.Print("muonpteta.eps")

    print("Generated events =",genEvents)
    # assuming that finding more than 1 muon/event can be neglected
    print("All muon events  =",allMuonEvents)
    print("Passed events    =",passedEvents)
    print("Probability for passing = Passed events / Generated events =",float(passedEvents)/genEvents)

if __name__ == "__main__":
    main()
