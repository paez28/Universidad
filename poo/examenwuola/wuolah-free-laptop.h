#ifndef LAPTOP_H
#define LAPTOP_H 
#include <iostream>
#include <string>
#include "computer.h"
using namespace std;
class Laptop : public Computer
{
private:
	int pulgadas_;
public:
	Laptop(int pulgadas, string modelo, int precio) :Computer ("Laptop",modelo,precio)
	{
		if (pulgadas<= 0) {
			pulgadas =1;
		}
		pulgadas_= pulgadas;
	}
	inline int getPulgadas (){return pulgadas_;}
	inline bool setPulgadas (int pulgadas){
		if (pulgadas<= 0) {
			return false;
		}
		pulgadas_= pulgadas;
		return true;
	}
	inline string getInfo() {
		return (getNombre()+" de " +to_string (pulgadas_)+ " pulgadas " + getModelo() + " precio " + to_string (getPrecio()) )
	}
 	~Laptop();
	
};

#endif	