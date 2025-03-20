#include <iostream>
#include "Pythia8/Pythia.h"

using namespace Pythia8;
using namespace std;

int main() {
    
    Pythia pythia;
    pythia.readString("HiggsSM:all = on");
    pythia.readString("Higgs:runningLoopMass = on");
    pythia.readString("Higgs:cubicWidth = on");
    pythia.readString("Beams:eCM = 8000.");
    pythia.readString("25:m0 = 125");
    pythia.init();
    
    pythia.next();
    
    cout << endl;
    cout << "Higgs Mass\tDecay Width" << endl;
    cout << 125 << "\t\t\t" << pythia.particleData.mWidth(25)  << endl; 
    return 0;
}
