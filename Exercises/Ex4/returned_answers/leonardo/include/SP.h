#ifndef SP_H
#define SP_H

#include "RT.h"
#include <string>

class SP : public RT {
 public:
  void setID(string id);
  void setParentID(string pid);
  string getID();
  string getParentID();
  
 private:
  string ID;
  string parentID;
  
};
#endif
