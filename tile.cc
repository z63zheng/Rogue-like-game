#include <iostream>
#include <utility>
#include "tile.h"

using namespace std;
Tile::Tile(int r, int c, char original): r{r}, c{c}, original{original}, current{original}{
  if ((original == '.') || (original == '+') || (original == '#')) isOccupied = false;
}

void Tile::unoccupy(){
  if (current == 'G') original = '.';
  current = original;
  isOccupied = false;
}

bool Tile::ifoccupied(){
  if (current == 'G') return false;
  return isOccupied;
}

void Tile::occupy(char symb){
  if (ifoccupied()) return;
  isOccupied = true;
  if (current == 'G'){
    original = current;
  }
  current = symb;
}

Info Tile::getInfo(){
  Info inf = {0,0,0,0,nullptr,current, "", r,c};
  return inf;
}



