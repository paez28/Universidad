#ifndef TAREATIEMPO_H
#define TAREATIEMPO_H

#include <iostream>
#include <list>
#include <string>
#include "tarea.h"

using namespace std;

class TareaTiempo : public Tarea{

private:
    float tiempo_;
public:

    TareaTiempo(int id,string nombre="XX",float tiempo=0):
    Tarea(id,nombre){
        setTiempo(tiempo);
    }

    inline float getTiempo(){return tiempo_;}
    inline bool setTiempo(float tiempo){
        if(tiempo<0){
            return false;
        }
        tiempo_=tiempo;
        return true;
    }






};


#endif