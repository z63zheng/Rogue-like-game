#include "Defend.h"
#include "character2.h"
#include "PlayerConcrete.h"
#include <cmath>
using namespace std;

int Defend::damage(Elf &e,Drow &dr,double atk,double def){
	double shield = 100+def;
	double reduced = 100/shield;
	reduced = reduced * atk;
	return ceil(reduced);
}

int Defend::damage(Elf &e,Character &c,double atk,double def){
	double shield = 100+def;
	double reduced = 100/shield;
	reduced = 2 * reduced * atk;
	return ceil(reduced);
}

int Defend::damage(Orcs &o,Goblin &g,double atk,double def){
	double shield = 100+def;
	double reduced = 100/shield;
	reduced = 1.5 * reduced * atk;
	return ceil(reduced);
}

int Defend::damage(Character &c,Halfing &h,double atk,double def){
	int p = rand() % 2;
	if(p==0){
		double shield = 100+def;
		double reduced = 100/shield;
		reduced = reduced * atk;
		return ceil(reduced);
	} else {
		return 0;
	}
}

int Defend::damage(Character &c1,Character &c2,double atk,double def){
	double shield = 100+def;
	double reduced = 100/shield;
	reduced = reduced * atk;
	return ceil(reduced);
}


