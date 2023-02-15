#ifndef FOURMOMENT_H
#define FOURMOMENT_H

#include <vector>

class fourMoment
{
public:
    fourMoment();

    double transverseMomentum(char a, char b);
    double pseudoRap();
    void setMoment(double t, double x, double y, double z);


private:
    double ds(double a, double b);
    double coordMoment(char a);

    std::vector<double> moments = {0, 0, 0, 0};

};

#endif // FOURMOMENT_H
