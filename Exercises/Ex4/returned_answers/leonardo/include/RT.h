#ifndef RT_H
#define RT_H

#include <vector>

using namespace std;

class RT{
 public:
  RT();
  RT(vector<float> fourMoment);
  ~RT();
  
  float caclTransverseMomentum();
  float calcPseudoRapidity();
  void setFourMoment(vector<float> fourMoment);
  
 protected:
  vector<float> moment;
  
  float calcMag();
  
};
#endif
