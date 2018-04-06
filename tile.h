#ifndef __TILE_H__
#define __TILE_H__
#include <iostream>
#include <vector>
#include <utility>
#include "Info.h"

class Tile{
  int r, c;
  bool isOccupied = true;
  char original, current;
  // Add other private members if necessary

 public:
  Tile(int r, int c, char original);  // Default constructor
  void unoccupy();
  void occupy(char symb);
  bool ifoccupied();
  Info getInfo();
};

#endif



