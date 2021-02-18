#ifndef LAPTOP_H
#define LAPTOP_H

#include <iostream>
#include <string>
#include <list>
#include "computer.h"

using namespace std;

class Laptop: public Computer
{
private:
    int pulgadas_;
public:
    Laptop(int pulgadas,string modelo,int precio):Computer("Laptop",modelo,precio){
        setPulgadas(pulgadas);
    }

    inline int getPulgadas(){return pulgadas_;}
    inline  bool setPulgadas(int pulgadas){
        if(pulgadas>0){
            pulgadas_=pulgadas;
            return true;
        }
        return false;
    }

    inline void getInfo(){
        cout<<"Laptop de" + to_string(getPulgadas())+ "\",de"+
        getModelo()+","+ to_string(getPrecio())<<endl;
    }

    
};


#endif