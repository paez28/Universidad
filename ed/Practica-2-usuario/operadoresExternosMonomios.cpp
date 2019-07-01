/*! 
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/

//  Ficheros de cabecera
#include <iostream>
#include "operadoresExternosMonomios.hpp"
#include <string>

// Espacios de nombres
using std::string;
using std::endl;

// Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed
{
	// Operadores de igualdad

	bool operator == (const ed::Monomio &m1, const ed::Monomio &m2) {
		if ( (m1.getGrado() == m2.getGrado()) && ( (m1.getCoeficiente() - m2.getCoeficiente() ) < COTA_ERROR) ) return true;
		else return false;
	}

	bool operator == (const ed::Monomio &m, const double x) {
		if ( (m.getGrado() == 0) && ( (m.getCoeficiente() - x) < COTA_ERROR) ) return true;
		else return false;
	}

	bool operator == (const double x, const ed::Monomio &m) {
		if ( (m.getGrado() == 0) && ( (m.getCoeficiente() - x) < COTA_ERROR) ) return true;
		else return false;
	}

	// Operadores de desigualdad

	bool operator != (const ed::Monomio &m1, const ed::Monomio &m2) {
		return (!(m1==m2));
	}

	bool operator != (const ed::Monomio &m, const double x) {
		return (!(m==x));
	}

	bool operator != (const double x, const ed::Monomio &m) {
		return (!(x==m));
	}

	// Operadores unarios prefijos

	//  Operador de suma
	ed::Monomio & operator + (const ed::Monomio &m) {
		ed::Monomio *nuevo = new ed::Monomio (m);

		return *nuevo;
	}

	//  Operador de resta
	ed::Monomio & operator - (const ed::Monomio &m) {
		ed::Monomio *nuevo = new ed::Monomio (m);
		nuevo -> setCoeficiente (-1 * (nuevo -> getCoeficiente()) );

		return *nuevo;
	}

	// Operadores aritméticos binarios
	
	//  Operador de suma
	ed::Monomio & operator + (const ed::Monomio &m1, const ed::Monomio &m2) {
		assert (m1.getGrado() == m2.getGrado());

		ed::Monomio *nuevo = new ed::Monomio (m1);
		nuevo -> setCoeficiente (nuevo->getCoeficiente() + m2.getCoeficiente());

		return *nuevo;
	}

	//  Operador de resta
	ed::Monomio & operator - (const ed::Monomio &m1, const ed::Monomio &m2) {
		assert (m1.getGrado() == m2.getGrado());

		ed::Monomio *nuevo = new ed::Monomio (m1);
		nuevo -> setCoeficiente (nuevo->getCoeficiente() - m2.getCoeficiente());

		return *nuevo;
	}

	//  Operadores de multiplicacion

	ed::Monomio & operator * (const ed::Monomio &m1, const ed::Monomio &m2) {
		ed::Monomio *nuevo = new ed::Monomio (m1);
		nuevo -> setCoeficiente (nuevo->getCoeficiente() * m2.getCoeficiente());
		nuevo -> setGrado (nuevo->getGrado() + m2.getGrado());

		return *nuevo;
	}

	ed::Monomio & operator * (const ed::Monomio &m, double const x) {
		ed::Monomio *nuevo = new ed::Monomio (m);
		nuevo -> setCoeficiente (nuevo->getCoeficiente() * x);

		return *nuevo;
	}

	ed::Monomio & operator * (double const x, const ed::Monomio &m) {
		ed::Monomio *nuevo = new ed::Monomio (m);
		nuevo -> setCoeficiente (nuevo->getCoeficiente() * x);

		return *nuevo;
	}

	//  Operadores de division

	ed::Monomio & operator / (const ed::Monomio &m1, const ed::Monomio &m2) {
		assert (m1.getGrado () >= m2.getGrado ());
		assert (m2.getCoeficiente() != 0.0);

		ed::Monomio *nuevo = new ed::Monomio (m1);
		nuevo -> setCoeficiente (nuevo->getCoeficiente() / m2.getCoeficiente());
		nuevo -> setGrado (nuevo->getGrado() - m2.getGrado());

		return *nuevo;
	}

	ed::Monomio & operator / (const ed::Monomio &m, double const x) {
		assert (x != 0.0);

		ed::Monomio *nuevo = new ed::Monomio (m);
		nuevo -> setCoeficiente (nuevo->getCoeficiente() / x);

		return *nuevo;
	}

	ed::Monomio & operator / (double const x, const ed::Monomio &m) {
		assert (m.getGrado() == 0);
		assert (m.getCoeficiente() != 0.0);

		ed::Monomio *nuevo = new ed::Monomio (m);
		nuevo -> setCoeficiente (x / nuevo->getCoeficiente());

		return *nuevo;
	}

	// Operadores adicionales

	//  Sobrecarga del operador de entrada
	istream & operator >> (istream &stream, ed::Monomio &m) {
	double coeficiente;
	int grado;
	stream >> coeficiente;
	stream >> grado;
	m.setCoeficiente(coeficiente);
	m.setGrado(grado);
	return stream;
	/*
	string aux;
	getline (stream, aux, ' ');
	m.setCoeficiente (atof (aux.c_str()));
	getline (stream, aux, '\n');
	m.setGrado (atoi (aux.c_str()));

	return stream;
*/
	}

	//  Sobrecarga del operador de salida
	ostream & operator<< (ostream &stream, ed::Monomio const &m) {
		if (m.getGrado() == 0) {
			stream << m.getCoeficiente();
			return stream;
		}
		if (m.getCoeficiente() == -1) {
			stream << "-X";
		} else if (m.getCoeficiente() == 1) {
			stream << "X";
		} else {
			stream << m.getCoeficiente() << "X";
		}
		if (m.getGrado() > 1) {
			stream << "^" << m.getGrado();
		}

		return stream;
	}

}