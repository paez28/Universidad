/*! 
	\file operadoresExternosMonomios.hpp
	\brief Ficheros con los prototipos de los operadores externos de la clase Monomio
*/

#ifndef _OperadoresExternosMonomios_HPP_
#define _OperadoresExternosMonomios_HPP_

// Facilita la entrada y salida
#include <iostream>
#include <stdlib.h>
#include "Monomio.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{
	//! \name Operadores de igualdad  

    /**
     * \brief Operador de igualdad
     * \param const ed::Monomio &m1: referencia de un objeto monomio
     * \param const ed::Monomio &m2: referencia de un objeto monomio
     * \retval Booleano (true si son el mismo monomio, false si son distintos monomios)
    */
	bool operator== (const ed::Monomio &m1, const ed::Monomio &m2);

    /**
     * \brief Operador de igualdad
     * \param const ed::Monomio &m: referencia de un objeto monomio
     * \param const double x: coeficiente del monomio
     * \retval Booleano (true si son el mismo monomio, false si son distintos monomios)
    */
	bool operator == (const ed::Monomio &m, const double x);

    /**
     * \brief Operador de igualdad
     * \param const double x: coeficiente del monomio
     * \param const ed::Monomio &m: referencia de un objeto monomio
     * \retval Booleano (true si son el mismo monomio, false si son distintos monomios)
    */
	bool operator == (const double x, const ed::Monomio &m);

	//! \name Operadores de desigualdad 

    /**
     * \brief Operador de igualdad
     * \param const ed::Monomio &m1: referencia de un objeto monomio
     * \param const ed::Monomio &m2: referencia de un objeto monomio
     * \retval Booleano (true si son el distinto monomio, false si son el mismo monomios)
    */
	bool operator!= (const ed::Monomio &m1, const ed::Monomio &m2);

    /**
     * \brief Operador de igualdad
     * \param const ed::Monomio &m: referencia de un objeto monomio
     * \param const double x: coeficiente del monomio
     * \retval Booleano (true si son el distinto monomio, false si son el mismo monomios)
    */
	bool operator != (const ed::Monomio &m, const double x);

    /**
     * \brief Operador de igualdad
     * \param const double x: coeficiente del monomio
     * \param const ed::Monomio &m: referencia de un objeto monomio
     * \retval Booleano (true si son el distinto monomio, false si son el mismo monomios)
    */
	bool operator != (const double x, const ed::Monomio &m);

	//! \name Operadores unarios prefijos

    /**
     * \brief Operador de copia
     * \param const ed::Monomio &m: referencia de un objeto monomio
     * \retval Monomio copiado
    */
	ed::Monomio & operator + (const ed::Monomio &m);

    /**
     * \brief Operador de copia negada
     * \param const ed::Monomio &m: referencia de un objeto monomio
     * \retval Monomio copiado y negado
    */
	ed::Monomio & operator - (const ed::Monomio &m);

	//! \name Operador binario de la suma 

    /**
     * \brief Operador binario de suma
     * \param const ed::Monomio &m1: referencia de un objeto monomio
	 * \param const ed::Monomio &m2: referencia de un objeto monomio
     * \retval Monomio igual a la suma de dos monomios
    */
	 ed::Monomio & operator + (const ed::Monomio &m1, const ed::Monomio &m2);

	//! \name Operador binario de la resta 

    /**
     * \brief Operador binario de resta
     * \param const ed::Monomio &m1: referencia de un objeto monomio
	 * \param const ed::Monomio &m2: referencia de un objeto monomio
     * \retval Monomio igual a la resta de dos monomios
    */
	 ed::Monomio & operator - (const ed::Monomio &m1, const ed::Monomio &m2);

	//! \name Operadores binarios de la multiplicación 

    /**
     * \brief Operador binario de multiplicacion
     * \param const ed::Monomio &m1: referencia de un objeto monomio
	 * \param const ed::Monomio &m2: referencia de un objeto monomio
     * \retval Monomio igual a la multiplicacion de dos monomios
    */
	 ed::Monomio & operator * (const ed::Monomio &m1, const ed::Monomio &m2);

    /**
     * \brief Operador binario de multiplicacion
     * \param const ed::Monomio &m: referencia de un objeto monomio
	 * \param const double x: coeficiente del monomio
     * \retval Monomio igual a la multiplicacion de dos monomios
    */
	 ed::Monomio & operator * (const ed::Monomio &m, const double x);

    /**
     * \brief Operador binario de multiplicacion
     * \param const double x: coeficiente del monomio
     * \param const ed::Monomio &m: referencia de un objeto monomio
     * \retval Monomio igual a la multiplicacion de dos monomios
    */
	 ed::Monomio & operator * (double const x, const ed::Monomio &m);

	//! \name Operadores binarios de la división 

    /**
     * \brief Operador binario de division
     * \param const ed::Monomio &m1: referencia de un objeto monomio
	 * \param const ed::Monomio &m2: referencia de un objeto monomio
     * \retval Monomio igual a la division de dos monomios
    */
	 ed::Monomio & operator / (const ed::Monomio &m1, const ed::Monomio &m2);

    /**
     * \brief Operador binario de division
     * \param const ed::Monomio &m: referencia de un objeto monomio
	 * \param const double x: coeficiente del monomio
     * \retval Monomio igual a la division de dos monomios
    */
	 ed::Monomio & operator / (const ed::Monomio &m, double const x);

    /**
     * \brief Operador binario de division
     * \param const double x: coeficiente del monomio
     * \param const ed::Monomio &m: referencia de un objeto monomio
     * \retval Monomio igual a la division de dos monomios
    */
	 ed::Monomio & operator / (double const x, const ed::Monomio &m);

	//! \name Sobrecarga de los operadores de entrada y salida 

    /**
     * \brief Operador de escritura
     * \param istream &stream: flujo de datos
     * \param ed::Monomio &m: referencia de un objeto monomio
     * \retval Flujo de datos
    */
	 istream & operator >> (istream &stream, ed::Monomio &m);

    /**
     * \brief Operador de lectura
     * \param ostream &stream: flujo de datos
     * \param ed::Monomio &m: referencia de un objeto monomio
     * \retval Flujo de datos
    */
	 ostream & operator << (ostream &stream, const ed::Monomio &m);
}

#endif