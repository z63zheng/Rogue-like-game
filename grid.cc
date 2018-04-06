#include <iostream>
#include <string>
#include "grid.h"
using namespace std;

class Next{};

Grid::Grid() {
}

Grid::~Grid() {
  for(unsigned int i = 0; i < theGrid.size(); ++i) {
   for(unsigned int j = 0; j < theGrid[i].size(); ++j) {
    delete theGrid[i][j];
   }
  }
}

bool Grid::checkOccupied(int r, int c, bool room){
  if (!room) return theGrid[r][c]->ifoccupied();
  if ((theGrid[r][c]->getInfo().sym == '+')|| (theGrid[r][c]->getInfo().sym == 'G')) return true;
  return theGrid[r][c]->ifoccupied();
}

void Grid::occupy(int r, int c, char symb){
  theGrid[r][c]->occupy(symb);
}

void Grid::unoccupy(int r,int c){
  theGrid[r][c]->unoccupy();
}
  
void Grid::checkStair(int r, int c){
  if (theGrid[r][c]->getInfo().sym == '/') throw Next{};
}

Info Grid::randTile(int random){
  
  //cout << random << endl;
  int index = rand() % rooms[random].size();
  //cout << rooms[random].size() << endl;
  while(rooms[random][index]->ifoccupied()){
    index = rand() % rooms[random].size();
  }
  return rooms[random][index]->getInfo();  
}
void Grid::read(istream &in){
  string s;
  int r = 0;
  while(getline(in,s)){
    vector<Tile *> row;
    int len = s.length();
    for(int c = 0; c < len; c++){
      Tile *tp = new Tile(r,c,s[c]);
      row.emplace_back(tp);
    }
    theGrid.emplace_back(row);
    r++;
  }
  vector <Tile *> room1;
  for (int i = 3; i < 7; i ++){
    for (int j = 3; j < 29; j ++){
      room1.emplace_back(theGrid[i][j]);
    }
  }
  rooms.emplace_back(room1);
  vector <Tile *> room2;
  for (int i = 39; i < 62; i++){
    room2.emplace_back(theGrid[3][i]);
    room2.emplace_back(theGrid[4][i]);
  }
  for (int i = 39; i < 70; i++){
    room2.emplace_back(theGrid[5][i]);
  }
  for (int i = 39; i < 73; i++){
    room2.emplace_back(theGrid[6][i]);
  }
  for (int i = 7; i < 13; i++){
    for (int j = 61; j < 76; j++){
      room2.emplace_back(theGrid[i][j]);
    }
  }
//  rooms.emplace_back(room2);
  vector<Tile *> room3;
  for (int i = 10;i < 13; i ++ ){
    for (int j = 38; j < 50; j++){
      room3.emplace_back(theGrid[i][j]);
    }
  }
  rooms.emplace_back(room3);
  vector<Tile *> room4;
  for (int i = 15;i < 22; i ++ ){
    for (int j = 4; j < 25; j++){
      room4.emplace_back(theGrid[i][j]);
    }
  }
  rooms.emplace_back(room4);
  vector<Tile *> room5;
  for (int i = 37; i < 76; i ++){
    for (int j = 19; j < 22; j++){
      room5.emplace_back(theGrid[j][i]);
    }
  } 
  for (int i = 65; i < 76; i++){
    for (int j = 16; j < 19; j++){
      room5.emplace_back(theGrid[j][i]);
    }
  }
  rooms.emplace_back(room5);
  rooms.emplace_back(room2);
}


void Grid::display() {
  int gridlen = theGrid.size();
  for (int i = 0; i < gridlen; i ++){
    vector<Tile *> row = theGrid[i];
    int len = row.size();
    for (int j = 0; j < len; j ++){
      cout << theGrid[i][j]->getInfo().sym;
    }
    cout << endl;
  }
}



