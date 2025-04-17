#include "Pythia8/Pythia.h"
using namespace Pythia8;

int main() {

    Pythia pythia;
    pythia.readString("Beams:eCM = 13600.");
    pythia.readString("Top:all = on");
    pythia.init();

    int NEV = 1000;
    int NTop = 0;
    int NMuon = 0;
    int NTop_passing = 0;
    int NMuon_passing = 0;
    std::cout << "Number of events " << NEV << std::endl;

    for (int iEvent = 0; iEvent < NEV; ++iEvent) {
        if (!pythia.next()) continue;
        // Events with the signal (mumu)
        for (int i = 0; i < pythia.event.size(); ++i){
            if (abs(pythia.event[i].id()) == 13){
                NMuon++; // Count the detected muons
                if(pythia.event[i].pT() > 20 && pythia.event[i].eta() < 2.1){
                    NMuon_passing++; // count the threshhold muons
	                std::cout << "Muon pt,eta,phi " 
                              << pythia.event[i].pT() << " "
                              << pythia.event[i].eta() << " "
		                      << pythia.event[i].phi() << std::endl;
		        }
            }
        // Events with the background (tt)  
            if (abs(pythia.event[i].id()) == 6){
                NTop++; // Count the detected top quarks
                if(pythia.event[i].pT() > 20 && pythia.event[i].eta() < 2.1){
                    NTop_passing++; // count the threshhold top quarks
	                std::cout << "Top pt,eta,phi " 
                              << pythia.event[i].pT() << " " 
                              << pythia.event[i].eta() << " "
		                      << pythia.event[i].phi() << std::endl;
		        }
            }
        }
    }
    double efficiency = double(NMuon_passing) / double(NMuon) * 100;
    
    cout << endl
         << "Results:\n"
         << "Total Muons: " << NMuon << endl
         << "Passing Muons: " << NMuon_passing << endl
         << "Signal Efficiency: " << efficiency << "%" << endl
         << "Total Top: " << NTop << endl
         << "Passing Top: " << NTop_passing << endl;
    return 0;
}
