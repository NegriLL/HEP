import ROOT
import random

file = ROOT.TFile("random_numbers.root", "RECREATE")
tree = ROOT.TTree("tree", "Random Numbers")

x = ROOT.std.vector('double')()
tree.Branch("x", value)

for i in range(1000):
    x.clear()
    x.push_back(random.gauss(0,1))
    tree.Fill()
    
tree.Write()
tree.Close()

file = ROOT.TFile("random_numbers.root", "READ")
tree = file.Get("tree")

hist = ROOT.TH1F("hist", "Histogram", 100, -5, 5)

canvas = ROOT.TCanvas("canvas", "Histogram", 800, 600)

tree.Draw("x>>hist")

gausFit = ROOT.TF1("gausFit", "gaus", -5, 5)
hist.Fit(gausFit, "R")

canvas.Draw()
input("Enter to exit...")

file.Close()
