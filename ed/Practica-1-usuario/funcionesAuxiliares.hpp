/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 1
  \author 
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
      \fn funcion test de la clase monomio
      \brief Funcion que realiza un test a la clase monomio
      \return Ninguno
      \sa operadoresExternosMonomios()
  */
	void testMonomio();


	/*!
      \fn funcion test de la clase operadores Externos
      \brief Funcion que realiza un test a la clase operadoresExternos
      \return Ninguno
      \sa testMonomio()
  */
	void operadoresExternosMonomios();

} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

