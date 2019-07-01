/*!
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


// Ficheros de cabecera
#include <iostream>
#include <string>

#include "Monomio.hpp"

// Herramientas del espacio de nombres std
using std::string;
using std::cout;
using std::endl;
using std::cin;

// Constructores

ed::Monomio::Monomio (double coeficiente, int grado) {
	assert (grado >= 0);

	this->setCoeficiente (coeficiente);
	this->setGrado (grado);
}

ed::Monomio::Monomio (const Monomio &monomio) {
	(*this) = monomio;
}

// Modificadores

void ed::Monomio::setCoeficiente (const double coeficiente) {
	coeficiente_ = coeficiente;
}

void ed::Monomio::setGrado (const int grado) {
	assert (grado >= 0);

	grado_ = grado;
}

// Operadores de asignación

ed::Monomio & ed::Monomio::operator = (ed::Monomio const &m) {
    this->setCoeficiente (m.getCoeficiente ());
    this->setGrado (m.getGrado ());

	return *this;
}


ed::Monomio & ed::Monomio::operator = (double const &x) {
    this->setCoeficiente (x);
    this->setGrado (0);

	return *this;
}

// Operadores aritméticos y asignación

ed::Monomio & ed::Monomio::operator += (ed::Monomio const &m) {
    assert (this->getGrado() == m.getGrado());

    this->setCoeficiente (this->getCoeficiente() + m.getCoeficiente());

	return *this;
}

ed::Monomio & ed::Monomio::operator -= (ed::Monomio const &m) {
    assert (this->getGrado() == m.getGrado());

    this->setCoeficiente (this->getCoeficiente() - m.getCoeficiente());

    return *this;
}

ed::Monomio & ed::Monomio::operator *= (ed::Monomio const &m) {
    this->setCoeficiente (this->getCoeficiente() * m.getCoeficiente());
    this->setGrado (this->getGrado() + m.getGrado());

    return *this;
}

ed::Monomio & ed::Monomio::operator /= (ed::Monomio const &m) {
    assert (this->getGrado() >= m.getGrado());
    assert (this->getCoeficiente() != 0.0);

    this->setCoeficiente (this->getCoeficiente() / m.getCoeficiente());
    this->setGrado (this->getGrado() - m.getGrado());

    return *this;
}

ed::Monomio & ed::Monomio::operator *= (const double x) {
    this->setCoeficiente (this->getCoeficiente() * x);

    return *this;
}

ed::Monomio & ed::Monomio::operator /= (const double x) {
    assert (x != 0.0);
    this->setCoeficiente (this->getCoeficiente() * x);

    return *this;
}

// Funciones lectura y escritura de la clase Monomio

void ed::Monomio::leerMonomio () {
    double coeficiente;
    int grado;

    cout << "Introduzca los datos del monomio" << endl;
    cout << "Coeficiente: ";
    cin >> coeficiente;
    cout << "Grado: ";
    cin >> grado;

    assert (grado >= 0);

    this->setCoeficiente (coeficiente);
    this->setGrado (grado);
}

void ed::Monomio::escribirMonomio () {
    if (this->getGrado() == 0) {
        cout << this->getCoeficiente();
        return;
    }
    if (this->getCoeficiente() == -1) {
        cout << "-X";
    } else if (this->getCoeficiente() == 1) {
        cout << "X";
    } else {
        cout << this->getCoeficiente() << "X";
    }
    if (this->getGrado() > 1) {
    	cout << "^" << this->getGrado();
    }
}

// Funciones auxiliares de la clase Monomio

double ed::Monomio::calcularValor (double x) {
	return (this->getCoeficiente() * pow (x, this->getGrado()));
}
