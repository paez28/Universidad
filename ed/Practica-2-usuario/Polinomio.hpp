/*!
   \file Polinomio.hpp
   \brief Definición de la clase Polinomio
*/

#ifndef _POLINOMIO_HPP_
#define _POLINOMIO_HPP_

// Control de asertos
#include <cassert>

// Vector de STL
#include <vector>
#include <list>

// Para usar la función abs
#include <cmath>

#include "PolinomioInterfaz.hpp"
#include "Monomio.hpp"


// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio: public ed::PolinomioInterfaz
{

  //! \name Atributos privados de la clase Polinomio
   private:
	int _grado;
    std::vector<ed::Monomio>_v;

   //! \name Funciones o métodos públicos de la clase Polinomio
   public:

	//! \name Constructores de la clase Polinomio

	/*!
		\fn inline Polinomio()
		\brief Crea un nuevo monomio usando coeficiente 0.0 y grado 0
		\attention Funcion sobrecargada
		\note Funcion inline
		\pre Ninguna
		\post  El polinomio creado es nulo.
		\sa  
	*/	

	inline Polinomio()
    {
		_v.push_back(Monomio(0.0,0)); // añado los vaores de grado y coeficiente a la lista

		#ifndef NDEBUG
		assert(esNulo());
		#endif //NDEBUG
    
	}
	/*!
		\fn inline Polinomio(Polinomio const &p)
		\brief Crea un nuevo polinomio a partir de otro polinomio
		\attention Funcion sobrecargada
		\note Funcion inline
		\pre Ninguna
		\post  El polinomio creado es igual al polinomio “p”.
		\sa  inline Polinomio()
	*/	
	
	inline Polinomio(Polinomio const &p)
	{
		_v = p._v;

		#ifndef NDEBUG
		assert(this->_v == p._v);
		#endif //NDEBUG

	}
  //! \name Observadores: funciones de consulta de la clase Polinomio



	//! \name Funciones de modificación de la clase Polinomio



 	////////////////////////////////////////////////////////////////

   //! \name Operadores de la clase Polinomio

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Polinomio const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Monomio const &m);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(double const &x);

  // Operadores aritméticos y asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator+=(Polinomio const &p);


	// COMPLETAR EL RESTO DE OPERADORES


  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Polinomio

	// COMPLETAR


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Polinomio

	// COMPLETAR


}; // Fin de la definición de la clase Polinomio




} // \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
