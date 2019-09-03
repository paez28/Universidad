#include <iostream>
#include <cstring>
#include <cstdlib> //Para usar system
#include <fstream> //Para trabajar con ficheros

#include "grafo.hpp"
#include "algoritmosgrafos.hpp"
#include "funciones.hpp"

using namespace std;
using namespace ed;

int main()
{
	Grafo<string, int> *g = new Grafo<string, int>;
	int opcion;
	bool grafoIntroducido = false;

	do {
		opcion = menu();
		switch (opcion) {
			case 1: // Cargar grafo desde fichero
				if (grafoIntroducido)
					(*g).borrarGrafo(); // Si hay un grafo introducido se borra.

				grafoIntroducido = cargarGrafo(g);

				if (grafoIntroducido) {
					cout << "Grafo cargado correctamente \n";
					g->imprimeMatriz();
					Grafo<string, int> g1 = *g;
				}
				else
					cout << "Grafo no cargado \n";

				getchar();
				getchar();
				break;

			case 2: //Algoritmo de Floyd
				if ( grafoIntroducido )
					algoritmoFloyd(*g);
				else
					cout << "Primero tiene que introducir un grafo\n";
				getchar();
				getchar();
				break;
		}
	} while (opcion!=0);

	return 0;
}
