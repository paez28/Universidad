#include "mezcla.h"

bool Mezcla::addIngrediente(string ingrediente){
    list<string>::iterator it;
    for(it=lista_.begin();it!=lista_.end();it++){
        if(getNombre()!=ingrediente)
            lista_.push_back(ingrediente);
            return true;
    }
    return false;

}
void Mezcla::print(){
    list<string>::iterator it;
    int aux=1;
    for(it=lista_.begin();it!=lista_.end();it++){
        cout << aux << "," << (*it);
        aux++;
    }
}
void Mezcla::write(){
    ofstream fichero;
    fichero.open("salida.txt");
    list<string>::iterator it;
    int aux=1;
    for(it=lista_.begin();it!=lista_.end();it++){
        fichero << aux << (*it);
        aux++;
    }
    fichero.close();
}