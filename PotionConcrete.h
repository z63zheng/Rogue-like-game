#ifndef _POTIONCONCRETE_H_
#define _POTIONCONCRETE_H_
#include "character2.h"
#include "PotionDecorator.h"

class RH: public PotionDecorator{
 public:
  RH(Player *component);
  Info getInfo() override;
};

class BA: public PotionDecorator{
 public:
  BA(Player *component);
  Info getInfo() override;
};

class BD: public PotionDecorator{
 public:
  BD(Player *component);
  Info getInfo() override;
};

class PH: public PotionDecorator{
 public:
  PH(Player *component);
  Info getInfo() override;
};

class WA: public PotionDecorator{
 public:
  WA(Player *component);
  Info getInfo() override;
};

class WD: public PotionDecorator{
 public:
  WD(Player *component);
  Info getInfo() override;
};

#endif



