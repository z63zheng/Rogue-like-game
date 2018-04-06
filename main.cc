#include <fstream>
#include <iostream>
#include "grid.h"
#include "character2.h"
#include "EnemyConcrete.h"
#include "PlayerConcrete.h"
#include "PotionDecorator.h"
#include "PotionConcrete.h"
#include "potion.h"
#include "treasure.h"
using namespace std;

class Next{};

int game();

int main(){
  int Continue = 1;
  while (Continue){
    Continue = game();
  }
}

int game(){
  int HP = 0;
  int gold = 0;
  bool freeze = false;
  string action;
  char playertype;
  cin >> playertype;
  Player *pc;
  for (int floor = 1; floor < 6; floor ++){
  ifstream file{"basic.txt"};
  Grid Map;
  Map.read(file);
 
 //generate pc
  if (HP){
    cout << "gold continue " << gold << endl;
    if(playertype=='s') pc = new Shade(&Map, HP,gold);
    else if(playertype=='d') pc = new Drow(&Map, HP,gold);
    else if(playertype=='v') pc = new Vampire(&Map, HP,gold);
    else if(playertype=='g') pc = new Goblin(&Map, HP,gold);
    else pc = new Troll(&Map, HP,gold);
    
  } else {
    if(playertype=='s') pc = new Shade(&Map);
    else if(playertype=='d') pc = new Drow(&Map);
    else if(playertype=='v') pc = new Vampire(&Map);
    else if(playertype=='g') pc = new Goblin(&Map);
    else pc = new Troll(&Map);
   
  }
  pc->generate(true);

//generate enemy and potion. Attach to pc
  for (int i = 0; i < 20; i++){
    int random = rand() % 18;
    Enemy *ep;
    if (random < 4) ep = new Human(&Map);
    else if (random < 7) ep = new Dwarf(&Map);
    else if (random < 12) ep = new Halfling(&Map);
    else if (random < 14) ep = new Elf(&Map);
    else if (random < 16) ep = new Orcs(&Map);
    else ep = new Merchant(&Map);
    ep->generate(false);
    pc->attach(ep);
  }
  
  for (int i = 0; i < 10; i++){
    int random = rand() % 6;
    string name;
    if (random == 0) name = "RH";
    if (random == 1) name = "BA";
    if (random == 2) name = "BD";
    if (random == 3) name = "PH";
    if (random == 4) name = "WA";
    if (random == 5) name = "WD";
    
    Potion *pp = new Potion(&Map, name);
    pp->generate();
    pc->attach(pp);
  }
  for (int i = 0; i < 10; i++){
    int dra = rand() % 8;
    bool dragon = false;
    int value;
    if (dra / 7 == 1){
      value = 6;
      dragon = true;
    } else if (dra < 5){
      value = 1;
    } else {
      value = 2;
    }
    Treasure *tp = new Treasure(&Map, value, dragon);
    tp->generate();
    pc->addT(tp);
    if (value == 6){
      Enemy *dp = new Dragon(&Map, tp);
      pc->attach(dp);
    }
  }  
  Map.display();
  cout<<"Race: " << pc->getInfo().name<<" Gold: "<<pc->getGold();
    for (int i = 0; i < 50; i++) cout <<" ";
    cout << "Floor " << floor << endl;
    cout<<"HP: "<<pc->getInfo().HP<<endl;
    cout<<"Atk: "<<pc->getInfo().Atk<<endl;
    cout<<"Def: "<<pc->getInfo().Def<<endl;
    cout<<"Action: "<<pc->getAction()<<endl;

  try{
//pc action: move, use potion, attack
  string cmd;
  string addition;
  while(cin>>cmd){
    //move
    if (cmd.length() == 2){
      pc->move(cmd, freeze);
    }
    //use potion
    if (cmd == "u"){
      cin >> cmd;
      int row;
      int col;
      if(cmd == "no"){
        row = pc->getInfo().r-1;
        col = pc->getInfo().c;
        //pc = pc->use(row, col, pc);
      }
      else if(cmd == "so"){
        row = pc->getInfo().r+1;
        col = pc->getInfo().c;
        //pc = pc->use(row, col, pc);
      }
      else if(cmd == "ea"){
        row = pc->getInfo().r;
        col = pc->getInfo().c+1;
        //pc = pc->use(row, col, pc);
      }
      else if(cmd == "we"){
        row = pc->getInfo().r;
        col = pc->getInfo().c-1;
	//pc = pc->use(row, col, pc);
      }
      else if(cmd == "nw"){
        row = pc->getInfo().r-1;
        col = pc->getInfo().c-1;
	//pc = pc->use(row, col, pc);
      }
      else if(cmd == "ne"){
        row = pc->getInfo().r-1;
        col = pc->getInfo().c+1;
	//pc = pc->use(row, col, pc);
      }
      else if(cmd == "se"){
        row = pc->getInfo().r+1;
        col = pc->getInfo().c+1;
	//pc = pc->use(row, col, pc);
      } else {
        row = pc->getInfo().r+1;
	col = pc->getInfo().c-1;
	//pc = pc->use(row, col, pc);
      }
      pc = pc->use(row,col,pc,freeze);
      //pc.use(direction);
    }
    //freeze
    if (cmd == "f"){
      freeze = !freeze;
    }
    if (cmd == "q"){
      double score = pc->getGold();
      if (pc->getInfo().name == "Shade") score = score * 1.5;
      cout<< "score: " << score << endl;
      cout << "defeated" << endl;
      delete pc;
      return 0;
    }
    if (cmd == "r"){
      double score = pc->getGold();
      if (pc->getInfo().name == "Shade") score = score * 1.5;
      cout<< "score: " << score << endl;
      cout << "defeated" << endl;
      delete pc;
      return 1;
    }
    //attack
    if (cmd == "a"){
      cin >> cmd;
      
      if(cmd == "no"){
        int row = pc->getInfo().r-1;
        int col = pc->getInfo().c;
        pc->attack(row, col, pc->getInfo().Atk,freeze);
       
      }
      else if(cmd == "so"){
        int row = pc->getInfo().r+1;
        int col = pc->getInfo().c;
        pc->attack(row, col, pc->getInfo().Atk,freeze);
        
      }
      else if(cmd == "ea"){
        int row = pc->getInfo().r;
        int col = pc->getInfo().c+1;
        pc->attack(row, col, pc->getInfo().Atk,freeze);
      
      }
      else if(cmd == "we"){
        int row = pc->getInfo().r;
        int col = pc->getInfo().c-1;
        pc->attack(row, col, pc->getInfo().Atk,freeze);
        
      }
      else if(cmd == "nw"){
        int row = pc->getInfo().r-1;
        int col = pc->getInfo().c-1;
        pc->attack(row, col, pc->getInfo().Atk,freeze);
   
      }
      else if(cmd == "ne"){
        int row = pc->getInfo().r-1;
        int col = pc->getInfo().c+1;
        pc->attack(row, col, pc->getInfo().Atk,freeze);
 
      }
      else if(cmd == "se"){
        int row = pc->getInfo().r+1;
        int col = pc->getInfo().c+1;
        pc->attack(row, col, pc->getInfo().Atk,freeze);
      
      } else {
	int row = pc->getInfo().r+1;
        int col = pc->getInfo().c-1;
        pc->attack(row, col, pc->getInfo().Atk,freeze);
     
      }
      
    }
    if (pc->getInfo().HP <= 0){
      double score = pc->getGold();
      if (pc->getInfo().name == "Shade") score = score * 1.5;
      cout<< "score: " << score << endl;
      cout << "defeated" << endl;
 
      delete pc;
      return 0;
    } 
    Map.display();
    gold = pc->getGold();
    cout<<"Race: " << pc->getInfo().name<<" Gold: " << pc->getGold();
    for (int i = 0; i < 50; i++) cout <<" ";
    cout << "Floor " << floor << endl;
    cout<<"HP: "<<pc->getInfo().HP<<endl;
    cout<<"Atk: "<<pc->getInfo().Atk<<endl;
    cout<<"Def: "<<pc->getInfo().Def<<endl;
    cout<<"Action: "<<pc->getAction()<<endl;
  }
  double score = pc->getGold();
  if (pc->getInfo().name == "Shade") score = score * 1.5;
  cout<< "score: " << score << endl;
  cout << "defeated" << endl;
  delete pc;
  return 0;
  } catch(Next &b){
    HP = pc->getInfo().HP;
    
    delete pc;
  }
 }
 double score = gold;
 if (playertype == 's') score = score * 1.5;
 cout<< "score: " << score << endl;
 cout << "victory" << endl;
 delete pc;
 return 0;
}



