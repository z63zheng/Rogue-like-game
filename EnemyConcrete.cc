#include "EnemyConcrete.h"
#include "Defend.h"

Human::Human(Grid *gp):Enemy{140, 140, 20, 20, gp, 'H', "Human"}{}
Human::~Human() {}
void Human::defend(Player &atkor, double atk, double def){
	Defend d;
	int val = d.damage(atkor,*this,atk,def);
	HP = HP - val;
	if(HP<=0){
		//Treasure *2np = new Normal{getInfo().row,getInfo().col};
		atkor.dettach(this);
		//atkor->attach(2np);
	}
}

Dwarf::Dwarf(Grid *gp):Enemy{100, 100, 20, 30, gp, 'W', "Dwarf"}{}
Dwarf::~Dwarf() {}

Elf::Elf(Grid *gp):Enemy{140, 140, 20, 30, gp, 'E', "Elf"}{}
Elf::~Elf() {}

Orcs::Orcs(Grid *gp):Enemy{180, 180, 30, 25, gp, 'O', "Orcs"}{}
Orcs::~Orcs() {}

Halfling::Halfling(Grid *gp):Enemy{100, 100, 15, 20, gp, 'L', "Halfling"}{}
Halfling::~Halfling() {}


Merchant::Merchant(Grid *gp):Enemy{30, 30, 70, 5, gp, 'M', "Merchant"}{}
Merchant::~Merchant() {}
bool Merchant::attacked = false;
bool Merchant::getattacked(){
	return attacked;
}
void Merchant::notify(Subject &whonotified){
	Info i = whonotified.getInfo();
	if(attacked==true&&i.r<=r+1&&i.r>=r-1&&i.c<=c+1&&i.c>=c-1){
		whonotified.defend(*this,this->getInfo().Atk,this->getInfo().Def);
	} else {
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

}
void Merchant::defend(Player &atkor, double atk, double def){
	Defend d;
	int val = d.damage(atkor,*this,atk,def);
	HP = HP - val;
	attacked = true;
}


Dragon::Dragon(Grid *gp,Treasure *tp):Enemy{150, 150, 20, 20, gp, 'd', "Dragon"},tp{tp}{
  int row = tp->getInfo().r;
  int col = tp->getInfo().c;
  for(int i = -1; i < 2; i ++){
    for (int j = -1; j < 2; j++){
      if ((i !=0) || (j !=0)){
        if (!gp->checkOccupied(row + i, col + j, true)){
          r = row + i;
          c = col + j;
        }
      }
    }
  }
  gp->occupy(r,c,'D');
}

Dragon::~Dragon() {}

void Dragon::defend(Player &atkor, double atk, double def){
  Defend d;
  int val = d.damage(atkor,*this,atk,def);
  HP = HP - val;
  if(HP <= 0) tp->slain();
}

void Dragon::notify(Subject &whonotified){
  Info inf = whonotified.getInfo();
  int distance = (inf.r - r) * (inf.r - r) + (inf.c - c) * (inf.c - c);
  int distance2 = (inf.r - tp->getInfo().r) * (inf.r - tp->getInfo().r) + (inf.c - tp->getInfo().c) * (inf.c - tp->getInfo().c);
  if ((distance <= 2) || (distance2 <= 2)){
    whonotified.defend(*this,getInfo().Atk,getInfo().Def);
    return;
  }
}



