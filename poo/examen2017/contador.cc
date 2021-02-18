#include "contador.h"

Contador Contador::operator=(int a){
    if(max_>a){
        setV(a);
    }else{
        setV(max_);
    }
    return *this;
}
Contador Contador::operator=(Contador c){
    (*this).setV(c.getV());
    (*this).setM(c.getM());
    
    return *this;
}

Contador Contador::operator++(void){
    valor_++;
    
    return *this;
}
Contador Contador::operator++(int){
    Contador aux=*this;
    valor_++;
    return aux;
}
Contador Contador::operator+(int a){
    if(max_ < (a+valor_)){
        valor_=max_;
        }else{
            valor_=valor_+a;
        }
    return *this;

}
Contador operator+(int aux,Contador c){
    if(c.getM()<(aux+c.getV())){
        c.setV(c.getM());
    }else{
        c.setV(aux+c.getV());
    }
    return c;
}