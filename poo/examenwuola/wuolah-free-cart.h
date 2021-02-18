#ifndef CART_H
#define CART_H 
#include <iostream>
#include <string>
#include <list>
#include "computer.h"
using namespace std;
	class Cart
	{
	private:
		int id_;
		list<Computer> lista_;
	public:
		Cart(int id) {id_ = id;}
		inline int getId() const{return id_;}
		inline int getN () const{return (int ) lista_.size();}
		inline void addComputer (const Computer &c) {lista_.push_back(c);}
		inline void print () {
			list<Computer> ::iterator i;
			int posicion = 1;
			for (i=lista_. begin () ; i != lista_.end() ; i++) {
				cout<<posicion<<", "<<i->getId()<<", "<<i->getNombre()<<", "<<i->getModelo()<<", "<<i->getPrecio<<"\n";
				posicion++;
			}
		}
		inline void write () {
			ofstream fich ("salida.txt");
			list<Computer> ::iterator i;
			int posicion = 1;
			for (i=lista_. begin () ; i != lista_.end() ; i++) {
				fich<<posicion<<", "<<i->getId()<<", "<<i->getNombre()<<", "<<i->getModelo()<<", "<<i->getPrecio<<"\n";
				posicion++;
			}
			fich.close ();	
			
		}

		~Cart() {}
		
	};
#endif	
