/*!
	\file operadoresExternosPolinomios.hpp
	\brief Ficheros con operadores de monomios y polinomios
*/

#ifndef _OperadoresPolinomios_HPP_
#define _OperadoresPolinomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Polinomio.hpp"

using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{
// Funciones y operadores que no pertenecen a la clase Polinomio

//! \name Operadores de igualdad
/**
 * @brief Comprueba si dos polinomios son iguales
 * 
 * @param p1 
 * @param p2 
 * @return true 
 * @return false 
 */
bool operator==(ed::Polinomio const &p1, ed::Polinomio const &p2);
/**
 * @brief Comprueba si un monomio es igual a un polinomio
 * 
 * @param p 
 * @param m 
 * @return true 
 * @return false 
 */
bool operator==(ed::Polinomio const &p, ed::Monomio const &m);
/**
 * @brief Comprueba si un monomio es igual a un polinomio
 * 
 * @param m 
 * @param p 
 * @return true 
 * @return false 
 */
bool operator==(ed::Monomio const &m, ed::Polinomio const &p);
/**
 * @brief Comprueba si un t. independiente es igual a un polinomio
 * 
 * @param p 
 * @param x 
 * @return true 
 * @return false 
 */
bool operator==(ed::Polinomio const &p, double const x);
/**
 * @brief Comprueba si un t. independiente es igual a un polinomio
 * 
 * @param x 
 * @param p 
 * @return true 
 * @return false 
 */
bool operator==(double const x, ed::Polinomio const &p);

//! \name Operadores de desigualdad
/**
 * @brief Comprueba si dos polinomios son distintos
 * 
 * @param p1 
 * @param p2 
 * @return true 
 * @return false 
 */
bool operator!=(ed::Polinomio const &p1, ed::Polinomio const &p2);
/**
 * @brief Comprueba si un monomio es distinto a un polinomio
 * 
 * @param p 
 * @param m 
 * @return true 
 * @return false 
 */
bool operator!=(ed::Polinomio const &p, ed::Monomio const &m);
/**
 * @brief Comprueba si un monomio es distinto a un polinomio
 * 
 * @param m 
 * @param p 
 * @return true 
 * @return false 
 */
bool operator!=(ed::Monomio const &m, ed::Polinomio const &p);
/**
 * @brief Comprueba si un t. independiente es distinto a un polinomio
 * 
 * @param p 
 * @param x 
 * @return true 
 * @return false 
 */
bool operator!=(ed::Polinomio const &p, double const x);
/**
 * @brief Comprueba si un t. independiente es distinto a un polinomio
 * 
 * @param x 
 * @param p 
 * @return true 
 * @return false 
 */
bool operator!=(double const x, ed::Polinomio const &p);

//! \name Operadores unarios
/**
 * @brief Devuelve una copia del polinomio
 * 
 * @param p 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator+(ed::Polinomio const &p);
/**
 * @brief Devuelve una copia del polinomio opuesto
 * 
 * @param p 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator-(ed::Polinomio const &p);

//! \name Operadores binarios de la suma
/**
 * @brief Suma de dos polinomios
 * 
 * @param p1 
 * @param p2 
 * @return ed::Polinomio& 
*/
ed::Polinomio &operator+(ed::Polinomio const &p1, ed::Polinomio const &p2);
/**
 * @brief Suma de un monomio a un polinomio
 * 
 * @param p 
 * @param m 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator+(ed::Polinomio const &p, ed::Monomio const &m);
/**
 * @brief Suma de un monomio a un polinomio
 * 
 * @param m 
 * @param p 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator+(ed::Monomio const &m, ed::Polinomio const &p);
/**
 * @brief Suma de un t. independiente a un polinomio
 * 
 * @param p 
 * @param x 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator+(ed::Polinomio const &p, double const x);
/**
 * @brief Suma de un t. independiente a un polinomio
 * 
 * @param x 
 * @param p 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator+(double const x, ed::Polinomio const &p);

//! \name Operador binario de la resta
/**
 * @brief Resta de dos polinomios
 * 
 * @param p1 
 * @param p2 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator-(ed::Polinomio const &p1, ed::Polinomio const &p2);
/**
 * @brief Resta de un monomio a un polinomio
 * 
 * @param p 
 * @param m 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator-(ed::Polinomio const &p, ed::Monomio const &m);
/**
 * @brief Resta de un monomio a un polinomio
 * 
 * @param m 
 * @param p 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator-(ed::Monomio const &m, ed::Polinomio const &p);
/**
 * @brief Resta de un t. independiente a un polinomio
 * 
 * @param p 
 * @param x 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator-(ed::Polinomio const &p, double const x);
/**
 * @brief Resta de un t. independiente a un polinomio
 * 
 * @param x 
 * @param p 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator-(double const x, ed::Polinomio const &p);

//! \name Operadores binarios de la multiplicación
/**
 * @brief Multiplicacion de dos polinomio
 * 
 * @param p1 
 * @param p2 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator*(ed::Polinomio const &p1, ed::Polinomio const &p2);
/**
 * @brief Multiplicacion de un monomio por un polinomio
 * 
 * @param p 
 * @param m 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator*(ed::Polinomio const &p, ed::Monomio const &m);
/**
 * @brief Multiplicacion de un monomio por un polinomio
 * 
 * @param m 
 * @param p 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator*(ed::Monomio const &m, ed::Polinomio const &p);
/**
 * @brief Multiplicacion de un t. independiente por un polinomio
 * 
 * @param p 
 * @param x 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator*(ed::Polinomio const &p, double const x);
/**
 * @brief Multiplicacion de un t. independiente por un polinomio
 * 
 * @param x 
 * @param p 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator*(double const x, ed::Polinomio const &p);

//! \name Operadores binarios de la división
/**
 * @brief Divisopn de dos polinomios
 * 
 * @param p1 
 * @param p2 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator/(ed::Polinomio const &p1, ed::Polinomio const &p2);
/**
 * @brief Division de un polinomio por un monomio
 * 
 * @param p 
 * @param m 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator/(ed::Polinomio const &p, ed::Monomio const &m);
/**
 * @brief Division de un polinomio por un monomio
 * 
 * @param m 
 * @param p 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator/(ed::Monomio const &m, ed::Polinomio const &p);
/**
 * @brief Division de un polinomio por un t. independiente
 * 
 * @param p 
 * @param x 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator/(ed::Polinomio const &p, double const x);
/**
 * @brief Division de un polinomio por un t. independiente
 * 
 * @param x 
 * @param p 
 * @return ed::Polinomio& 
 */
ed::Polinomio &operator/(double const x, ed::Polinomio const &p);

//! \name Sobrecarga de los operadores de flujo de la clase Polinomio.
/**
 * @brief Carga de un flujo desde un polinomio
 * 
 * @param stream 
 * @param p 
 * @return ostream& 
 */
ostream &operator<<(ostream &stream, ed::Polinomio const &p);
/**
 * @brief Carga de un polinomio desde un flujo
 * 
 * @param stream 
 * @param p 
 * @return istream& 
 */
istream &operator>>(istream &stream, ed::Polinomio &p);

} // namespace ed

#endif // _OperadoresPolinomios_HPP_
