#include <iostream>
#include "treasure.h"
using namespace std;

Treasure::Treasure(Grid *gp, int value, bool dragon): gp{gp}, value{value}, dragon{dragon}{}
Treasure::Treasure(Grid *gp, int value, bool dragon, int r, int c):r{r},c{c}, gp{gp}, value{value}, dragon{dragon}{
  gp->occupy(r,c,'G');
}

Treasure::~Treasure(){}

void Treasure::generate(){
  int num = rand() % 5;
  Info pos = gp->randTile(num);
  r = pos.r;
  c = pos.c;
  gp->occupy(r, c, 'G');
}

int Treasure::getValue(){
  return value;
}

bool Treasure::pickup(int row, int col){
  if (dragon) return false;
  if ((row == r) && (col == c)){
    gp->unoccupy(r,c);
    return true;
  }
  return false;
}

Info Treasure::getInfo(){
  return Info{0,0,0,0,gp,'/', " ", r, c};
}

void Treasure::slain(){
  dragon = false;
}



