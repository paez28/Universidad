#ifndef COMPUTER_H
#define COMPUTER_H 
#include <iostream>
#include <string>
using namespace std;
class Computer
{
private: 
	string nombre_;
	string modelo_;
	int precio_;

public:
	Computer(string nombre , string modelo , int precio = 1) {
		if (nombre.empty()) {
			nombre="Ninguno";
		}
		if (modelo.empty()) {
			modelo="Ninguno";
		}
		if (precio<=0) {
			precio=1;
		}
		nombre_ = nombre;
		modelo_ =modelo;
		precio_ = precio;
	}
	inline string getNombre() {return nombre_;}
	inline string getModelo() {return modelo_;}
	inline int getPrecio() {return precio_;}
	inline bool setNombre (string nombre) {
		if (nombre.empty()) {
			return false;
		}
		nombre_ = nombre;
		return true;
	}
	inline bool setModelo (string modelo) {
		if (modelo.empty()) {
			return false;
		}
		modelo_ = modelo;
		return true;
	}	
	inline bool setId(int id) {
		if (precio<=0) {
			return false;
		}
		precio_ = precio;
		return true;
	}
	inline string getNombreYModelo () {return (nombre_+", "+ modelo_);}
	~Computer() {}
	
};
#endif