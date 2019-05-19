#ifndef __FUNCIONES_HPP
#define __FUNCIONES_HPP

#include <iostream>
#include <cstring>
#include <cstdlib> //Para usar system
#include <fstream> //Para trabajar con ficheros
#include <cmath>
#include <string> 

#include "grafo.hpp"
#include "algoritmosgrafos.hpp"

using namespace std;
using namespace ed;

int menu()
{
  int opcion;

  system("clear");
  cout << "  0. Salir................................\n";
  cout << "  1. Cargar grafo desde fichero...........\n";
  cout << "  2. Algoritmo de Floyd (GD y GND)......\n";

  cout << "Introduzca opcion...:";
  cin >> opcion;

  return opcion;
}

template <class G_Nodo, class G_Lado>
bool cargarGrafo(Grafo<G_Nodo, G_Lado> * &g)
{
  string ficheroMatriz, ficheroEtiquetas, aux;
  ifstream fichNodos;
  ifstream fichLados;
  int nodoscounter = 0;
  int index = 0;
  G_Nodo nodo;
  G_Lado lado;


  cout << "Fichero de la matriz de conexion: ";
  cin >> ficheroMatriz;

  cout << "Fichero de las etiquetas: ";
  cin >> ficheroEtiquetas;

 
  fichNodos.open(ficheroEtiquetas.c_str());
  while(getline(fichNodos, aux)){
    nodoscounter++;
  }
  fichNodos.close();
  g->reservaMemoria(nodoscounter);
  
  
  fichNodos.open(ficheroEtiquetas.c_str());
  
  while(getline(fichNodos, aux)){
    nodo = aux;
    g->setNodo(index, nodo);
    index++;
  }
  fichNodos.close();

 
  fichLados.open(ficheroMatriz.c_str()); 
  for(int fila = 0; fila < g->getnumNodos(); ++fila){
    for(int columna = 0; columna < g->getnumNodos() - 1; ++columna){
      getline(fichLados, aux, ' ');
      int lado_aux = atoi(aux.c_str());
      lado = lado_aux;
      g->setLado(fila, columna, lado);      
    }
    getline(fichLados, aux, '\n');
    int lado = atoi(aux.c_str());
    lado = lado;
    g->setLado(fila, g->getnumNodos() -1, lado);
  }
  fichLados.close();

  return true;	
}


template <class G_Nodo, class G_Lado>
void algoritmoFloyd(const Grafo<G_Nodo, G_Lado> &g)
{
   
  G_Lado **matrizAux;
  matrizAux = new G_Lado*[g.getnumNodos()];
  for(int i=0; i < g.getnumNodos(); ++i){
				matrizAux[i] = new G_Lado[g.getnumNodos()];
	}

  g.setMatrix(matrizAux);

  for(int i = 0; i < g.getnumNodos(); ++i){
    matrizAux[i][i] = 0;
  }

  for(int i = 0; i < g.getnumNodos(); ++i){
    for (int j = 0; j < g.getnumNodos(); ++j){
      for (int k = 0; k < g.getnumNodos(); ++k){
        if (matrizAux[j][i] + matrizAux[i][k] < matrizAux[j][k]){
          matrizAux[j][k] = matrizAux[j][i] + matrizAux[i][k];
        }
      }
    }
  }

  cout<<"Matriz de distancias:"<<endl;
  for(int i = 0; i < g.getnumNodos(); ++i){
     cout<<endl;
    for (int j = 0; j < g.getnumNodos(); ++j){
      cout<<matrizAux[i][j]<<" ";
    }
  }

  G_Lado **mrecorridos;
  mrecorridos = new G_Lado*[g.getnumNodos()];
  for(int i=0; i < g.getnumNodos(); ++i){
				mrecorridos[i] = new G_Lado[g.getnumNodos()];
	}

  cout<< g.getnumNodos();
  for(int i = 0; i < g.getnumNodos(); ++i){
    for(int j = 0; j < pow(g.getnumNodos(), 2); ++j){
      mrecorridos[i][j] = -1;
    }
  }

  g.setMatrix(matrizAux);

  for(int i = 0; i < g.getnumNodos(); ++i){
    matrizAux[i][i] = 0;
  }

  for(int i = 0; i < g.getnumNodos(); ++i){
    for (int j = 0; j < g.getnumNodos(); ++j){
      for (int k = 0; k < g.getnumNodos(); ++k){
        if (matrizAux[j][i] + matrizAux[i][k] < matrizAux[j][k]){
         matrizAux[j][k] = matrizAux[j][i] + matrizAux[i][k];
         mrecorridos[j][k] = i;
        }
      }
    }
  }

  cout<<'\n'<<endl;
  cout<<"Matriz de distancia recorrida:"<<endl;
  for(int i = 0; i < g.getnumNodos(); ++i){
     cout<<endl;
    for (int j = 0; j < g.getnumNodos(); ++j){
      cout<<mrecorridos[i][j]<<" ";
    }
  }
}

#endif
