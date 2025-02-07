#include "RT.h"
#include <math.h>

using namespace std;

RT::RT(){
    moment = {0, 0, 0, 0};
}

RT::RT(vector<float> fourMoment){
    moment = fourMoment;
}

RT::~RT(){}

void RT::setFourMoment(vector<float> fourMoment){
    moment = fourMoment;
}

float RT::caclTransverseMomentum(){
    return sqrt(pow(moment[1],2) + pow(moment[2],2));
};

float RT::calcPseudoRapidity(){
    float theta = acos(moment[3]/calcMag());
    return -log(theta/2);
}

float RT::calcMag(){
    return sqrt(pow(moment[1],2) + pow(moment[2],2) + pow(moment[3],2));
}
