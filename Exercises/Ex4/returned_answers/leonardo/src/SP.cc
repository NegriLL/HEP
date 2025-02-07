#include "SP.h"

void SP::setID(string id){
    ID = id;
}

void SP::setParentID(string pid){
    parentID = pid;
}
string SP::getID(){
    return ID;
}

string SP::getParentID(){
    return parentID;
}
