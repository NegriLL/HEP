void makeTree() {

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
}
