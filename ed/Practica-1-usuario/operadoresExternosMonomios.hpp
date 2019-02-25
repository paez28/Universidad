/*! 
	\file operadoresExternosMonomios.hpp
	\brief Ficheros con los prototipos de los operadores externos de la clase Monomio
*/

#ifndef _OperadoresExternosMonomios_HPP_
#define _OperadoresExternosMonomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Monomio.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{
//////////////////////////////////////////////////////////////////////////////////////
	// Operadores externos que no pertenecen a la clase Monomio

	//! \name Operadores de igualdad  

	/*!
		\fn bool operator==(ed::Monomio const & m1, ed::Monomio const & m2)
		\brief comprueba si dos monomios son iguales
		\note ninguna
		\return return true
		\pre ninguna
		\post verdadero si los dos monomios tienen el mismo grado y el mismo
		coeficiente;
		\post falso, en caso contrario.
		\sa bool operator==(ed::Monomio const & m1, double const & x)
		\sa bool operator==(double const & x, ed::Monomio const & m2)
	*/
	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2);

	/*!
		\fn bool operator==(ed::Monomio const & m1, double const & x)
		\brief Comprueba si un monomio es igual a un número real: m== x
		\note ninguna
		\return return true
		\pre ninguna
		\post verdadero si el monomio tiene grado 0 y su coeficiente es igual al
		número “x”;
		\post falso, en caso contrario.
		\sa bool operator==(ed::Monomio const & m1, double const & x)
	*/

	bool operator==(ed::Monomio const & m1, double const & x);

	/*!
		\fn bool operator==(double const & x, ed::Monomio const & m2)
		\brief Comprueba si un monomio es igual a un número real: x == m
		\note ninguna
		\return return true
		\pre ninguna
		\post verdadero si el monomio tiene grado 0 y su coeficiente es igual al
		número “x”.
		\post falso, en caso contrario.
		\sa bool operator==(ed::Monomio const & m1, double const & x)
	*/

	bool operator==(double const & x, ed::Monomio const & m2);





	//! \name Operadores de desigualdad 

	/*!
		\fn bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
		\brief Comprueba si dos monomios no son iguales: m1 != m2
		\note ninguna
		\return return true
		\pre ninguna
		\post verdadero si los dos monomios no tienen el mismo grado o no tienen
		el mismo coeficiente;
		\post falso, en caso contrario.
		\sa bool operator!=(double const & x, ed::Monomio const & m2)
		\sa bool operator!=(ed::Monomio const & m1, double const & x)
	*/
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);

	/*!
		\fn bool operator!=(double const & x, ed::Monomio const & m2)
		\brief Comprueba si un monomio no es igual a un número real: m == x
		\note ninguna
		\return return true
		\pre ninguna
		\post verdadero si el monomio no tiene grado 0 o si su coeficiente no es
		igual al número “x”;
		\post falso, en caso contrario.
		\sa bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	*/
	bool operator!=(double const & x, ed::Monomio const & m2);

	/*!
		\fn bool operator!=(ed::Monomio const & m1, double const & x)
		\brief Comprueba si un monomio no es igual a un número real: x == m
		\note ninguna
		\return return true
		\pre ninguna
		\post vverdadero si el monomio no tiene grado 0 o si su coeficiente no es
		igual al número “x”;
		\post falso, en caso contrario.
		\sa bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
		\sa bool operator!=(double const & x, ed::Monomio const & m2)
	*/
	bool operator!=(ed::Monomio const & m1, double const & x);


	///////////////////////////////////////////////////

	//! \name Operadores unarios prefijos

	/*!
		\fn ed::Monomio & operator+(ed::Monomio const & m)
		\brief Devuelve una copia del Monomio “m”: +m
		\note ninguna
		\return return *this
		\pre Los monomios m1 y m2 tienen el mismo grado.
		\post El monomio devuelto es igual al monomio “m”, es decir, tiene el mismo
		grado y el mismo coeficiente.
		\sa ed::Monomio & operator-(ed::Monomio const & m)
	*/

	ed::Monomio & operator+(ed::Monomio const & m);

	/*!
		\fn ed::Monomio & operator-(ed::Monomio const & m)
		\brief Devuelve otro monomio que es la resta de dos monomios: m1 – m2
		\note ninguna
		\return return *this
		\pre Los monomios m1 y m2 tienen el mismo grado.
		\post El monomio devuelto tiene el mismo grado que los monomios m1 y m2.
		\post y su coeficiente es la resta de los coeficientes de los monomios m1 y m2.
		\sa ed::Monomio & operator+(ed::Monomio const & m)
	*/
	ed::Monomio & operator-(ed::Monomio const & m);




	//////////////////////////////////////////////////////////

	//! \name Operador binario de la suma 

	/*!
		\fn ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
		\brief Devuelve otro monomio que es la suma de dos monomios: m1 + m2
		\note ninguna
		\return return nuevo
		\pre Los monomios m1 y m2 tienen el mismo grado.
		\post el mismo grado que los monomios m1 y m2,
		\post y su coeficiente es la suma de los coeficientes de los monomio.
		\sa ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2)
	*/
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2);


	//////////////////////////////////////////////////////////
	//! \name Operador binario de la resta 
	/*!
		\fn ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2)
		\brief Devuelve otro monomio que es la resta de dos monomios: m1 – m2
		\note ninguna
		\return return nuevo
		\pre Los monomios m1 y m2 tienen el mismo grado.
		\post El monomio devuelto tiene el mismo grado que los monomios m1 y m2,
		\post y su coeficiente es la resta de los coeficientes de los monomios m1 y m2.
		\sa ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	*/
	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2);

	///////////////////////////////////////////////////////////////////////////
	//! \name Operadores binarios de la multiplicación 

	/*!
		\fn ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2)
		\brief Devuelve otro monomio que es el producto de dos monomios: m1 * m2
		\note ninguna
		\return return nuevo
		\pre ninguna
		\post El monomio devuelto tiene un grado que es la suma de los grados de los
		monomios m1 y m2.
		\post y su coeficiente es el producto de los coeficientes de los monomios m1 y m2.
		\sa ed::Monomio & operator* (ed::Monomio const &m1, double  const &x)
		\sa ed::Monomio & operator* (double const &x, ed::Monomio const &m2)
	*/
	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2);

	/*!
		\fn ed::Monomio & operator* (ed::Monomio const &m1, double  const &x)
		\brief Devuelve otro monomio que es el producto de un monomio por un número real: m * x
		\note ninguna
		\return return nuevo
		\pre ninguna
		\post El monomio devuelto tiene el mismo grado que el monomio “m”,
		\post y su coeficiente es el producto del coeficiente del monomio “m” por el número “x”.
		\sa ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2)
		\sa ed::Monomio & operator* (double const &x, ed::Monomio const &m2)
	*/
	ed::Monomio & operator* (ed::Monomio const &m1, double  const &x);

	/*!
		\fn ed::Monomio & operator* (double const &x, ed::Monomio const &m2)
		\brief Devuelve otro monomio que es el producto de un monomio por un número real: x * m
		\note ninguna
		\return return nuevo
		\pre ninguna
		\post El monomio devuelto tiene el mismo grado que el monomio “m”,
		\post y su coeficiente es el producto del coeficiente del monomio “m” por el número “x”.
		\sa ed::Monomio & operator* (ed::Monomio const &m1, double  const &x)
		\sa ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2)
	*/	
	ed::Monomio & operator* (double const &x, ed::Monomio const &m2);

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división 

	/*!
		\fn ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2)
		\brief Devuelve otro monomio que es la división de dos monomios: m1 / m2
		\note ninguna
		\return return nuevo
		\pre El grado del monomio m2 es menor o igual que el grado del monomio m1.
		\pre El coeficiente del monomio m2 no es 0.0.
		\post El monomio devuelto tiene un grado que es la resta de los grados de los monomios m1 y m2,
		\post y su coeficiente es la división de los coeficientes de los monomios m1 y m2.
		\sa ed::Monomio & operator/ (ed::Monomio const &m1, double const &x)
		\sa ed::Monomio & operator/ (double const &x, ed::Monomio const &m2)
	*/	
	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2);

	/*!
		\fn ed::Monomio & operator/ (ed::Monomio const &m1, double const &x)
		\brief Devuelve otro monomio que es la división del monomio “m” por el número real “x”: m / x
		\note ninguna
		\return return nuevo
		\pre El número “x” no es 0.0.
		\post El monomio devuelto tiene el mismo grado que el monomio “m”,
		\post y su coeficiente es la división del coeficiente del monomio “m” por el número “x”.
		\sa ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2)
	*/	
	ed::Monomio & operator/ (ed::Monomio const &m1, double const &x);

	/*!
		\fn ed::Monomio & operator/ (double const &x, ed::Monomio const &m2)
		\brief Devuelve otro monomio que es la división del número “x” por el monomio “m”: x / m
		\note ninguna
		\return return nuevo
		\pre El grado del monomio es 0 y su coeficiente es distinto de 0.0.
		\post El monomio devuelto tiene grado igual a 0
		\post y su coeficiente es la división del número “x” por el coeficiente del monomio “m”.
		\sa ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2)
		\sa ed::Monomio & operator/ (ed::Monomio const &m1, double const &x)
	*/	
	ed::Monomio & operator/ (double const &x, ed::Monomio const &m2);


	/////////////////////////////////////////////////////////////////////////////

	//! \name Sobrecarga de los operadores de entrada y salida 

	/*!
  	 	\fn istream &operator>>(istream &stream, ed::Monomio &m)
  	 	\brief Lee desde el flujo de entrada los atributos de un monomio separados por espacios
  	 	\attention Función sobrecargada
  		\param objeto: objeto Monomio constante pasado como referencia
  		\return stream
  		\pre Ninguna
  		\post Ninguna
	*/
	 istream &operator>>(istream &stream, ed::Monomio &m);

	/*!
  		\fn ostream &operator<<(ostream &stream, Monomio const &m)
   		\brief Escribe en el flujo de salida los atributos del monomio separados por espacios
   		\attention Función sobrecargada
   		\param objeto: objeto Monomio constante pasado como referencia
   		\return stream
   		\pre Ninguna
   		\post Ninguna
	*/	
	 ostream &operator<<(ostream &stream, ed::Monomio const &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_


