/*!
	\file Monomio.hpp
	\brief Definición de la clase Monomio
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
namespace ed
{
//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$
class Monomio
{
	//! \name Atributos privados de la clase Monomio
	private:

	// COMPLETAR
	int grado_; //!< Grado del monomio
	double coeficiente_; //!< Coeficiente del monomio

	//! \name Funciones o métodos públicos de la clase Monomio
	public:

	//! \name Constructores de la clase Monomio

	/*!
			\fn inline Monomio
			\brief Constructor que crea un Monomio nulo
			\attention Funcion sobrecargada
			\note Funcion inline
			\pre el grado no puede ser negativo
			\post El grado tiene que ser el mismo del coeficiente
			\post El grado del monomio de be tener el mismo valor del parametro grado
			\sa  setCoeficiente(), setGrado()
	*/
	inline Monomio(double coeficiente = 0.0, int grado = 0)
	{
			//Se comprueba la precondicion
			#ifndef NDEBUG
			assert(grado >= 0);
			#endif //NDEBUG

			this->setCoeficiente(coeficiente);
			this->setGrado(grado);

			//Se comprueban la postcondiciones
			#ifndef NDEBUG
			assert(std::abs(this->getCoeficiente() - coeficiente) < COTA_ERROR);
			assert(this->getGrado() == grado);
			#endif //NDEBUG

	}
	//! \name Constructores de la clase Monomio
	/*!
	\brief     Constructor de "copia" que crea un Grado a partir de otro Grado
	\attention Funcionn sobrecargada
	\note      Funcion inline
	\param     m : Nuevo valor del monomio
	\pre       Ninguna
	\post	   La abscisa del Grado debe tener el valor de la abscisa del Grado v
	\post	   La ordenada del Grado debe tener el valor de la ordenada del Grado v
	\note	   Se debe utilizar COTA_ERROR para controlar la precisionn de los numeros reales
	\sa
	*/
	inline Monomio(Monomio const &m)
	{
		this->setCoeficiente(m.getCoeficiente());
		this->setGrado(m.getGrado());

		#ifndef NDEBUG
		assert(std::abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
		assert(std::abs(this->getGrado() - m.getGrado()) < COTA_ERROR);
		#endif //NDEBUG
	}

	//! \name Observadores: funciones de consulta de la clase Monomio
	/*!
      \fn inline double getCoeficiente()const
      \brief Funcion que devuelveel coeficiente
      \note Funcion inline
      \return Componente coefiente_ atributo
      \pre Ninguna
      \post Ninguna
      \sa getGrado()
  */
	inline double getCoeficiente()const {return coeficiente_;}

	/*!
      \fn inline int getGrado()
      \brief Funcion que devuelve el grado
      \note Funcion inline
      \return Componente grado_ atributo
      \pre Ninguna
      \post Ninguna
      \sa getGrado()
  */
	inline int getGrado()const {return grado_;}



	//! \name Funciones de modificación de la clase Monomio
	/*!
			\fn inline int setGrado()
			\brief Funcion que asigna el grado
			\note Funcion inline
			\return Componente grado_ y el atributo por referencia
			\pre El número entero “n” es mayor o igual que 0.
			\post El grado del monomio es igual al número entero “n”.
			\sa setGrado()
	*/
	inline void setGrado(int g)
	{
		#ifndef NDEBUG
		assert( g >= 0);
		#endif //NDEBUG
		grado_=g;
		#ifndef NDEBUG
		assert( getGrado() == g);
		#endif //NDEBUG
	}
	/*!
			\fn inline int setCoeficiente()
			\brief Funcion que asigna el coefiente
			\note Funcion inline
			\return Componente coefiente_ y el atributo por referencia
			\pre ninguna
			\post El coeficiente del monomio es igual al número real “x”.
			\sa setCoeficiente()
	*/
	inline void setCoeficiente(double c)
	{
		coeficiente_ = c;
		#ifndef NDEBUG
		assert(std::abs(getCoeficiente() - c) < COTA_ERROR);
		#endif //NDEBUG

	}


	/////////////////////////////////////////////////

	//! \name Operadores de la clase Monomio


	// Operadores de asignación

	/*!
			\fn operador =
			\brief operador que devuelve el monomio actual con atributos
			\note ninguna
			\return return *this
			\pre ninguna
			\post El coeficiente del monomio es igual al coeficiente del monomio “m"
			\post El coeficiente del monomio es igual al coeficiente del monomio “m"
			\sa operador=
	*/
		Monomio & operator=(Monomio const &m);

		/*!
				\fn operador =
				\brief operador que devuelve el monomio actual con atributos de grado 0
				\note ninguna
				\return return *this
				\pre ninguna
				\post El grado del monomio es igual 0.
				\post El coeficiente del monomio es igual al número real “x”.
				\sa operador=
		*/
		Monomio & operator=(double const &x);


	// Operadores aritméticos y asignación

	/*!
			\fn operador+=
			\brief Modifica el monomio sumandole otro monomio de igual grado
			\note ninguna
			\return return *this
			\pre El monomio “m” tiene el mismo grado que el monomio actual.
			\post El coeficiente del monomio actual se ha incrementado con el coeficiente
			del monomio “m”.
			\post El grado del monomio actual no ha sido modificado.
			\sa operador-=
			\sa operador*=
			\sa operador/=
	*/
		Monomio & operator+=(Monomio const &m);

		/*!
				\fn operador-=
				\brief Modifica el monomio restandole otro monomio de igual grado
				\note ninguna
				\return return *this
				\pre El monomio “m” tiene el mismo grado que el monomio actual.
				\post El coeficiente del monomio actual se ha decrementado con el coeficiente
				del monomio “m”.
				\post El grado del monomio actual no ha sido modificado.
				\sa operador-=
				\sa operador*=
				\sa operador/=
		*/
		Monomio & operator-=(Monomio const &m);

		Monomio & operator*=(Monomio const &m);

		Monomio & operator/=(Monomio const &m);

		Monomio & operator*=(Monomio const &m);

		Monomio & operator/=(Monomio const &m);
		// COMPLETAR EL RESTO DE OPERADORES


	/////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Monomio

	/*!
		 \fn void leerMonomio()
		 \brief Funcion que lee del teclado las componentes de un monomio
		 \return Nada
		 \pre Ninguna
		 \post Ninguna
		 \sa escribirMonomio()
	 */
	void leerMonomio();

	/*!
		 \fn void escribirMonomio()
		 \brief Funcion que escribe del teclado las componentes de un monomio
		 \return Nada
		 \pre Ninguna
		 \post Ninguna
		 \sa leerMonomio()
	 */
	void escribirMonomio();


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Monomio

	// COMPLETAR



};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
