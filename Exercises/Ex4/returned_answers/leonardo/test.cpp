#include "SP.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

    // Testing MET with input arguments
    SP sp;
    if(argc == 7){
        float t = stof(argv[1]);
        float p1 = stof(argv[2]);
        float p2 = stof(argv[3]);
        float p3 = stof(argv[4]);
        vector<float> fourMoment = {t, p1, p2, p3};
        sp.setFourMoment(fourMoment);
        sp.setID(argv[5]);
        sp.setParentID(argv[6]);
    } else {
        cout << "Incorrect number of arguments! Setting values to 1" << endl;
        sp.setFourMoment({1, 1, 1, 1});
        sp.setID("1");
        sp.setParentID("1");
    }
    
    cout << "Particle ID = " << sp.getID() << endl;
    cout << "Particle Parent = " << sp.getParentID() << endl;
    cout << "Transverse Momentum = " << sp.caclTransverseMomentum() << endl;
    cout << "Pseudorapidity = " << sp.calcPseudoRapidity() << endl;
  
}
