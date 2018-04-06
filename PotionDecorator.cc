#include "character2.h"
#include "PotionDecorator.h"
using namespace std;


string PotionDecorator::getAction(){
 return component->getAction();
}


PotionDecorator::PotionDecorator(Player *oldcomponent):
	Player{0, oldcomponent->getInfo().HPmax, 0, 0, oldcomponent->getInfo().gp, oldcomponent->getInfo().name}, component{oldcomponent}{
	r = oldcomponent->getInfo().r;
	c = oldcomponent->getInfo().c;
}

int PotionDecorator::getGold() {return component->getGold();}

void PotionDecorator::addT(Treasure *p) {component->addT(p);}

void PotionDecorator::move(string direction, bool freeze){
	component->move(direction,freeze);
	return;
}

void PotionDecorator::attack(int row, int col, double atk, bool freeze){
	component->attack(row, col, atk, freeze);
	return;
}

void PotionDecorator::defend(Character &atkor, double atk, double def){
	component->defend(atkor,atk,def);
	return;
}

Player *PotionDecorator::use(int row, int col, Player *pptr,bool freeze) {
	return component->use(row, col, pptr,freeze);
}

PotionDecorator::~PotionDecorator() { delete component; }




