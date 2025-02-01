#ifndef MET_H
#define MET_H

#include <string>

class MET{
 public:
  MET();
  MET(float X, float Y, float Value);
  ~MET();
  
  float getValue();
  float getX();
  float getY();
  float getPhi();
  
 private:
  float value;
  float x;
  float y;
  float phi;
  
  float calculatePhi();
};
#endif
