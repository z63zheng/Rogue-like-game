#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include <vector>
#include "tile.h"

class Grid {
  std::vector<std::vector<Tile *>> theGrid;  // The actual grid.
  std::vector<std::vector<Tile *>> rooms;
  //int gridSize;    // Size of the grid.
  //void clearGrid();   // Frees the grid.

 public:
  Grid();
  ~Grid();
  void checkStair(int r, int c);
  Info randTile(int random);
  bool checkOccupied(int r, int c, bool room);
  void occupy(int r, int c, char symb);
  void unoccupy(int r, int c);
  void display();
  void read(std::istream &in);
};

#endif



