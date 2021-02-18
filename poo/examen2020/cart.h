#ifndef CART_H
#define CART_H

#include "computer.h"
#include <list>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Cart{

private:

    int id_;
    list<Computer> lista_;
public:

    Cart(int id){
        id_=id;
    }
    inline int getId(){return id_;}
    inline int getN(){return lista_.size();}

    void addComputer(Computer computer);
    void print();
    void write();


    ~Cart(){}


};



#endif