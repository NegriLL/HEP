import ROOT
import numpy as np

def readValues(fileName):
    with open(fileName, "r") as file:
        hmass = np.array([], dtype=float)
        width = np.array([], dtype=float)
        # Skip header
        file.readline()
        file.readline()
        file.readline()
        for line in file:
            row = line.strip("\n")
            row = row.split(" ")
            row = [x for x in row if x.strip()]
            hmass = np.append(hmass, float(row[0]))
            width = np.append(width, float(row[-1]))
        return hmass, width       

def main():
    (hmass, width) = readValues("br.sm2")
    
    # Creating Graph
    n = len(hmass)
    canvas = ROOT.TCanvas("c1", "HMass vs Width", 800, 600)
    graph = ROOT.TGraph(n, hmass, width)
    
    # Setting Options
    graph.SetTitle("HDECAY")
    graph.GetXaxis().SetTitle("Higgs Mass (GeV)")
    graph.GetYaxis().SetTitle("Width")
    graph.GetYaxis().SetTitleOffset(1.5)
    
    graph.Draw("ALP")
    canvas.SaveAs("HDECAY Graph.png")
    
    # Waiting for input so the canvas doesn't close
    input("Press enter to continue...")
    
main()
