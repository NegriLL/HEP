#include "Pythia8/Pythia.h"
#include "TFile.h"
#include "TTree.h"
#include "TRandom3.h"
#include "TLorentzVector.h"
#include "math.h"
#include <vector>
using namespace Pythia8;
using namespace std;

// Calculates the distance between two events in pythia
double distance(Event event, int i, int j){
    double dEta = event[i].eta() - event[j].eta();
    double dPhi = fabs(event[i].phi() - event[j].eta());
    if(dPhi > M_PI) dPhi = 2 * M_PI - dPhi;
    return sqrt(dEta*dEta + dPhi*dPhi);
}

// Returns the total charged pion momentum within a bondary dR
double pionMomenta(Event event, int index, double dR){
    double totalPionMomentum = 0;
    for(int i = 0; i < event.size(); i++){
        if(abs(event[i].id()) == 211 && distance(event, index, i) < dR && event[i].isFinal()){
            totalPionMomentum += event[i].pT();
        }
    }
    return totalPionMomentum;
}

int main(int argc, char** argv) { 

    int NEV = atoi(argv[1]);
    
    // Starting pythia
    Pythia pythia;
    TFile *file = new TFile(argv[2], "RECREATE");
    TTree *tree = new TTree(argv[2], "Signal Events Passing the Trigger");
    if(strcmp(argv[2], "signal") == 0){
        pythia.readString("WeakSingleBoson:ffbar2gmZ = on");
    } else if (strcmp(argv[2], "noise") == 0){
        pythia.readString("Top:gg2ttbar = on");
        pythia.readString("Top:qqbar2ttbar = on");
    } else {
        cout << "Invalid Command" << endl;
    }
    pythia.init();
    
    // Creating branches
    double muonPt;
    double muonTheta;
    double muonPhi;
    double muonE;
    double muonEta;
    bool signal = false; // Checking whether the muon is a signal or not
    bool select = false; // Checks the second threshold
    double pionP = 0; // total charged pion momenta within distance threshhold
    int eventNumber = 0;
	tree->Branch("muonPt", &muonPt);
	tree->Branch("muonTheta", &muonTheta);
	tree->Branch("muonPhi", &muonPhi);
	tree->Branch("muonEta", &muonEta);
	tree->Branch("muonE", &muonE);
	tree->Branch("signal", &signal);
	tree->Branch("select", &select);
	tree->Branch("pionP",  &pionP);
	tree->Branch("eventNumber", &eventNumber);
	
	// Cut Offs
	double pionMaxdR = 0.3;

    // Initiating other variables
    int NSignal = 0;

    for (int iEvent = 0; iEvent < NEV; ++iEvent) {
        if (!pythia.next()) continue;
        for (int i = 0; i < pythia.event.size(); ++i){
            if(abs(pythia.event[i].id()) == 13 && pythia.event[i].pT() > 20
                                               && abs(pythia.event[i].eta()) < 2.1
                                               && pythia.event[i].isFinal()){
                // Setting 4 Moment
                muonPt = pythia.event[i].pT();
                muonTheta = pythia.event[i].theta();
                muonPhi = pythia.event[i].phi() ;
                muonE = pythia.event[i].eT();
                muonEta = pythia.event[i].eta();
                // Counting Signal
                NSignal++;
                // Setting isolation
                pionP = pionMomenta(pythia.event, i, pionMaxdR);
                // Filling Tree
                eventNumber = iEvent;
                tree->Fill();
            }
        }
    }
    // Saving to file
    tree->Write();
    file->Close();
    // Summary of results
    double efficiency = double(NSignal) / double(NEV) * 100;
    cout << endl
         << "Results Summary:" << endl
         << "Number of events " << NEV << endl
         << "Signal Muons: " << NSignal << endl
         << "Signal Efficiency: " << efficiency << "%" << endl;
    cout << setprecision(10) << fixed;
    cout << "Weighted Cross Section: " << pythia.info.sigmaGen() * 1e9/double(NEV) << " fb" << endl;
    return 0;

}
