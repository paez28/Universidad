/*!
   \file operadoresExternosPolinomios.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/

// Ficheros de cabecera
#include <iostream>
#include <string>
#include <stdlib.h>

#include "Polinomio.hpp"
#include "Monomio.hpp"
#include "operadoresExternosPolinomios.hpp"
#include "operadoresExternosMonomios.hpp"

// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed
{

// Operadores de igualdad

bool operator==(ed::Polinomio const &p1, ed::Polinomio const &p2)
{
	int mayorGrado = 0;
	if (p1.getGrado() > p2.getGrado())
		mayorGrado = p1.getGrado();
	else
		mayorGrado = p2.getGrado();

	if (p1.getNumeroMonomios() != p2.getNumeroMonomios())
		return false;
	if (p1.getGrado() != p2.getGrado())
		return false;

	for (int i = 0; i < mayorGrado; i++)
		if (p1.existeMonomio(i) && !p2.existeMonomio(i))
			return false;

	for (int i = 0; i < mayorGrado; i++)
		if (!p1.existeMonomio(i) && p2.existeMonomio(i))
			return false;

	for (int i = 0; i < p1.getGrado(); i++)
		if (p1.existeMonomio(i) && p2.existeMonomio(i))
			if (p1.getMonomio(i) != p2.getMonomio(i))
				return false;

	return true;
}

bool operator==(ed::Polinomio const &p, ed::Monomio const &m)
{
	if (p.getNumeroMonomios() != 1)
		return false;

	if (p.getGrado() != m.getGrado())
		return false;

	if (p.getMonomio(m.getGrado()) == m)
		return true;
	
	return false;
}
	
bool operator==(ed::Monomio const &m, ed::Polinomio const &p)
{
	if (p.getNumeroMonomios() != 1)
		return false;

	if (p.getGrado() != m.getGrado())
		return false;

	if (p.getMonomio(m.getGrado()) == m)
		return true;
	
	return false;
}

bool operator==(ed::Polinomio const &p, double const x)
{
	ed::Monomio m(x);
	return (p == m);
}

bool operator==(double const x, ed::Polinomio const &p)
{
	ed::Monomio m(x);
	return (p == m);
}

// Operadores de desigualdad

bool operator!=(ed::Polinomio const &p1, ed::Polinomio const &p2)
{
	return !(p1 == p2);
}

bool operator!=(ed::Polinomio const &p, ed::Monomio const &m)
{
	return !(p == m);
}

bool operator!=(ed::Monomio const &m, ed::Polinomio const &p)
{
	return !(p == m);
}

bool operator!=(ed::Polinomio const &p, double const x)
{
	return !(p == x);
}

bool operator!=(double const x, ed::Polinomio const &p)
{
	return !(p == x);
}

// Operadores unarios

ed::Polinomio &operator+(ed::Polinomio const &p)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);
	return *nuevo;
}

ed::Polinomio &operator-(ed::Polinomio const &p)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);
	*nuevo *= (-1);
	return *nuevo;
}

// Operadores binarios de la suma

ed::Polinomio &operator+(ed::Polinomio const &p1, ed::Polinomio const &p2)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p1);

	*nuevo += p2;
	return *nuevo;
}

ed::Polinomio &operator+(ed::Polinomio const &p, ed::Monomio const &m)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);

	*nuevo += m;
	return *nuevo;
}

ed::Polinomio &operator+(ed::Monomio const &m, ed::Polinomio const &p)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);
	*nuevo += m;
	return *nuevo;
}

ed::Polinomio &operator+(ed::Polinomio const &p, double const x)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);
	*nuevo += x;
	return *nuevo;
}

ed::Polinomio &operator+(double const x, ed::Polinomio const &p)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);
	*nuevo += x;
	return *nuevo;
}

// Resta

ed::Polinomio &operator-(ed::Polinomio const &p1, ed::Polinomio const &p2)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p1);

	*nuevo -= p2;
	return *nuevo;
}

ed::Polinomio &operator-(ed::Polinomio const &p, ed::Monomio const &m)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);

	*nuevo -= m;
	return *nuevo;
}

ed::Polinomio &operator-(ed::Monomio const &m, ed::Polinomio const &p)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);
	*nuevo -= m;
	return *nuevo;
}
ed::Polinomio &operator-(ed::Polinomio const &p, double const x)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);
	*nuevo -= x;
	return *nuevo;
}

ed::Polinomio &operator-(double const x, ed::Polinomio const &p)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);
	*nuevo -= x;
	return *nuevo;
}

// Multiplicación

ed::Polinomio &operator*(ed::Polinomio const &p1, ed::Polinomio const &p2)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p1);
	*nuevo *= p2;
	return *nuevo;
}

ed::Polinomio &operator*(ed::Polinomio const &p, ed::Monomio const &m)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);
	*nuevo *= m;
	return *nuevo;
}

ed::Polinomio &operator*(ed::Monomio const &m, ed::Polinomio const &p)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);
	*nuevo *= m;
	return *nuevo;
}

ed::Polinomio &operator*(ed::Polinomio const &p, double const x)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);
	*nuevo *= x;
	return *nuevo;
}

ed::Polinomio &operator*(double const x, ed::Polinomio const &p)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);
	*nuevo *= x;
	return *nuevo;
}

// División

ed::Polinomio &operator/(ed::Polinomio const &p1, ed::Polinomio const &p2)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p1);
	*nuevo /= p2;
	return *nuevo;

}

ed::Polinomio &operator/(ed::Polinomio const &p, ed::Monomio const &m)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);
	*nuevo /= m;
	return *nuevo;
}

ed::Polinomio &operator/(ed::Monomio const &m, ed::Polinomio const &p)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);
	*nuevo /= m;
	return *nuevo;
}

ed::Polinomio &operator/(ed::Polinomio const &p, double const x)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);
	*nuevo /= x;
	return *nuevo;
}

ed::Polinomio &operator/(double const x, ed::Polinomio const &p)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);
	*nuevo /= x;
	return *nuevo;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, Polinomio &p)
{
	Monomio aux;

	char opcion = 's';
	while (opcion == 's')
	{
		stream >> aux;
		p.anadirMonomio(aux);
		std::cout << "Desea anadir otro monomio mas al polinomio? [s/n]: ";
		std::cin >> opcion;
	}
	return stream;
}

// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, Polinomio const &p)
{
	stream << p.getMonomio(p.getGrado());
	for (int i = p.getGrado() - 1; i >= 0; i--)
	{
		if (p.existeMonomio(i))
		{
			if (p.getMonomio(i).getCoeficiente() >= 0) // if (i - 1 >= 0)
				stream << "+";
			stream << p.getMonomio(i);
		}
	}
	return stream;
}

} // namespace ed
