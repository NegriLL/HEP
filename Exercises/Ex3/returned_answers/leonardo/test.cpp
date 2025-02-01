#include "MET.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){

    // Testing MET with input arguments
    MET met1;
    if(argc == 4){
        float arg1 = stof(argv[1]);
        float arg2 = stof(argv[2]);
        float arg3 = stof(argv[3]);
        met1 = MET(arg1, arg2, arg3);
    } else if(argc != 1){
        cout << "Incorrect number of arguments!" << endl;
        return 0;
    }
    
    cout << "x = " << met1.getX() << endl;
    cout << "y = " << met1.getY() << endl;
    cout << "Value = " << met1.getValue() << endl;
    cout << "phi = " << met1.getPhi() << endl;
  
}
