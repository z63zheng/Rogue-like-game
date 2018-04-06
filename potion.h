#ifndef __POTION_H__
#define __POTION_H__
#include <iostream>
#include <string>
#include "grid.h"
#include "observer.h"
#include "Info.h"
#include "subject.h"

class Potion: public Observer{
  int r, c;
  Grid *gp;
  
  std::string name;
  std::string action;
 public:
  void defend(Player &atkor, double atk, double def){}
  Info getInfo();
  //std::string getAction();
  static int used[6];
  Potion(Grid *gp, std::string name);
  ~Potion();
  void generate();
  void notify(Subject &whoNotified);
  void use();
};

#endif



