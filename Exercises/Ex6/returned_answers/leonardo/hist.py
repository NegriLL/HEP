import ROOT
import random
from array import array

file = ROOT.TFile("random_numbers.root", "RECREATE")
tree = ROOT.TTree("tree", "Random Numbers")

x = array('d', [0])
tree.Branch("x", x, 'x/D')

for i in range(1000):
    x[0] = random.gauss(0,1)
    tree.Fill()
    
tree.Write()
file.Close()

file = ROOT.TFile("random_numbers.root", "READ")
tree = file.Get("tree")

hist = ROOT.TH1F("hist", "Histogram", 100, -5, 5)
hist.SetLineColor(ROOT.kBlack);
hist.SetFillColor(ROOT.kYellow);
hist.SetLineWidth(4);

canvas = ROOT.TCanvas("canvas", "Histogram", 800, 600)
tree.Draw("x>>hist")

input("Enter to exit...")

file.Close()
