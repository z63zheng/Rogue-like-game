#ifndef __DAMAGEVISITOR_H__
#define __DAMAGEVISITOR_H__

class Character;
class Drow;
class Goblin;
class Elf;
class Orcs;
class Halfing;

class DamageVisitor {
public:
	virtual int damage(Elf &e,Drow &dr,double atk,double def) = 0;
	virtual int damage(Elf &e,Character &c,double atk,double def) = 0;
	virtual int damage(Orcs &o,Goblin &g,double atk,double def) = 0;
	virtual int damage(Character &c,Halfing &h,double atk,double def) = 0;
	virtual int damage(Character &c1,Character &c2,double atk,double def) = 0;
	~DamageVisitor();
};

#endif


