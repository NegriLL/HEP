#include <iostream>

#include <TRandom3.h>
#include <TFile.h>
#include <TTree.h>

int main(int argc, char** argv){
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
    
    std::cout << "Tree saved!" << std::endl;
    return 0;
}
