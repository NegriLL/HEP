void makeHist(){
    TFile* file = TFile::Open("random_numbers.root");
    TTree* tree = (TTree*)file->Get("tree");
    TH1F* hist = new TH1F("hist", "Random Numbers", 100, -5, 5);
    
    hist->SetLineColor(kBlack);
    hist->SetFillColor(kYellow);
    hist->SetLineWidth(4);
    
    hist->GetXaxis()->SetTitle("Value");
    hist->GetYaxis()->SetTitle("Count");
    
    tree->Draw("x>>hist");
    hist->Draw();
    
    hist->Fit("gaus");
    TF1* fitFunc = hist->GetFunction("gaus");
    fitFunc->SetLineColor(kRed);
    fitFunc->SetLineWidth(4);
    fitFunc->Draw("SAME");
      
}
