#include "PlayerConcrete.h"
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <utility>
#include "treasure.h"
using namespace std;


Shade::Shade(Grid *gp): Player(125, 125, 25, 25, gp, "Shade",0) {
  action = "Player character has spawned.";
}
Shade::Shade(Grid *gp, int HP, int gold): Player(HP, 125, 25, 25, gp, "Shade",gold){
  action = "Player character enters a new floor.";
}
Shade::~Shade() {};
void Shade::attack(int row, int col, double atk,bool freeze) {
 Observer *target = nullptr;
 for(unsigned int i = 0; i < observers.size(); ++i) {
  Info info = observers[i]->getInfo();
  if((info.r == row) && (info.c == col)) {
    target = observers[i];
    break;
  }
 }
 if(target != nullptr) {
  //cout << "Enemy is being attacked" << endl;
  double def = (target->getInfo()).Def;
  int oldenemyHP = (target->getInfo()).HP;
  target->defend(*this, atk, def);
  int enemyHP = (target->getInfo()).HP;
  stringstream ss;
  ss << "PC deals " << oldenemyHP - enemyHP << " damage to "<< (target->getInfo()).sym << " (";
  if (enemyHP > 0) ss  << enemyHP << " HP).";
  else ss << "0 HP).";
  action = ss.str();
  if(enemyHP <= 0) {
  
   gp->unoccupy(row, col);
   if (((target->getInfo()).sym == 'M') || ((target->getInfo()).sym == 'H')) {
     Treasure *tp = new Treasure(gp,4,false,row,col);
     addT(tp);
   }
   this->dettach(target);
   delete target;
   //cout << "Enemy Dead" << endl;
  }
  //cout << "EnemyHP = " << enemyHP << endl;
 } else {
 }
 if (!freeze) this->notifyObservers();
}

void Shade::defend(Character &atkor, double atk, double def) {
 int miss = (rand() % 2);
 if(miss == 1) action = action + " " + atkor.getInfo().sym + " attack missed.";
 else { 
  Defend x;
  int damage = x.damage(atkor, *this, atk, def);
  this->HP -= damage;
  stringstream ss;
  ss << " " << atkor.getInfo().sym << " deals " << damage << " to PC.";
  action += ss.str();
  //cout << "damage:"<< damage << endl;
 }
}

Drow::Drow(Grid *gp): Player(150, 150, 25, 15, gp, "Drow",0) {
  action = "Player character has spawned.";
}
Drow::Drow(Grid *gp, int HP, int gold): Player(HP, 150, 25, 15, gp, "Drow",gold){
  action = "Player character enters a new floor.";
}
Drow::~Drow() {};
void Drow::attack(int row, int col, double atk,bool freeze) {
 Observer *target = nullptr;
 for(unsigned int i = 0; i < observers.size(); ++i) {
  Info info = observers[i]->getInfo();
  if((info.r == row) && (info.c == col)) {
    target = observers[i];
  }
 }
 if(target != nullptr) {
  double def = (target->getInfo()).Def;
  int oldenemyHP = (target->getInfo()).HP;
  target->defend(*this, atk, def);
  int enemyHP = (target->getInfo()).HP;
  stringstream ss;
  ss << "PC deals " << oldenemyHP - enemyHP << " damage to "<< (target->getInfo()).sym << " (";
  if (enemyHP > 0) ss  << enemyHP << " HP).";
  else ss << "0 HP).";
  action = ss.str();
  if(enemyHP <= 0) {
   gp->unoccupy(row, col);
   if (((target->getInfo()).sym == 'M') || ((target->getInfo()).sym == 'H')) {
     Treasure *tp = new Treasure(gp,4,false,row,col);
     addT(tp);
   }
   delete target;
   this->dettach(target);
  }
 } else {
 }

 if (!freeze) this->notifyObservers();
}

void Drow::defend(Character &atkor, double atk, double def) {
 int miss = (rand() % 2);
 if(miss == 1) {
   action = action + " " + atkor.getInfo().sym + " attack missed.";
 } else { 
  Defend x;
  int damage = x.damage(atkor, *this, atk, def);
  this->HP -= damage;
  stringstream ss;
  ss << " " << atkor.getInfo().sym << " deals " << damage << " to PC.";
  action += ss.str();
 }
}

