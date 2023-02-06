#include <iostream>
#include "twod.h"

using namespace std;

int main()
{
    int x = 1;
    int y = 2;
    
    float sxx = 0.1;
    float syy = 0.2;
    float sxy = 0.3;
    
    twoD myValues(x, y);
    cout << "Value X: " <<  myValues.getX() << endl;
    cout << "Value Y: " <<  myValues.getY() << endl;
    cout << "Distance: " << myValues.distance() << endl;
    cout << endl;
    
    myValues.setErrorMatrix(sxx, syy, sxy);
    
    cout << "Errors: " << myValues.getMatrix(0,0) << " " << myValues.getMatrix(0,1) << endl;
    cout << "        " << myValues.getMatrix(1,0) << " " << myValues.getMatrix(1,1);
    
    cout << endl;
    
    cout << "The error is: " << myValues.getError() << endl;
    cout << "The significance is: " << myValues.getSignificance() << endl;
    
    return 0;

}
