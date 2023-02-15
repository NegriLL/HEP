#include "simulated.h"
#include <iostream>

using namespace std;

simulated::simulated()
{

}

void simulated::setID(int ID){
    particleID = ID;
}

void simulated::setParent(int ID){
    parentID = ID;
}

void simulated::getInfo(){
    cout << "The particle ID is " << particleID << endl;
    cout << "The parent ID is " << parentID << endl;
}
