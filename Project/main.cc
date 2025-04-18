#include "Pythia8/Pythia.h"
#include "TFile.h"
#include "TTree.h"
using namespace Pythia8;
using namespace std;

int main() {
    // Starting pythia
    Pythia pythia;
    pythia.readString("Beams:eCM = 13600.");
    //pythia.readString("Top:all = on");
    pythia.readString("WeakSingleBoson:ffbar2gmz = on"); // Weak processes
    pythia.readString("Top:gg2ttbar = on"); // Background events
    pythia.readString("Top:qqbar2ttbar = on");
    pythia.readString("Top:ffbar2ttbar(s:gmz) = on");
    pythia.init();
    
    // Creating root files and tree
    TFile *file = new TFile("MuonTau.root", "RECREATE");
    TTree *tree = new TTree("Events", "Signal and Background events passing trigger");
    
    // Creating branches
    float muon_pT = 0 ; float muon_eta = 0; float muon_phi = 0;
    float top_pT = 0 ; float top_eta = 0; float top_phi = 0;
    
    tree->Branch("muon_pT", &muon_pT);
	tree->Branch("muon_eta", &muon_eta);
	tree->Branch("muon_phi", &muon_phi);
	
	tree->Branch("top_pT", &top_pT);
	tree->Branch("top_eta", &top_eta);
	tree->Branch("top_phi", &top_phi);
	
    
    // Initiating other variables
    int NEV = 1000;
    int NTop = 0;
    int NMuon = 0;
    int NTop_passing = 0;
    int NMuon_passing = 0;
    cout << "Number of events " << NEV << std::endl;

    for (int iEvent = 0; iEvent < NEV; ++iEvent) {
        if (!pythia.next()) continue;
        // Events with the signal (mumu)
        for (int i = 0; i < pythia.event.size(); ++i){
            if (abs(pythia.event[i].id()) == 13){
                NMuon++; // Count the detected muons
                if(pythia.event[i].pT() > 20 && pythia.event[i].eta() < 2.1){
                    NMuon_passing++; // count the threshhold muons
		            muon_pT = pythia.event[i].pT();
		            muon_eta = pythia.event[i].eta();
		            muon_phi = pythia.event[i].phi();
		            tree->Fill();
		        }
            }
        // Events with the background (tt)  
            if (abs(pythia.event[i].id()) == 6){
                NTop++; // Count the detected top quarks
                if(pythia.event[i].pT() > 20 && pythia.event[i].eta() < 2.1){
                    NTop_passing++; // count the threshhold top quarks
		            top_pT = pythia.event[i].pT();
		            top_eta = pythia.event[i].eta();
		            top_phi = pythia.event[i].phi();
		            tree->Fill();
		        }
            }
        }
    }
    
    tree->Write();
    file->Close();
    
    // Summary of results
    float efficiency = float(NMuon_passing) / float(NMuon) * 100;
    cout << endl
         << "Results:\n"
         << "Total Muons: " << NMuon << endl
         << "Passing Muons: " << NMuon_passing << endl
         << "Signal Efficiency: " << efficiency << "%" << endl
         << "Total Top: " << NTop << endl
         << "Passing Top: " << NTop_passing << endl;
    return 0;
}
