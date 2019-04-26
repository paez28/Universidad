#ifndef __ARBOLBINARIOORDENADO_HPP__
#define __ARBOLBINARIOORDENADOENLAZADO_HPP__

#include <iostream>
#include <cassert>
#include "arbolbinarioordenado.hpp"
#include "operadornodo.hpp"

using namespace std;
/*!
\brief Espacio de nombres para la asignatura Estructura de datos.
*/
namespace ed
{
	/*!\brief Interfaz para definir un ArbolBinario ordenado.

	Define una interfaz para definir un ArbolBinarioOrdenado.

	\arg G define el campo de información a contener en el arbol.
	\pre G debe tener definidos los operadores < y ==.
	*/
	template<class G>
	class ArbolBinarioOrdenadoEnlazado:public ArbolBinarioOrdenado<G>
	{
	private:

		/*!\brief Define un nodo del arbol binario.*/
		class NodoArbolBinario
		{
		private:
			G _info;  //Valor informativo almacenado en el nodo
			NodoArbolBinario * _izquierdo;  //Puntero al hijo izquierdo
			NodoArbolBinario * _derecho;  //Puntero al hijo derecho

		public:
			/*!
			\fn NodoArbolBinario (const G &info)
			\brief Crea un nuevo nodo con la información de “info”
			\pre Ninguna
			\post  El nodo creado no tiene hijos
			*/
			NodoArbolBinario (const G &info)
			{
				//_info=info;

				this->setInfo(info);
				this->setDerecho(NULL);
				this->setIzquierdo(NULL);
				#ifndef NDEBUG
				assert(this->esHoja());
				#endif //NDEBUG
			}
			/*!
			\fn NodoArbolBinario (const NodoArbolBinario &n)
			\brief Crea un nuevo nodo a partir de otro nodo.
			\pre Ninguna
			\post  El nodo creado es igual al nodo “n”.
			*/
			NodoArbolBinario (const NodoArbolBinario &n)
			{
				this->setInfo(n.getInfo());
				this->setDerecho(n.getDerecho());
				this->setIzquierdo(n.getIzquierdo());
				#ifndef NDEBUG
				assert(this->getInfo()==n.getInfo() &&
				this->getIzquierdo()==n.getIzquierdo() &&
				this->getDerecho()==n.getDerecho());
				#endif //NDEBUG
			}

			/*!\brief Observadores.*/
			/*!
			\fn const G & getInfo()
			\brief Devuelve la información contenida en el nodo
			*/
			const G & getInfo() const
			{
				return this->_info;
			}
			/*!
			\fn NodoArbolBinario *getIzquierdo() const
			\brief Devuelve el puntero al hijo izquierdo
			*/
			NodoArbolBinario *getIzquierdo() const
			{
				return _izquierdo;
			}
			/*!
			\fn NodoArbolBinario *getDerecho() const
			\brief Devuelve el puntero al hijo Derecho
			*/
			NodoArbolBinario *getDerecho() const
			{
				return _derecho;
			}
			/*!
			\fn bool esHoja() const
			\brief Comprueba si el nodo actual es hoja, es decir, no tiene hijo izquierdo ni derecho
			*/
			bool esHoja() const
			{
				//si no tiene hijos es hoja
				if((this->getDerecho()==NULL) && this->getIzquierdo()==NULL){
					return true;
				}
				return false;
			}

			/*!
			\fn void recorridoPreOrden (OperadorNodo<G> &operador) const
			\brief Aplica el operador “op” y delega sobre los hijos para realizar el recorrido en preorden
			*/
			void recorridoPreOrden (OperadorNodo<G> &operador) const
			{
				if(operador != NULL)
				{
					cout << operador->_info << " ";
					recorridoPreOrden(operador->getIzquierdo()); //si el operador es distinto a nulo asignamos los hijos izq y dere al puntero para recorrerlo
					recorridoPreOrden(operador->getDerecho());
				}
			}

			/*!
			\fn void recorridoPostOrden (OperadorNodo<G> &operador) const
			\brief Aplica el operador “op” y delega sobre los hijos para realizar el recorrido en inorden
			*/
			void recorridoPostOrden (OperadorNodo<G> &operador) const
			{
				if(operador != NULL)
				{
					recorridoPostOrden(operador->getIzquierdo());
					cout << operador->_info << " ";
					recorridoPostOrden(operador->getDerecho());

				}

			}

