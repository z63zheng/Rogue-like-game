#include <iostream>
#include <vector>
#include "subject.h"
#include "observer.h"
//#include "subscriptions.h"
using namespace std;

Subject::~Subject() {
  for(unsigned int i = 0; i < observers.size(); ++i) {
   delete observers[i];
  }
}

string Subject::getAction(){
  return action;
}

void Subject::attach(Observer *o) {  
  observers.emplace_back(o);
}

void Subject::dettach(Observer *o) {  
  for (unsigned int i= 0; i< observers.size(); i++)
    {
        if (observers[i] == o)
        {
            observers.erase(observers.begin()+i);
            return;
        }
    }
}

void Subject::notifyObservers() {
  int len = observers.size();
  for(int i = 0; i < len; ++i){
    Observer *ob = observers[i];    
    ob->notify(*this);     
  }
}



