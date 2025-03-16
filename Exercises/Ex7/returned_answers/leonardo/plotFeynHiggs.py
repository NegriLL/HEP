import ROOT
import numpy as np

def readValuesHD(fileName):
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

def readValuesFH(fileName):
    with open(fileName, "r") as file:
        hmass = np.array([], dtype=float)
        width = np.array([], dtype=float)
        # Skip header
        file.readline()
        file.readline()
        file.readline()
        for line in file:
            row = line.strip("\n")
            row = row.split("\t")
            hmass = np.append(hmass, float(row[0]))
            width = np.append(width, float(row[1]))
        return hmass, width       

def main():
    (hmassHD, widthHD) = readValuesHD("br.sm2")
    (hmassFH, widthFH) = readValuesFH("results.txt")
    
    canvas = ROOT.TCanvas("c1", "HMass vs Width", 800, 600)
    canvas.Divide(1,2)
    # Creating Graph HD
    n = len(hmassHD)
    graph1 = ROOT.TGraph(n, hmassHD, widthHD)
    graph1.SetTitle("Higgs Decay Width")
    graph1.GetXaxis().SetTitle("Higgs Mass (GeV)")
    graph1.GetYaxis().SetTitle("Width")
    graph1.SetLineColor(ROOT.kRed)
    graph1.SetLineWidth(2)
    
    # Creating Graph FH
    n = len(hmassFH)
    graph2 = ROOT.TGraph(n, hmassFH, widthFH)
    graph2.SetLineColor(ROOT.kBlue)
    graph2.SetLineWidth(2)
    
    # First Graph
    canvas.cd(1)
    graph1.Draw("ALP")
    graph2.Draw("LP SAME")
    
    # Legend
    legend = ROOT.TLegend(0.1, 0.7, 0.48, 0.9)
    legend.SetHeader("Legend")
    legend.AddEntry(graph1, "HDecay", "l")
    legend.AddEntry(graph2, "FeynHiggs", "l")
    legend.Draw()
    
    # Second Graph
    ratio = [widthFH[i] / widthHD[i] for i in range(len(widthFH))]
    ratio = np.array(ratio)
    ratio_graph = ROOT.TGraph(n, hmassFH, ratio)
    ratio_graph.SetLineColor(ROOT.kBlack)
    ratio_graph.SetLineWidth(2)
    ratio_graph.GetXaxis().SetTitle("Mass (GeV)")
    ratio_graph.GetYaxis().SetTitle("Ratio")
    ratio_graph.SetTitle("FeynHiggs / HDecay")
    
    canvas.cd(2)
    ratio_graph.Draw("ALP")
    

    canvas.SaveAs("Comparison.png")
    # Waiting for input so the canvas doesn't close
    input("Press enter to continue...")
    
main()