			/*!
			\fn void recorridoInOrden (OperadorNodo<G> &operador) const
			\brief Aplica el operador “op” y delega sobre los hijos para realizar el recorrido en postorden
			*/
			void recorridoInOrden (OperadorNodo<G> &operador) const
			{
				if(operador != NULL){
					recorridoInOrden(operador->getIzquierdo());
					recorridoInOrden(operador->getDerecho());
					cout << operador->_info << " ";
				}

			}
			/*!\brief Modificadores. */

			/*!
			\fn void setInfo(const G &info)
			\brief Establece el valor informativo del nodo actual
			*/
			void setInfo(const G &info)
			{
				_info = info;
			}

			/*!
			\fn void setIzquierdo(NodoArbolBinario *n)
			\brief Establece el puntero al hijo izquierdo del nodo actual
			*/
			void setIzquierdo(NodoArbolBinario *n)
			{
			 	this->_izquierdo = n;
			}

			/*!
			\fn void setDerecho(NodoArbolBinario *n)
			\brief Establece el puntero al hijo derecho del nodo actual
			*/
			void setDerecho(NodoArbolBinario *n)
			{
				this->_derecho = n;
			}

			/*!
			\fn NodoArbolBinario & operator=(const NodoArbolBinario &n)
			\brief Operador de asignación. Operador que copia el nodo “n” en el nodo actual
			\pre El nodo “n” debe ser diferente del nodo actual
			\post El nodo actual debe ser igual al nodo “n”
			*/
			NodoArbolBinario & operator=(const NodoArbolBinario &n)
			{
				#ifndef NDEBUG
				assert(this->getDerecho() != n.getDerecho() &&
						this->getIzquierdo() != n.getIzquierdo() );
				#endif //NDEBUG

				this->setDerecho(n.getDerecho());
				this->setIzquierdo(n.getIzquierdo()); // asignamos el nodo que se pasa por referencia a los set izq y der

				#ifndef NDEBUG
				assert(this->getDerecho() == n.getDerecho() &&
						this->getIzquierdo() == n.getIzquierdo() );
				#endif //NDEBUG
			}

		}; //Fin clase NodoArbolBinario

		//Implementación de la raíz
		NodoArbolBinario * _raiz; /*!<La raiz del árbol*/
		NodoArbolBinario * _actual; /*!<Cursor al nodo actual*/
		NodoArbolBinario * _padre; /*!<Cursor al nodo actual*/

	public:

		/*!
		\fn ArbolBinarioOrdenadoEnlazado ()
		\brief Crea un nuevo árbol vacío
		\pre Ninguna
		\post El árbol creado está vacío
		*/
		ArbolBinarioOrdenadoEnlazado ()
		{

			this->_raiz = NULL;
			this->_actual = NULL;
			this->_padre = NULL;

		#ifndef NDEBUG
		assert(estaVacio());
		#endif //NDEBUG
		}

		/*!
		\fn ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G>& a)
		\brief Crea un nuevo árbol a partir de otro árbol.
		\pre Ninguna
		\post El árbol creado es igual al árbol “a”.
		*/
		ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G>& a)
		{
			_raiz = a._raiz;
			_actual = a._actual;
			_padre = a._padre;

			#ifndef NDEBUG
			assert(_raiz == a._raiz &&
					_actual == a._actual &&
					_padre = a._padre);
			#endif //NDEBUG

		}

		/*!
		\fn ~ArbolBinarioOrdenadoEnlazado ()
		\brief Destructor de arbol
		\pre Ninguna
		\post El árbol creado es nulo
		*/
		~ArbolBinarioOrdenadoEnlazado ()
		{
			if (not estaVacio())
			borrarArbol();
			cout << "Destructor Usado \n";
		}

