#include "MET.h"
#include <math.h>

MET::MET(){
    value = 0;
    x = 0;
    y = 0;
    phi = 0;
}

MET::MET(float X, float Y, float Value){
    value = Value;
    x = X;
    y = Y;
    phi = calculatePhi();
}

MET::~MET(){}

float MET::getValue(){
    return value;
}

float MET::getX(){
    return x;
}
float MET::getY(){
    return y;
}

float MET::calculatePhi(){
    phi = acos(x / value);
    return phi;
    
}

float MET::getPhi(){
    phi = calculatePhi();
    return phi;
}

