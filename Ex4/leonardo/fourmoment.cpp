#include "fourmoment.h"
#include "cmath"

fourMoment::fourMoment()
{

}

double fourMoment::coordMoment(char a){
    switch (a) {
        case 't':
            return moments[0];
    }
    switch (a) {
        case 'x':
            return moments[1];
    }
    switch (a) {
        case 'y':
            return moments[2];
    }
    switch (a) {
        case 'z':
            return moments[3];
    }
    return 0;
}

double fourMoment::ds(double a, double b){
    return sqrt(a*a + b*b);
}

double fourMoment::transverseMomentum(char a, char b){
    double k = coordMoment(a);
    double j = coordMoment(b);
    return ds(k ,j);
}

double fourMoment::pseudoRap(){
    double cosTheta = moments[3] / sqrt(moments[0]*moments[0] +
                                        moments[1]*moments[1] +
                                        moments[2]*moments[2]);
    double theta = acos(cosTheta);
    return -log(tan(theta/2));

}

void fourMoment::setMoment(double t, double x, double y, double z){
    moments[0] = t;
    moments[1] = x;
    moments[2] = y;
    moments[3] = z;
}
