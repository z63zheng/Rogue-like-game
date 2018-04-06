#ifndef _ENEMYCONCRETE_H_
#define _ENEMYCONCRETE_H_
#include "character2.h"
#include "treasure.h"


class Human : public Enemy {
public:
	Human(Grid *gp);
	~Human();
	void defend(Player &atkor, double atk, double def) override;
};

class Dwarf : public Enemy {
public:
	Dwarf(Grid *gp);
	~Dwarf();
};

class Elf : public Enemy {
public:
	Elf(Grid *gp);
	~Elf();
};

class Orcs : public Enemy {
public:
	Orcs(Grid *gp);
	~Orcs();
};

class Halfling : public Enemy {
public:
	Halfling(Grid *gp);
	~Halfling();
};

class Merchant : public Enemy {
	static bool attacked;
public:
	bool getattacked();
	Merchant(Grid *gp);
	~Merchant();
	void notify(Subject &whonotified) override;
	void defend(Player &atkor, double atk, double def) override;
};

class Dragon : public Enemy {
  Treasure *tp;
public:
	void notify(Subject &whonotified);
	Dragon(Grid *gp,Treasure *tp);
	~Dragon();
	void defend(Player &atkor, double atk, double def);
};

#endif



