#ifndef __CHARACTER2_H__
#define __CHARACTER2_H__
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include "grid.h"
#include "subject.h"
#include "observer.h"
#include "Info.h"
#include "Defend.h"
#include "treasure.h"
//#include "PotionDecorator.h"
//#include "PotionConcrete.h"
//struct Info;


class Character{
 protected:
  int HP;
  int HPmax;
  double Atk;
  double Def;
  
  int r, c;
  Grid *gp;
  char sym;
  const std::string name;
  // Add other private members if necessary
  
public:
//  virtual std::string getAction();
  Character(int HP, int HPmax, double Atk, double Def, Grid *gp, char sym, std::string name);
  virtual Info getInfo()=0;
  void generate(bool pc);
  
};

class Player: public Character, public Subject{
  std::vector<Treasure *> Tlist;
protected:
  int gold;
public:
  virtual int getGold();
  virtual void addT(Treasure *p);
  Player(int HP, int HPmax, double Atk, double Def, Grid *gp, std::string name);
  Player(int HP, int HPmax, double Atk, double Def, Grid *gp, std::string name, int gold);
  ~Player();
  virtual void move(std::string direction, bool freeze);
  virtual Player *use(int row, int col, Player *pptr, bool freeze);
  virtual void attack(int row, int col, double atk, bool freeze)=0;
  virtual void defend(Character &atkor, double atk, double def)=0;
  Info getInfo() override;
};

class Enemy: public Character, public Observer{
public:
  void use(){}
  ~Enemy(){}
  Enemy(int HP, int HPmax, double Atk, double Def, Grid *gp, char sym, std::string name);
  void notify(Subject &whoNotified);
  virtual void defend(Player &atkor, double atk, double def);
  Info getInfo() override;
};


#endif




