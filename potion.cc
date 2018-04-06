#include "potion.h"
#include "Info.h"
using namespace std;

Info Potion::getInfo(){
  
  return Info{0,0,0,0,gp,'P',name,r,c};
  
}

int Potion::used[6] = {0,0,0,0,0,0};

void Potion::generate(){
  int num = rand() % 5;
  Info pos = gp->randTile(num);
  r = pos.r;
  c = pos.c;
  gp->occupy(r, c, 'P');
}

void Potion::notify(Subject &whoNotified){
  Info inf = whoNotified.getInfo();
  int distance = (inf.r - r) * (inf.r - r) + (inf.c - c) * (inf.c - c);
  if (distance <= 2){ 
    if ((name == "RH") && (used[0] == 1)) action = " and sees a RH potion.";
    else if ((name == "BA") && (used[1] == 1)) action = " and sees a BA potion."; 
    else if ((name == "BD") && (used[2] == 1)) action = " and sees a BD potion.";
    else if ((name == "PH") && (used[3] == 1)) action = " and sees a PH potion.";
    else if ((name == "WA") && (used[4] == 1)) action = " and sees a WA potion.";
    else if ((name == "WD") && (used[5] == 1)) action = " and sees a WD potion.";
    else action = " and sees an unknown potion.";  
    whoNotified.action += action;
  }
}


Potion::Potion(Grid *gp, string name): gp{gp}, name{name}{}

Potion::~Potion() {}

void Potion::use(){
  
  if (name == "RH") used[0] = 1;
  if (name == "BA") used[1] = 1;
  if (name == "BD") used[2] = 1;
  if (name == "PH") used[3] = 1;
  if (name == "WA") used[4] = 1;
  if (name == "WD") used[5] = 1;
  action = "PC uses " + name;
  //cout << "hi again"<<endl;
//  cout << r << c<<endl;
  gp->unoccupy(r,c);
}



