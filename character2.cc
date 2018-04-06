#include <iostream>
#include <utility>
#include "character2.h"
#include "Info.h"
#include "PotionDecorator.h"
#include "PotionConcrete.h"

using namespace std;

//struct Info;
Character::Character(int HP, int HPmax, double Atk, double Def, Grid *gp, char sym, std::string name): 
HP{HP}, HPmax{HPmax}, Atk{Atk}, Def{Def}, gp{gp}, sym{sym}, name{name}{}

void Character::generate(bool pc){
  int random = rand() % 5;
  Info pos = gp->randTile(random);
  r = pos.r;
  c = pos.c;
  gp->occupy(r, c, sym);
  if (!pc) return;
  int random2 = rand() % 5;
  while(random2 == random) random2 = rand() % 5;
  Info pos2 = gp->randTile(random2);
  int newr = pos2.r;
  int newc = pos2.c;
  gp->occupy(newr, newc, '/');
}

Player::Player(int HP, int HPmax, double Atk, double Def, Grid *gp, std::string name): Character(HP, HPmax, Atk, Def, gp, '@', name) {
  gold = 0;
}
Player::Player(int HP, int HPmax, double Atk, double Def, Grid *gp, std::string name, int gold): Character(HP, HPmax, Atk, Def, gp, '@', name), gold{gold} {
  cout << gold << endl;
}
Player::~Player() {
  for(unsigned int i = 0; i < Tlist.size(); ++i) {
   delete Tlist[i];
  }
}
int Player::getGold() {return gold;}
void Player::addT(Treasure *p) {Tlist.emplace_back(p);}
void Player::move(string direction, bool freeze){
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
  for (unsigned int i = 0; i < Tlist.size(); i++){
    if(Tlist[i]->pickup(newr, newc)){
      gold += Tlist[i]->getValue();
      //if (name == "shade") gold += 0.5 * Tlist[i]->getValue();
      delete Tlist[i];
      Tlist.erase(Tlist.begin() + i);
    }
  }
  if (gp->checkOccupied(newr, newc, false)){
    cout << "invalid position" << endl;
    return;
  }
  gp->unoccupy(r,c);
  r = newr;
  c = newc;
  gp->occupy(r,c,sym);
  if (freeze) return;
  notifyObservers();
}

Player *Player::use(int row, int col, Player *pptr,bool freeze){
 Observer *target;
 for(unsigned int i=0; i < observers.size(); ++i){
	target = observers.at(i);
	if(target->getInfo().r == row && target->getInfo().c == col)break;
 }
 target->use(); 
 string pname = target->getInfo().name;
 this->dettach(target);
 action = "PC uses " + pname;
 Player *newp = this;
 if(pname == "RH"){
	newp = new RH{pptr};

 }
 if(pname == "BA"){
        newp = new BA{pptr};
        
 }
 if(pname == "BD"){
        newp = new BD{pptr};
        
 }
 if(pname == "PH"){
        newp = new PH{pptr};
       
 }
 if(pname == "WA"){
        newp = new WA{pptr};
        
 }
 if(pname == "WD"){
        newp = new WD{pptr};
        
 }
 newp->action = "PC uses " + pname;
 if(name == "Troll"){
	if(HP+5>HPmax)HP = HPmax;
	else HP += 5;
 }
 if ((target->getInfo().r != row) || (target->getInfo().c != col)){
   action = "no potion here";
 } else if (!freeze) notifyObservers();
 delete target;
 return newp;
}

Info Player::getInfo(){
  struct Info info {HP, HPmax, Atk, Def, gp, sym, name, r, c};
  return info;
}


Enemy::Enemy(int HP, int HPmax, double Atk, double Def, Grid *gp, char sym, std::string name): Character(HP, HPmax, Atk, Def, gp, sym, name) {}


void Enemy::notify(Subject &whonotified){
//  cout<<"hi"<<endl;
  Info inf = whonotified.getInfo();
  int distance = (inf.r - r) * (inf.r - r) + (inf.c - c) * (inf.c - c);
  if (distance <= 2){
    //cout << "Enemy attacked Player" << endl;
    whonotified.defend(*this,getInfo().Atk,inf.Def);
    return;
  }
  
  int mover = rand() % 3 - 1;
  int movec = rand() % 3 - 1;
  while(gp->checkOccupied(r + mover, c + movec, true)){
    mover = rand() % 3 - 1;
    movec = rand() % 3 - 1;
  }
  gp->unoccupy(r,c);
  r += mover;
  c += movec;
  gp->occupy(r,c,sym);
}

void Enemy::defend(Player &atkor, double atk, double def){
  Defend d;
  int val = d.damage(atkor,*this,atk,def);
  HP = HP - val;
}

Info Enemy::getInfo(){
  struct Info info {HP, HPmax, Atk, Def, gp, sym, name, r, c};
  return info;
}




