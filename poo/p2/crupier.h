#ifndef CRUPIER_H
#define CRUPIER_H

#include <string>
#include "persona.h"
using namespace std;

class Crupier :public Persona{

private:
string codigo_;

public:

Crupier(string DNI, string codigo, 
		string nombre="", string apellidos="", int edad=0, 
		string direccion="", string localidad="",string provincia="",
		string pais=""):Persona(DNI,nombre,apellidos,edad,direccion,
		localidad,provincia,pais){
			codigo_=codigo;
		}
inline void setCodigo(string codigo){codigo_=codigo;}
inline string getCodigo(){return codigo_;}


};




#endif