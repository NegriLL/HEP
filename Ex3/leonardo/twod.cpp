#include "twod.h"
#include "cmath"

twoD::twoD(double i, double j){

    x = i;
    y = j;

    // Initializing the matrix
    error.sigX2 = 0;
    error.sigY2 = 0;
    error.covXY = 0;

}

double twoD::getX(){
    return x;
}

double twoD::getY(){
    return y;
}

double twoD::distance(){
    return sqrt(pow(x,2) + pow(y,2));
}

double twoD::getMatrix(int i,int j){
    switch(i + j){
        case 0:
            return error.sigX2;
        case 1:
            return error.covXY;
        case 2:
            return error.sigY2;
    }
    return 0;
}

double twoD::getError(){
    double pt1 = error.sigX2 * pow( x / distance(),2);
    double pt2 = error.sigY2 * pow( y / distance(),2);
    double pt3 = pow(error.covXY, 2) * ( x * y ) / pow(distance(),2);

    return sqrt(pt1 + pt2 + pt3);
}

double twoD::getSignificance(){
    return distance() / getError();
}

void twoD::setErrorMatrix(double sx, double sy, double sxy){
    error.sigX2 = sx;
    error.sigY2 = sy;
    error.covXY = sxy;

}
