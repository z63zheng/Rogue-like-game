#ifndef __TREASURE_H__
#define __TREASURE_H__
#include <iostream>
#include "grid.h"
#include "Info.h"

class Treasure{
  int r,c;
  Grid *gp;
  int value;
  bool dragon;
 public:
  void slain();
  int getValue();
  Treasure(Grid *gp, int value, bool dragon);
  Treasure(Grid *gp, int value, bool dragon, int r, int c);
  ~Treasure();
  void generate();
  bool pickup(int row, int col);
  Info getInfo();
};

#endif


