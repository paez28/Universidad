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

// Para usar la función abs
#include <cmath>

#include "PolinomioInterfaz.hpp"
#include "Monomio.hpp"

// Espacios de nombre
using std::vector;

// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed
{

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio : public ed::PolinomioInterfaz
{

	//! \name Atributos privados de la clase Polinomio
  private:
	vector<Monomio> monomios_;

	//! \name Funciones o métodos públicos de la clase Polinomio
  public:
	//! \name Constructores de la clase Polinomio
	Polinomio();
	Polinomio(const Polinomio &polinomio);
	// Polinomio(const Monomio &monomio);

	//! \name Observadores: funciones de consulta de la clase Polinomio
	bool esNulo() const;
	int getGrado() const;
	int getGradoReal() const;
	int getNumeroMonomios() const;
	bool existeMonomio(int grado) const;
	ed::Monomio &getMonomio(int grado) const;

	//! \name Funciones de modificación de la clase Polinomio

	//! \name Operadores de la clase Polinomio
	/**
	 * @brief Asignacion de un polinomio a un polinomio
	 * 
	 * @param p 
	 * @return Polinomio& 
	 */
	Polinomio &operator=(Polinomio const &p);
	/**
	 * @brief Asignacion de un monomio a un polinomio
	 * 
	 * @param m 
	 * @return Polinomio& 
	 */
	Polinomio &operator=(Monomio const &m);
	/**
	 * @brief Asignacion de un t. independiente a un polinomio
	 * 
	 * @param x 
	 * @return Polinomio& 
	 */
	Polinomio &operator=(double const &x);

	// Operadores aritméticos y asignación
	/**
	 * @brief Suma de dos polinomios
	 * 
	 * @param p 
	 * @return Polinomio& 
	 */
	Polinomio &operator+=(Polinomio const &p);
	/**
	 * @brief Suma de un monomio a un polinomio
	 * 
	 * @param m 
	 * @return Polinomio& 
	 */
	Polinomio &operator+=(Monomio const &m);
	/**
	 * @brief Suma de un t. independiente a un polinomio
	 * 
	 * @param x 
	 * @return Polinomio& 
	 */
	Polinomio &operator+=(double const &x);
	/**
	 * @brief Resta de dos polinomios
	 * 
	 * @param p 
	 * @return Polinomio& 
	 */
	Polinomio &operator-=(Polinomio const &p);
	/**
	 * @brief Resta de un monomio a un polinomio
	 * 
	 * @param m 
	 * @return Polinomio& 
	 */
	Polinomio &operator-=(Monomio const &m);
	/**
	 * @brief Resta de un t. independiente a un polinomio
	 * 
	 * @param x 
	 * @return Polinomio& 
	 */
	Polinomio &operator-=(double const &x);
	/**
	 * @brief Multiplicacion de dos polinomios
	 * 
	 * @param p 
	 * @return Polinomio& 
	 */
	Polinomio &operator*=(Polinomio const &p);
	/**
	 * @brief Multiplicacion de un monomio por un polinomio
	 * 
	 * @param m 
	 * @return Polinomio& 
	 */
	Polinomio &operator*=(Monomio const &m);
	/**
	 * @brief Multiplicacion de un t. independiente por un polinomio
	 * 
	 * @param x 
	 * @return Polinomio& 
	 */
	Polinomio &operator*=(double const &x);
	/**
	 * @brief Division de dos polinomios
	 * 
	 * @param p 
	 * @return Polinomio& 
	 */
	Polinomio &operator/=(Polinomio const &p);
	/**
	 * @brief Division de un polinomio por un monomio
	 * 
	 * @param m 
	 * @return Polinomio& 
	 */
	Polinomio &operator/=(Monomio const &m);
	/**
	 * @brief Division de un polinomio por un t. independiente
	 * 
	 * @param x 
	 * @return Polinomio& 
	 */
	Polinomio &operator/=(double const &x);

	//! \name Funciones lectura y escritura de la clase Polinomio
	/**
	 * @brief Lectura de un monomio
	 * 
	 */
	void leerPolinomio();
	/**
	 * @brief Escritura de un monomio
	 * 
	 */
	void escribirPolinomio();

	//! \name Funciones auxiliares de la clase Polinomio
	/**
	 * @brief Calculo de una funcion polinomial
	 * 
	 * @param x 
	 * @return double 
	 */
	double calcularValor(double const x);
	/**
	 * @brief Adicion de un monomio al polinomio
	 * 
	 * @param m 
	 */
	void anadirMonomio(Monomio const &m);
	/**
	 * @brief Retorna el objeto polinomio
	 * 
	 * @return std::vector <ed::Monomio> 
	 */
	std::vector<ed::Monomio> getPolinomio() const;

}; // Fin de la definición de la clase Polinomio

} // namespace ed

//  _POLINOMIO_HPP_
#endif
