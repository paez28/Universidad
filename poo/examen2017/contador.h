#ifndef CONTADOR_H
#define CONTADOR_H
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

class Contador{

private:
    int valor_;
    int max_;
public:
    Contador(int valor=0,int max=100){
        setV(valor);
        max_=max;
    }    

    inline int getV(){return valor_;}
    inline int getM(){return max_;}

    inline bool setV(int valor){
        if(valor>max_){
            valor_=max_;
            return false;
        }else{
            valor_=valor;
            return true;
        }
    }
    inline bool setM(int max){
        max_=max;
        return true;
    }
    Contador operator=(int a);
    Contador operator=(Contador c);
    Contador operator++(void);
    Contador operator++(int);
    Contador operator+(int a);
    friend Contador operator+(int aux, Contador c);

};

#endif