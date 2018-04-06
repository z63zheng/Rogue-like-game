#ifndef __DEFEND_H__
#define __DEFEND_H__
#include "DamageVisitor.h"

class Character;
class Drow;
class Goblin;
class Elf;
class Orcs;
class Halfing;

class Defend : DamageVisitor {
public:
	virtual int damage(Elf &e,Drow &dr,double atk,double def) override;
	virtual int damage(Elf &e,Character &c,double atk,double def) override;
	virtual int damage(Orcs &o,Goblin &g,double atk,double def) override;
	virtual int damage(Character &c,Halfing &h,double atk,double def) override;
	virtual int damage(Character &c1,Character &c2,double atk,double def) override;
};

#endif


