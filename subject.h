#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include "Info.h"
//include "subscriptions.h"
class Observer;
class Character;
class Potion;
class Enemy;


class Subject {
 protected:
  std::string action;
  std::vector<Observer*> observers;
  friend class Potion; 
  friend class Enemy;
 public:
  virtual std::string getAction();
  void attach(Observer *o); 
  void dettach(Observer *o);
  void notifyObservers();
  virtual Info getInfo() = 0;
  virtual void defend(Character &atkor, double atk, double def) = 0;
  virtual ~Subject() = 0;
  
};

#endif



