#include <iostream>

#include <TApplication.h>
#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TF1.h>

int main(int argc, char** argv){
    TApplication app("Root Application", &argc, argv);
    
    TFile* file = new TFile("random_numbers.root", "READ");
    TTree* tree = (TTree*)file->Get("tree");
    
    TH1F* hist = new TH1F("hist", "Random Numbers", 100, -5, 5);
    TCanvas* canvas = new TCanvas("canvas", "Canvas", 800, 600);
    tree->Draw("x>>hist");
    
    hist->SetLineColor(kBlack);
    hist->SetFillColor(kYellow);
    hist->SetLineWidth(4);
    hist->GetXaxis()->SetTitle("Value");
    hist->GetYaxis()->SetTitle("Count");
    
    // The following part of the code creates a segfault. I am unsure why and
    // the forums haven't helped. After many tries, I will leave this commented
    // out.
    
//    auto fitFunc = new TF1("gausFit", "gaus(0)", -5, 5);
//    fitFunc->SetParameters(hist->GetMaximum(), hist->GetMean(), hist->GetRMS());
//    hist->Fit(fitFunc);
//    fitFunc->SetLineColor(kRed);
//    fitFunc->SetLineWidth(4);
//    fitFunc->Draw("SAME");
//    fitFunc->Draw("same");
    
    app.Run();
    file->Close();
    
    return 0;
}
