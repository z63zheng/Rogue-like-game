#ifndef _PLAYERCONCRETE_H_
#define _PLAYERCONCRETE_H_
#include "character2.h"
#include "subject.h"
#include "observer.h"
#include <string.h>
#include <cstdlib>
#include <utility>
#include <vector>

class Shade: public Player{
 public:
  Shade(Grid *gp);
  Shade(Grid *gp, int HP, int gold);
  ~Shade();
  void attack(int row, int col, double atk,bool freeze);
  void defend(Character &atkor, double atk, double def);
};

class Drow: public Player{
 public:
  Drow(Grid *gp);
  Drow(Grid *gp, int HP, int gold);
  ~Drow();
  void attack(int row, int col, double atki,bool freeze);
  void defend(Character &atkor, double atk, double def);
};

class Goblin: public Player{
 public:
  Goblin(Grid *gp);
  Goblin(Grid *gp, int HP, int gold);
  ~Goblin();
  void attack(int row, int col, double atk,bool freeze);
  void defend(Character &atkor, double atk, double def);
};

class Troll: public Player{
 public:
  Troll(Grid *gp);
  Troll(Grid *gp, int HP, int gold);
  ~Troll();
  void move(std::string direction, bool freeze);
  void attack(int row, int col, double atk,bool freeze);
  void defend(Character &atkor, double atk, double def);
};

class Vampire: public Player{
 public:
  Vampire(Grid *gp);
  Vampire(Grid *gp, int HP, int gold);
  ~Vampire();
  void attack(int row, int col, double atk,bool freeze);
  void defend(Character &atkor, double atk, double def);
};

#endif



