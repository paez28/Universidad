/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 1
  \author Martin Paez Anguita
  \date
*/


#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

namespace ed
{
	/*!
		\brief   Muestra el menú del programa principal
		\return  Devuelve el número de opción elegido
	*/
	int menu();

	/*!
      \fn void testMonomio()
      \brief Funcion que realiza un test a la clase monomio
      \return Ninguno
      \sa operadoresExternosMonomios()
  */
	void testMonomio();


	/*!
      \fn void operadoresExternosMonomios()
      \brief Funcion que realiza un test a la clase operadoresExternos
      \return Ninguno
      \sa testMonomio()
  */
	void operadoresExternosMonomios();

} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif
