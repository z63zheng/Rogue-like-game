#ifndef __POTIONDECORATOR_H__
#define __POTIONDECORATOR_H__
#include "character2.h"
#include "Info.h"

class PotionDecorator : public Player{
protected:
	Player *component;
public:
  	virtual std::string getAction();
	virtual Info getInfo() = 0;
	int getGold() override;
	void addT(Treasure *p) override;
	void move(std::string direction, bool freeze)override;
	void attack(int row, int col, double atk, bool freeze)override;
	void defend(Character &atkor, double atk, double def)override;
	Player *use(int row, int col, Player *pptr,bool freeze) override;
	PotionDecorator(Player *oldcomponent);
	virtual ~PotionDecorator();
};

#endif



