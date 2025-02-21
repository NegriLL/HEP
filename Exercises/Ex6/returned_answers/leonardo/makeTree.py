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
print("Tree saved!")
file.Close()
