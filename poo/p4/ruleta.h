#ifndef RULETA_H
#define RULETA_H

#include <fstream>
#include <string>
#include <list>
#include <iostream>
#include "jugador.h"
#include "crupier.h"



using namespace std;


class Ruleta
{
private:
    int banca_;
    int bola_;
    list<Jugador> jugadores_;
    Crupier crupier_;
    bool player_exist(Jugador player);
public:
    Ruleta(Crupier crupier): crupier_(crupier){
        bola_=-1;
        banca_=1000000;
    }
    inline int getBola(){return bola_;}
    inline bool setBola(int bola){
        if(bola>=0 && bola<=36){
            bola_=bola;
            return true;
        }
        return false;
    }
    inline int getBanca(){return banca_;}
    inline bool setBanca(int banca){
        if(banca >0){
            banca_=banca;
            return true;
        }
        return false;
    }
    inline Crupier getCrupier(){return crupier_;}
    inline void setCrupier(Crupier crupier){crupier_=crupier;}
    inline list<Jugador> getJugadores(){return jugadores_;}
    bool addJugador(Jugador jugador);
    int deleteJugador(string DNI);
    inline int  deleteJugador(Jugador jugador){return 
    deleteJugador(jugador.getDNI());}
    void escribeJugadores();
    void leeJugadores();
    void getPremios();
    void giraRuleta();
};




#endif