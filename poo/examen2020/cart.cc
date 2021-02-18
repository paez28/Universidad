#include "cart.h"


void Cart::addComputer(Computer computer){
    return lista_.push_back(computer);
}

void Cart::print(){

    list<Computer>::iterator it;
    int incremento=1;

    for(it=lista_.begin();it !=lista_.end();it++){
        cout<<incremento<<","<<getId()<<","<<it->getNombre()<<
        ","<<it->getModelo()<<","<<it->getPrecio();
        incremento++;
    }
}
void Cart::write(){
    ofstream fichero;
    fichero.open("salida.txt");
    list<Computer>::iterator it;
    int posicion=1;

    for(it=lista_.begin();it!=lista_.end();it++){
        fichero<<posicion<<","<<getId()<<","<<it->getNombre()
        <<","<<it->getModelo()<<","<<it->getPrecio();
        posicion++;
    }
    fichero.close();
}