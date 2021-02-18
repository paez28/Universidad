#include "jugador.h"

void Jugador::setApuestas(){

    Apuesta apuesta_jugador;
    char cantidad[50], tipo[50], valor[50];

    apuestas_.clear();

    string jugadores=getDNI()+".txt";
    ifstream archivo(jugadores.c_str());

    if(archivo.is_open()==false){
        cout <<"No se puede abrir.";
    }
    while(archivo.getline(tipo,256,',')){
        archivo.getline(valor,256,',');
        archivo.getline(cantidad,256,',');

        apuesta_jugador.tipo=atoi(tipo);
        apuesta_jugador.valor=valor;
        apuesta_jugador.cantidad=atoi(cantidad);

        apuestas_.push_back(apuesta_jugador);


    }

    archivo.close();

}