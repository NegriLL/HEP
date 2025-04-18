#include "Pythia8/Pythia.h"
#include "TFile.h"
#include "TTree.h"
#include "TRandom3.h"
#include "math.h"
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
    TTree *treeTop = new TTree("Top Quark Events", "Background events passing trigger");
    TTree *treeMuon = new TTree("Muon Events", "Signal events passing trigger");
    TTree *treeMuonSmear = new TTree("Smeared Muon Events", "Signal events passing trigger with smearing");
    TTree *treeMuonSelect = new TTree("Selected Muon Events", "Track Muon events passing trigger with smearing and selection");
    
    // Creating branches
    double muon_pT = 0 ; double muon_eta = 0; double muon_phi = 0;
    double top_pT = 0 ; double top_eta = 0; double top_phi = 0;
    double muon_pT_smear = 0 ; double muon_eta_smear = 0; double muon_phi_smear = 0;
    double muon_pT_select = 0 ; double muon_eta_select = 0; double muon_phi_select = 0;
    
    treeTop->Branch("muon_pT", &muon_pT);
	treeTop->Branch("muon_eta", &muon_eta);
	treeTop->Branch("muon_phi", &muon_phi);
	
	treeMuon->Branch("muon_pT", &top_pT);
	treeMuon->Branch("muon_eta", &top_eta);
	treeMuon->Branch("muon_phi", &top_phi);
	
	treeMuonSmear->Branch("muon_pT_smear", &muon_pT_smear);
	treeMuonSmear->Branch("muon_eta_smear", &muon_eta_smear);
	treeMuonSmear->Branch("muon_phi_smear", &muon_phi_smear);
	
	treeMuonSelect->Branch("muon_pT_select", &muon_pT_select);
	treeMuonSelect->Branch("muon_eta_select", &muon_eta_select);
	treeMuonSelect->Branch("muon_phi_select", &muon_phi_select);
	
	// Initiate TRandom
	TRandom3 *smear = new TRandom3();
	
    
    // Initiating other variables
    int NEV = 10000;
    int NTop = 0;
    int NMuon = 0;
    int NTop_passing = 0;
    int NMuon_passing = 0;
    int NMuon_select = 0;
    cout << "Number of events " << NEV << std::endl;

    for (int iEvent = 0; iEvent < NEV; ++iEvent) {
        if (!pythia.next()) continue;
        for (int i = 0; i < pythia.event.size(); ++i){
            switch(abs(pythia.event[i].id())){
                case 13: // Events with the background (mumu) 
                    NMuon++; // Count the detected muons
                    if(pythia.event[i].pT() > 20 && pythia.event[i].eta() < 2.1){
                        NMuon_passing++; // count the threshhold muons
		                muon_pT = pythia.event[i].pT();
		                muon_eta = pythia.event[i].eta();
		                muon_phi = pythia.event[i].phi();
		                treeMuon->Fill();
		                // Measurement Error
		                muon_pT_smear = smear->Gaus(pythia.event[i].pT(), pythia.event[i].pT()*0.01);
		                muon_eta_smear = smear->Gaus(pythia.event[i].eta(), 0.002);
		                muon_phi_smear = smear->Gaus(pythia.event[i].phi(), 0.002);
		                treeMuonSmear->Fill();
		                // Selection and Track Isolation
		                if(muon_pT_smear > 30){
		                    double total_pion_momenta = 0;
		                    for(int j = 0; j < pythia.event.size(); ++j){ // Iterate through all events
		                        if(abs(pythia.event[i].id()) == 211){ // Find pions
		                            double dR = sqrt(pow(pythia.event[i].xProd() - pythia.event[j].xProd(), 2) +
		                                             pow(pythia.event[i].yProd() - pythia.event[j].yProd(), 2) +
		                                             pow(pythia.event[i].zProd() - pythia.event[j].zProd(), 2));
		                            if(dR < 0.3){
		                                total_pion_momenta += pythia.event[j].pT();
		                            }
		                        }
		                    }
		                    if(total_pion_momenta < 1.5){
		                        NMuon_select++;
                                muon_pT_select = muon_pT_smear;
                                muon_eta_select = muon_eta_smear;
                                muon_phi_select = muon_phi_smear;
                                treeMuonSelect->Fill();
		                    }
		                }
		            }
		            break;
                 case 6: // Events with the background (tt) 
                    NTop++; // Count the detected top quarks
                    if(pythia.event[i].pT() > 20 && pythia.event[i].eta() < 2.1){
                        NTop_passing++; // count the threshhold top quarks
		                top_pT = pythia.event[i].pT();
		                top_eta = pythia.event[i].eta();
		                top_phi = pythia.event[i].phi();
		                treeTop->Fill();
		            }
		            break;
            }
        }
    }
    // Saving to file
    TFile *fileTop = new TFile("Top.root", "RECREATE");
    treeTop->Write();
    fileTop->Close();  
    TFile *fileMuon = new TFile("Muon.root", "RECREATE");
    treeMuon->Write();
    fileMuon->Close();
    TFile *fileMuonSmear = new TFile("MuonSmear.root", "RECREATE");
    treeMuonSmear->Write();
    fileMuonSmear->Close();
    TFile *fileMuonSelect = new TFile("MuonSelect.root", "RECREATE");
    treeMuonSelect->Write();
    fileMuonSelect->Close();
    
    // Summary of results
    double efficiencySignal = double(NMuon_passing) / double(NMuon) * 100;
    double efficiencySelect = double(NMuon_select) / double(NMuon) * 100;
    cout << endl
         << "Results:\n"
         << "Total Muons: " << NMuon << endl
         << "Passing Muons: " << NMuon_passing << endl
         << "Selected Muons: " << NMuon_select << endl
         << "Signal Efficiency: " << efficiencySignal << "%" << endl
         << "Select Efficiency: " << efficiencySelect << "%" << endl
         << "Total Top: " << NTop << endl
         << "Passing Top: " << NTop_passing << endl;
    return 0;
}