Goblin::Goblin(Grid *gp): Player(110, 110, 15, 20, gp, "Goblin",0) {
  action = "Player character has spawned.";
}
Goblin::Goblin(Grid *gp, int HP, int gold): Player(HP, 110, 15, 20, gp, "Goblin",gold) {
  action = "Player character enters a new floor.";
}
Goblin::~Goblin() {};
void Goblin::attack(int row, int col, double atk, bool freeze) {
 Observer *target = nullptr;
 for(unsigned int i = 0; i < observers.size(); ++i) {
  Info info = observers[i]->getInfo();
  if((info.r == row) && (info.c == col)) {
    target = observers[i];
  }
 }
 if(target != nullptr) {
  double def = (target->getInfo()).Def;
  int oldenemyHP = (target->getInfo()).HP;
  target->defend(*this, atk, def);
  int enemyHP = (target->getInfo()).HP;
  stringstream ss;
  ss << "PC deals " << oldenemyHP - enemyHP << " damage to "<< (target->getInfo()).sym << " (";
  if (enemyHP > 0) ss  << enemyHP << " HP).";
  else ss << "0 HP).";
  action = ss.str();
  if(enemyHP <= 0) {
   gold += 5;
   gp->unoccupy(row, col);
   if (((target->getInfo()).sym == 'M') || ((target->getInfo()).sym == 'H')) {
     Treasure *tp = new Treasure(gp,4,false,row,col);
     addT(tp);
   }
   delete target;
   this->dettach(target);
  }
 } else {
 }
 if (!freeze) this->notifyObservers();
}

void Goblin::defend(Character &atkor, double atk, double def) {
 int miss = (rand() % 2);
 if(miss == 1) {
   action = action + " " + atkor.getInfo().sym + " attack missed.";
 } else { 
  Defend x;
  int damage = x.damage(atkor, *this, atk, def);
  this->HP -= damage;
  stringstream ss;
  ss << " " << atkor.getInfo().sym << " deals " << damage << " to PC.";
  action += ss.str();
 }
}

Troll::Troll(Grid *gp): Player(120, 120, 25, 15, gp, "Troll",0) {
  action = "Player character has spawned.";
}
Troll::Troll(Grid *gp,int HP, int gold): Player(HP, 120, 25, 15, gp, "Troll",gold) {
  action = "Player character enters a new floor.";
}
Troll::~Troll() {};
void Troll::move(string direction, bool freeze){
    int newr = r;
  int newc = c;
  action = "PC moves ";
  if (direction == "no") {
    newr -= 1;
    action += "North";
  }
  if (direction == "so") {
    newr += 1;
    action += "South";
  }
  if (direction == "ea") {
    newc += 1;
    action += "East";
  }
  if (direction == "we") {
    newc -= 1;
    action += "West";
  }
  if (direction == "ne"){
    newr -= 1;
    newc += 1;
    action += "Northeast";
  }
  if (direction == "nw"){
    newr -= 1;
    newc -= 1;
    action += "Northwest";
  }
  if (direction == "se"){
    newr += 1;
    newc += 1;
    action += "Southeast";
  }
  if (direction == "sw"){
    newr += 1;
    newc -= 1;
    action += "Southwest";
  }

  gp->checkStair(newr, newc);
  if (gp->checkOccupied(newr, newc, false)){
    action = "invalid position";
    return;
  }
  gp->unoccupy(r,c);
  r = newr;
  c = newc;
  gp->occupy(r,c,sym);
  this->HP += 5;
  if((this->HP) > (this->HPmax)) (this->HP) = (this->HPmax);
  if (freeze) return;
  notifyObservers();
}

