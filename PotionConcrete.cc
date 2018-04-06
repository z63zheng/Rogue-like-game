#include "PotionDecorator.h"
#include "PotionConcrete.h"
#include "character2.h"
#include "Info.h"
using namespace std;

RH::RH(Player *component):PotionDecorator{component}{}
Info RH::getInfo(){
	if(name == "Drow"){
		if(component->getInfo().HP+15>component->getInfo().HPmax) return Info{HPmax, HPmax ,component->getInfo().Atk ,component->getInfo().Def, gp, sym, name, component->getInfo().r, component->getInfo().c};
        	return Info{component->getInfo().HP+15, HPmax ,component->getInfo().Atk ,component->getInfo().Def, gp, sym, name, component->getInfo().r, component->getInfo().c};
	} else {
		if(component->getInfo().HP+10>component->getInfo().HPmax) return Info{HPmax, HPmax ,component->getInfo().Atk ,component->getInfo().Def, gp, sym, name, component->getInfo().r, component->getInfo().c};
        	return Info{component->getInfo().HP+10, HPmax ,component->getInfo().Atk ,component->getInfo().Def, gp, sym, name, component->getInfo().r, component->getInfo().c};
	}
}

BA::BA(Player *component):PotionDecorator{component}{}
Info BA::getInfo(){
	if(name == "Drow") return Info{component->getInfo().HP, HPmax, component->getInfo().Atk+7.5, component->getInfo().Def, gp, sym, name, component->getInfo().r, component->getInfo().c};
	else return Info{component->getInfo().HP, HPmax, component->getInfo().Atk+5, component->getInfo().Def, gp, sym, name, component->getInfo().r, component->getInfo().c};
}

BD::BD(Player *component):PotionDecorator{component}{}
Info BD::getInfo(){
	if(name == "Drow") return Info{component->getInfo().HP,HPmax, component->getInfo().Atk, component->getInfo().Def+7.5, gp, sym, name, component->getInfo().r, component->getInfo().c};
	else return Info{component->getInfo().HP,HPmax, component->getInfo().Atk, component->getInfo().Def+5, gp, sym, name, component->getInfo().r, component->getInfo().c};
}

PH::PH(Player *component):PotionDecorator{component}{}
Info PH::getInfo(){
	if(name == "Drow"){
		if(component->getInfo().HP<=15) return Info{0, HPmax ,component->getInfo().Atk ,component->getInfo().Def, gp, sym, name, component->getInfo().r, component->getInfo().c};
        	return Info{component->getInfo().HP-15, HPmax, component->getInfo().Atk,component->getInfo().Def,gp, sym, name,component->getInfo().r,component->getInfo().c};
	} else {
		if(component->getInfo().HP<=10) return Info{0, HPmax ,component->getInfo().Atk ,component->getInfo().Def, gp, sym, name, component->getInfo().r, component->getInfo().c};
		return Info{component->getInfo().HP-10, HPmax, component->getInfo().Atk,component->getInfo().Def,gp, sym, name,component->getInfo().r,component->getInfo().c};
	}
}


WA::WA(Player *component):PotionDecorator{component}{}
Info WA::getInfo(){
	if(name == "Drow"){
		if(component->getInfo().Atk<=7.5)return Info{component->getInfo().HP,HPmax, 0, component->getInfo().Def,gp, sym, name, component->getInfo().r, component->getInfo().c};
        	else return Info{component->getInfo().HP, HPmax, component->getInfo().Atk-7.5, component->getInfo().Def, gp, sym, name, component->getInfo().r, component->getInfo().c};
	} else {
		if(component->getInfo().Atk<=5)return Info{component->getInfo().HP,HPmax, 0, component->getInfo().Def,gp, sym, name, component->getInfo().r, component->getInfo().c};
		else return Info{component->getInfo().HP, HPmax, component->getInfo().Atk-5, component->getInfo().Def, gp, sym, name, component->getInfo().r, component->getInfo().c};
	}
}

WD::WD(Player *component):PotionDecorator{component}{}
Info WD::getInfo(){
	if(name == "Drow"){
		if(component->getInfo().Def<=5)return Info{component->getInfo().HP,HPmax, component->getInfo().Atk, 0,gp, sym, name, component->getInfo().r, component->getInfo().c};
        	else return Info{component->getInfo().HP, HPmax, component->getInfo().Atk, component->getInfo().Def-5, gp, sym, name, component->getInfo().r, component->getInfo().c};
	} else {
		if(component->getInfo().Def<=5)return Info{component->getInfo().HP,HPmax, component->getInfo().Atk, 0,gp, sym, name, component->getInfo().r, component->getInfo().c};
		else return Info{component->getInfo().HP, HPmax, component->getInfo().Atk, component->getInfo().Def-5, gp, sym, name, component->getInfo().r, component->getInfo().c};
	}
}


