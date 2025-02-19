#include <iostream>

#include <TROOT.h>
#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TApplication.h>
#include <TF1.h>
#include <TRandom3.h>

int main(int argc, char** argv){
    TApplication app("Root Application", &argc, argv);
    TRandom3 rand;

    TFile* file = new TFile("random_numbers.root", "RECREATE");
    TTree* tree = new TTree("tree", "Random Numbers");

    double x;
    tree->Branch("x", &x, "x/D");

    for (int i = 0; i < 1000; i++){
        x = rand.Gaus(0, 1);
        tree->Fill();
    }

    tree->Write();
    file->Close();
    
    file = new TFile("random_numbers.root", "READ");
    tree = (TTree*)file->Get("tree");
    TH1F* hist = new TH1F("hist", "Random Numbers", 100, -5, 5);

    hist->SetLineColor(kBlack);
    hist->SetFillColor(kYellow);
    hist->SetLineWidth(4);

    hist->GetXaxis()->SetTitle("Value");
    hist->GetYaxis()->SetTitle("Count");

    tree->Draw("x>>hist");
    
    TCanvas *canvas = new TCanvas("canvas", "Histogram", 800, 600);
    hist->Draw();

    hist->Fit("gaus");
    TF1* fitFunc = hist->GetFunction("gaus");
    fitFunc->SetLineColor(kRed);
    fitFunc->SetLineWidth(4);
    fitFunc->Draw("SAME");
    
    app.Run();
    
    file->Close();
    delete file;
    return 0;

}
