#!/usr/bin/env python

import ROOT

def main():

    ROOT.gSystem.Load("libMyAnalysis.so")

    tchain = ROOT.TChain("Events")
    tchain.Add("DYJetsToLL.root")

    tselector = ROOT.MyAnalysis()

    tchain.Process(tselector)
    
    file = ROOT.TFile.Open("output.root")
    hist = file.Get("h_pileup")

    canvas = ROOT.TCanvas("c1", "Pileup Distribution", 800, 600)
    hist.Draw()

    canvas.SaveAs("pileup_distribution.png")

    input("Press Enter to exit...")

main()
