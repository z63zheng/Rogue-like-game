#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "Info.h"
//include "subscriptions.h"
class Subject;
class Player;


class Observer {
 public:
  virtual void notify(Subject &whoNotified) = 0;  // pass the Cell that called
                                                  // the notify method
  //virtual SubscriptionType subType() const = 0;
  virtual ~Observer(); //= default;
  virtual Info getInfo()=0;
  virtual void use() = 0;
  virtual void defend(Player &atkor, double atk, double def)= 0;
};

#endif


