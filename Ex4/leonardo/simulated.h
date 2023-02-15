#ifndef SIMULATED_H
#define SIMULATED_H

#include "fourmoment.h"

class simulated : public fourMoment
{
public:
    simulated();
    void setID(int ID);
    void setParent(int ID);
    void getInfo();

private:
    int particleID;
    int parentID;

};

#endif // SIMULATED_H
