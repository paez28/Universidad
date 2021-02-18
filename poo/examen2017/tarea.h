#ifndef TAREA_H
#define TAREA_H

#include <iostream>
#include <string>

using namespace std;

class Tarea{

private:

    string nombre_;
    int id_;

public:

    Tarea(int id,string nombre="XX"){
        setId(id);
        setNombre(nombre);
    }

    inline int getId(){return id_;}
    inline string getNombre(){return nombre_;}

    inline bool setId(int id){
        if(id<0){
            return false;
        }
        id_=id;
        return true;
    }
    inline bool setNombre(string nombre){
        if(nombre ==""){
            return false;
        }
        nombre_=nombre;
        return true;
    }
    


};


#endif