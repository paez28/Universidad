#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <cassert>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace ed
{

	template <class G_Nodo, class G_Lado>
	class Grafo
	{
	private:

		G_Lado **_lados;

		G_Nodo *_nodos;

		int *_numnodos;

	public:

		// constructores
		Grafo(){
			_numnodos = new int;
			*_numnodos = 0;
			_lados = new G_Lado*;
			_nodos = new G_Nodo;
		
		}

		Grafo (int n){
			reservaMemoria(n);
		}

		Grafo(const Grafo &g){
			*this = g;

		}

		//destructores
		~Grafo(){
			//if(not isEmpty())
				borrarGrafo();
		}
		/*bool isEmpty() const{
			if(this->_lados== 0 && this->_nodos==0){
				return true;
			}
			return false;
		}*/

		// funciones
		void reservaMemoria(int n) {
			_numnodos = new int;
          	*_numnodos = n;
			_lados = new G_Lado*[*_numnodos];
            _nodos = new G_Nodo[*_numnodos];
            for(int i=0; i < *_numnodos; ++i){
				_lados[i] = new G_Lado[*_numnodos];
			}
        }
		
		int getnumNodos() const {
			return *_numnodos;
		}

		G_Nodo getNodo(int pos) const {
			return _nodos[pos];
		}

		G_Lado** getLado(int posi, int posj) const {
			return _lados[posi][posj];
		}

		void setNodo(int pos, G_Nodo nodo){
			_nodos[pos] = nodo;
		}

		void setLado(int posi, int posj, G_Lado lado){
			_lados[posi][posj] = lado;
		}

		void setnumNodos(int nodos){
			*_numnodos =nodos;
		}
		void borrarGrafo() {	// cabecera indicada para que compile
			delete [] _nodos;
			
			for (int i = 0; i < *_numnodos; ++i){
				delete [] _lados[i];
			}
			delete [] _lados;
			_nodos = NULL;
			_lados = NULL;
		}

		Grafo& operator=(const Grafo& g){
			//reservo mem de numnodos
			_numnodos = new int;
            *_numnodos = *g._numnodos;

			//ahor apara el constructor
			_lados = new G_Lado*[*_numnodos];
			_nodos = new G_Nodo[*_numnodos];

			for (int i = 0; i < *_numnodos; ++i){
				_lados = new G_Lado*[*_numnodos];
			}

			for (int i = 0; i < *_numnodos; ++i){
				_nodos[i] = g._nodos[i];
			}

			for (int i = 0; i < *_numnodos; ++i){
				for (int j = 0; i < *_numnodos; ++j){
					_lados[i][j] = g._lados[i][j];
				}
			}
			return *this;
        }
		void setMatrix(G_Lado **matriz) const{
		for (int i = 0; i < getnumNodos(); ++i) {
			for (int j = 0; j < getnumNodos(); ++j) {
				matriz[i][j] = _lados[i][j];
			}
		}
		}
		void impMatriz(){
			for (int i=0; i<*_numnodos; i++){
				cout<<"[";
				for (int j=0; j<*_numnodos; j++){
					cout<<_lados[i][j]<<" ";
				}
				cout<<"]"<<endl;
    		}
		}

		/*bool cargarGrafo(Grafo<G_Nodo, G_Lado> * &g)
		{
			string fichMatriz, fichNodos;

			cout << "Fichero de la matriz de salida: ";
			cin >> fichMatriz;

			cout << "Fichero de los nodos: ";
			cin >> fichNodos;

			int nodosaux = 0;
			ifstream archNodos;
			ifstream archLados;
			archLados.open(fichMatriz.c_str());
			archNodos.open(fichNodos.c_str());
			string buffer;

		
			while(getline(archNodos, buffer)){
				nodosaux++;
			}

			reservaMemoria(nodosaux);
			archNodos.close();
			archNodos.open(fichNodos.c_str());

			//Vamos a recorrer el fichero
			while(getline(archNodos, buffer)){
				g->getNodo().pushback(buffer.substr(0,buffer.size()-1)); 
			}

			
			vector<G_Lado> Lados; 
			G_Lado Lado; 

			while(getline(archLados, buffer)){
				Lados.clear(); 
				while(buffer.find(' ') != string::npos){ 
					Lado = atoi(buffer.substr(0, buffer.find(' ')).c_str()); 
					buffer = buffer.substr(buffer.find(' ') + 1, buffer.size()); 
					Lados.push_back(Lado); 
				}

				Lado = atoi(buffer.substr(0, buffer.find('\n')).c_str());
				Lados.push_back(Lado);

				
				g->getLado().push_back(Lados);
				
			}
		
			archNodos.close();
			archLados.close();

			return true;
			
			}*/

	};
}

#endif
