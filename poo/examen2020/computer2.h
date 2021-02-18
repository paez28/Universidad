#ifndef COMPUTER_H
#define COMPUTER_H

#include<iostream>
#include<string>

using namespace std;

class Computer{
private:
    
    string nombre_;
    string modelo_;
    int precio_;



public:
    Computer(string nombre,string modelo,int precio=1){
        if(nombre.empty()){
            nombre_="Ninguno";
        }
        if(modelo.empty()){
            modelo_="Ninguno";
        }
        setNombre(nombre);
        setModelo(modelo);
        setPrecio(precio);    


    }

    inline string getNombre(){return nombre_;};
    inline string getModelo(){return modelo_;};
    inline int getPrecio(){return precio_;};

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
	inline bool setPrecio(int id) {
		if (id<=0) {
			return false;
		}
		precio_ = id;
		return true;
	}
	inline string getNombreYModelo () {return (nombre_+", "+ modelo_);}
	~Computer() {}
	friend istream &operator>> (istream &stream , Computer &c) {
		string nombre,modelo;
		cout<<"Nombre: ";
		cin>>nombre;
		c.setNombre(nombre);
		cout<<"Modelo: ";
		cin>>modelo;
		c.setModelo(modelo);
		return stream;
	}
	friend ostream &operator<< (ostream &stream ,const Computer &c) {
		stream<<"Nombre: ";
		stream<< c.nombre_;
		stream<<"Modelo: ";
		stream<< c.modelo_;
		return stream;
	}

};


#endif