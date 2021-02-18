#ifndef MEZCLA_H
#define MEZCLA_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "tarea.h"
using namespace std;

class Mezcla : public Tarea{

private:
    list<string> lista_;

public:
    Mezcla(int id, string nombre="XX"):Tarea(id,nombre){}

   bool addIngrediente(string ingrediente);
   inline int getN(){return lista_.size();}
   void print();
   void write();


};


#endif