void Troll::attack(int row, int col, double atk,bool freeze) {
 Observer *target = nullptr;
 for(unsigned int i = 0; i < observers.size(); ++i) {
  Info info = observers[i]->getInfo();
  if((info.r == row) && (info.c == col)) {
    target = observers[i];
  }
 }
 if(target != nullptr) {
  double def = (target->getInfo()).Def;
  int oldenemyHP = (target->getInfo()).HP;
  target->defend(*this, atk, def);
  int enemyHP = (target->getInfo()).HP;
  stringstream ss;
  ss << "PC deals " << oldenemyHP - enemyHP << " damage to "<< (target->getInfo()).sym << " (";
  if (enemyHP > 0) ss  << enemyHP << " HP).";
  else ss << "0 HP).";
  action = ss.str();
  if(enemyHP <= 0) {
   gp->unoccupy(row, col);
   if (((target->getInfo()).sym == 'M') || ((target->getInfo()).sym == 'H')) {
     Treasure *tp = new Treasure(gp,4,false,row,col);
     addT(tp);
   }
   delete target;
   this->dettach(target);
  }
 } else {
 }
 this->HP += 5;
 if((this->HP) > (this->HPmax)) (this->HP) = (this->HPmax);
 if (!freeze) this->notifyObservers();
}

void Troll::defend(Character &atkor, double atk, double def) {
 int miss = (rand() % 2);
 if(miss == 1) {
   action = action + " " + atkor.getInfo().sym + " attack missed.";
 } else { 
  Defend x;
  int damage = x.damage(atkor, *this, atk, def);
  this->HP -= damage;
  stringstream ss;
  ss << " " << atkor.getInfo().sym << " deals " << damage << " to PC.";
  action += ss.str();
 }
}

Vampire::Vampire(Grid *gp): Player(50, 0, 25, 25, gp, "Vampire",0) {
  action = "Player character has spawned.";
}
Vampire::Vampire(Grid *gp, int HP, int gold): Player(HP, 0, 25, 25, gp, "Vampire",gold){
  action = "Player character enters a new floor.";
}
Vampire::~Vampire() {};
void Vampire::attack(int row, int col, double atk,bool freeze) {
 Observer *target = nullptr;
 for(unsigned int i = 0; i < observers.size(); ++i) {
  Info info = observers[i]->getInfo();
  if((info.r == row) && (info.c == col)) {
    target = observers[i];
  }
 }
 if(target != nullptr) {
  //cout << "Enemy being attcked" << endl;
  double def = (target->getInfo()).Def;
  int oldHP = (target->getInfo()).HP;
  string name = (target->getInfo()).name;
  int oldenemyHP = (target->getInfo()).HP;
  target->defend(*this, atk, def);
  int enemyHP = (target->getInfo()).HP;
  stringstream ss;
  ss << "PC deals " << oldenemyHP - enemyHP << " damage to "<< (target->getInfo()).sym << " (";
  if (enemyHP > 0) ss  << enemyHP << " HP).";
  else ss << "0 HP).";
  action = ss.str();
  if(enemyHP <= 0) {
   if(name == "Dwarf") {
    this->HP -= 5;
   } else {
    this->HP += 5;
   }
   gp->unoccupy(row, col);
   if (((target->getInfo()).sym == 'M') || ((target->getInfo()).sym == 'H')) {
     Treasure *tp = new Treasure(gp,4,false,row,col);
     addT(tp);
   }
   delete target;
   this->dettach(target);
//   cout << "Enemy Dead" << endl;
  } else if(enemyHP != oldHP) {
   if((target->getInfo()).name == "Dwarf") {
    this->HP -= 5;
   } else {
    this->HP += 5;
   }
  }
//  cout << "EnemyHP = " << enemyHP << endl;
 } else {
 }
 if (!freeze) this->notifyObservers();
}

void Vampire::defend(Character &atkor, double atk, double def) {
 int miss = (rand() % 2);
 if(miss == 1) {
   action = action + " " + atkor.getInfo().sym + " attack missed.";
 } else { 
  Defend x;
  int damage = x.damage(atkor, *this, atk, def);
  this->HP -= damage;
  stringstream ss;
  ss << " " << atkor.getInfo().sym << " deals " << damage << " to PC.";
  action += ss.str();
 }
}