		/*!
		\fn ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado& a)
		\brief operador= de la clase ArbolBinarioOrdenadoEnlazado
		\pre Ninguna
		\post El objeto creado tiene que ser igual al pasado
		*/
		ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado& a)
		{
			this->_raiz = a._raiz;
			this->_actual = a._actual;
			this->_padre = a._padre;

			#ifndef NDEBUG
			assert(this->_raiz == a._raiz &&
						this->_actual == a._actual &&
						this->_padre == a._padre);
			#endif //NDEBUG

		}

		/*!
		\fn bool insertar(const G &x)
		\brief Inserta un elemento en el árbol, el cual deberá mantener el orden
		\pre Ninguna
		\post 	El elemento debe estar en el árbol
		\post	El árbol debe estar ordenado
		*/
		bool insertar(const G &x)
		{
			/*if (this->_raiz == NULL) {
				this->_raiz = new NodoArbolBinario(x);
				return true;
			}

			if (this->buscar(x))
				return false;

			NodoArbolBinario* nodo = new NodoArbolBinario(x);

			if (this->_padre->getInfo() > x) {

				this->_padre->setIzquierdo(nodo);
			}
			else {
				this->_padre->setDerecho(nodo);
			}

			return true;
			*/
		return false;
		}

		/*!
		\fn void borrarArbol()
		\brief Elimina el árbol por completo
		\pre El árbol no puede estar vacío
		\post El árbol debe estar vacío
		*/
		void borrarArbol()
		{
			this->_raiz = NULL;
			this->_actual = NULL;
			this->_padre = NULL;

		}

		/*!
		\fn bool borrar()
		\brief Elimina el nodo apuntado por “_actual”
		\pre “_actual” debe apuntar a algún nodo
		\post El elemento borrado no debe existir
		*/
		bool borrar()
		{
			/*
			if (!this->existeActual())
				return false;

			AlmacenarNodo<G> almacenador;

			this->_actual->recorridoPostOrden(almacenador);

			if (this->_padre->getInfo() > this->_actual->getInfo())
			    this->_padre->setIzquierdo(NULL);

            else
                this->_padre->setDerecho(NULL);

			std::vector<G> nodes = almacenador.vectorNodos();

            for (int i = 1; i < nodes.size(); ++i) {
                this->insertar(nodes[i]);
            }

			return true;
			*/
		return false;
		}

		/*!
		\fn void recorridoPreOrden (OperadorNodo<G> &operador) const
		\brief Realiza el recorrido preorden del árbol aplicando el operador “op”.
		*/
		void recorridoPreOrden (OperadorNodo<G> &operador) const
		{

		}

		/*!
		\fn void recorridoPostOrden (OperadorNodo<G> &operador) const
		\brief Realiza el recorrido inorden del árbol aplicando el operador “op”.
		*/
		void recorridoPostOrden (OperadorNodo<G> &operador) const
		{

		}

		/*!
		\fn void recorridoInOrden (OperadorNodo<G> &operador) const
		\brief Realiza el recorrido postorden del árbol aplicando el operador “op”.
		*/
		void recorridoInOrden (OperadorNodo<G> &operador) const
		{

		}

		/*!
		\fn bool buscar(const G& x) const
		\brief Busca un elemento en el árbol y actualiza el cursor de “_actual” y “_padre” si lo encuentra
		\pre Ninguna
		\post “_actual” debe apuntar al nodo encontrado, si lo encuentra
		*/
		bool buscar(const G& x) const
		{

			return false;
		}

		/*!
		\fn bool estaVacio() const
		\brief Comprueba si el árbol está vacío
		*/
		bool estaVacio() const
		{
			if(this->_raiz == NULL){return true;}

			return false;
		}

		/*!
		\fn G raiz() const
		\brief Obtiene el dato almacenado en la raíz
		\pre El árbol no puede estar vacío
		*/
		G raiz() const
		{
			#ifndef NDEBUG
			assert(this->_raiz != NULL);
			#endif //NDEBUG

			return this->_raiz.getInfo();

		}

		/*!
		\fn bool existeActual() const
		\brief Comprueba si “_actual” está apuntando a algún nodo
		\pre El árbol no puede estar vacío
		*/
		bool existeActual() const
		{
			#ifndef NDEBUG
			assert(this->_raiz != NULL);
			#endif //NDEBUG
			
			if(this->_actual == NULL){
				return false;
			}

			return true;
		}

		/*!
		\fn G actual() const
		\brief Devuelve el dato almacenado por el nodo “_actual”
		\pre “_actual” debe de apuntar a algún nodo
		*/
		G actual() const
		{
			#ifndef NDEBUG
			assert(this->_actual != NULL);
			#endif //NDEBUG

			return this->_actual.getInfo();

		}

		/*!@}*/
	};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
