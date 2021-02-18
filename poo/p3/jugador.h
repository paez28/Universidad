#ifndef JUGADOR_H
#define JUGADOR_H
#include "persona.h"

#include <string>
#include <list>
#include <fstream>  //biblioteca de ficheros, provee facilidades para la entrada y salida basada en archivos.
#include <cstdlib> //bliblioteca para usar atoi
using namespace std;

struct Apuesta
{
    int tipo;
    string valor;
    int cantidad;
};


class Jugador : public Persona{

private:
    int dinero_;
    string codigo_;
    list<Apuesta> apuestas_;
public:

    Jugador(string DNI, string codigo, 
		string nombre="", string apellidos="", int edad=0, 
		string direccion="", string localidad="",
		string provincia="",string pais="" )
        :Persona(DNI,nombre,apellidos,edad,direccion,localidad,
        provincia,pais){
            codigo_=codigo;
            dinero_=1000;
        }

    inline void setCodigo(string codigo){codigo_=codigo;}
    inline string getCodigo(){return codigo_;}
    inline void setDinero(int dinero){dinero_=dinero;}
    inline int getDinero(){return dinero_;}

    inline list<Apuesta> getApuestas(){return apuestas_;}
    void setApuestas();

};


#endif