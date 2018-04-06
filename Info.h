#ifndef _INFO_H_
#define _INFO_H_
#include <string>

class Grid;

struct Info {
 int HP;
 int HPmax;
 double Atk;
 double Def;
 Grid *gp;
 char sym;
 const std::string name;
 int r;
 int c;
};

#endif


