/*! 
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed 
{
	// Operadores de igualdad
	
	// COMPLETAR

	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return true;
	}

	bool operator==(ed::Monomio const & m1, double const & x)
	{
		

		
		return true;
	}
	bool operator==(double  const & x, ed::Monomio const & m2)
	{
		

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return true;
	}



	// Operadores de desigualdad

	
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return true;
	}

	bool operator!=(double  const & x, ed::Monomio const & m2)
	{
		

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return true;
	}

	bool operator!=(ed::Monomio const & m1, double const & x)
	{
		

		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return true;
	}


	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos 

	
	ed::Monomio & operator+(ed::Monomio const & m)
	{
		
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();


		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator-(ed::Monomio const & m)
	{
		
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();


		// Se devuelve el resultado
		return *nuevo;
	}




	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
	
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

	
		// Se devuelve el resultado
		return *nuevo;
	}


	////////////
	// Resta

	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2)
	{
	
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

	
		// Se devuelve el resultado
		return *nuevo;
	}


	//////////////////
	// Multiplicación

	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2)
	{
	
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

	
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator* (ed::Monomio const &m1, double const &x)
	{
	
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

	
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator* (double const &x, ed::Monomio const &m2)
	{
	
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

	
		// Se devuelve el resultado
		return *nuevo;
	}


	////////////
	// División
	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
	
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

	
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator/ (ed::Monomio const &m1, double const &x)
	{
	
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

	
		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator/ (double const &x, ed::Monomio const &m2)
	{
	
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

	
		// Se devuelve el resultado
		return *nuevo;
	}
	


	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m) 
	{
		

   		// Se devuelve el flujo de entrada
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m) 
	{
		

		// Se devuelve el flujo de salida
		return stream;
	}


}  // namespace ed
