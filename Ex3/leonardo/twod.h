#ifndef TWOD_H
#define TWOD_H
#include "cmath"


class twoD
{
public:
    twoD(double i, double j);

    double x = 0;
    double y = 0;

    struct errorMatrix{
        double sigX2, sigY2, covXY;
    };
    errorMatrix error;

    double distance();
    void setErrorMatrix(double sx, double sy, double sxy);

    double getSignificance();
    double getX();
    double getY();
    double getError();
    double getMatrix(int i,int j);

};

#endif // TWOD_H
