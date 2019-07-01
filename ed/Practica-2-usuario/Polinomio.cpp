/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/

// Ficheros de cabecera
#include <iostream>

#include "Polinomio.hpp"
#include "Monomio.hpp"
#include "operadoresExternosMonomios.hpp"
#include "operadoresExternosPolinomios.hpp"

using std::cin;
using std::cout;

// Constructores

ed::Polinomio::Polinomio()
{
}

ed::Polinomio::Polinomio(const Polinomio &polinomio)
{
	this->monomios_=polinomio.monomios_;
}

// Observadores

bool ed::Polinomio::esNulo() const
{
	if (this->monomios_.empty())
		return true;
	return false;
}

int ed::Polinomio::getGrado() const
{
	if (this->esNulo())
		return 0;
	else
		return this->monomios_.front().getGrado();
}

int ed::Polinomio::getNumeroMonomios() const
{
	return this->monomios_.size();
}

bool ed::Polinomio::existeMonomio(int grado) const
{
	for (int i = 0; i < this->getNumeroMonomios(); i++)
		if (this->monomios_[i].getGrado() == grado)
			return true;
	return false;
}

ed::Monomio &ed::Polinomio::getMonomio(int grado) const
{
	for (int i = 0; i < getNumeroMonomios(); i++)
		if (this->monomios_[i].getGrado() == grado)
			return *new ed::Monomio(this->monomios_[i]);
	return *new ed::Monomio;
}

// Operadores de asignación

ed::Polinomio &ed::Polinomio::operator=(ed::Polinomio const &p)
{
	this->monomios_.clear();
	for(int i=0; i < p.getNumeroMonomios();i++){
		this->anadirMonomio(p.monomios_[i]);
	}
	return *this;
}

ed::Polinomio &ed::Polinomio::operator=(ed::Monomio const &m)
{
	this->monomios_.clear();
	this->anadirMonomio(m);
	return *this;
}

ed::Polinomio &ed::Polinomio::operator=(double const &x)
{
	this->monomios_.clear();
	ed::Monomio m(x);
	this->anadirMonomio(m);
	return *this;
}

ed::Polinomio &ed::Polinomio::operator+=(ed::Polinomio const &p)
{
	for(int i=0; i < p.getNumeroMonomios();i++){
		this->anadirMonomio(p.monomios_[i]);
	}
	return *this;
}

ed::Polinomio &ed::Polinomio::operator+=(ed::Monomio const &m)
{
	this->anadirMonomio(m);
	return *this;

}

ed::Polinomio &ed::Polinomio::operator+=(double const &x)
{
	ed::Monomio m(x);
	this->anadirMonomio(m);
	return *this;
}

ed::Polinomio &ed::Polinomio::operator-=(ed::Polinomio const &p)
{	
	for(int i=0;i < p.getNumeroMonomios();i++){
		this->anadirMonomio(p.monomios_[i]);

	}
	return *this;
	
}

ed::Polinomio &ed::Polinomio::operator-=(ed::Monomio const &m)
{
	this->anadirMonomio(m);
	return *this;
}

ed::Polinomio &ed::Polinomio::operator-=(double const &x)
{
	ed::Monomio m(x);
	this->anadirMonomio(m);
	return *this;
}

ed::Polinomio &ed::Polinomio::operator*=(ed::Polinomio const &p)
{
	ed::Polinomio aux(*this);
	ed::Polinomio result;

	for(int i=0; i <p.getNumeroMonomios();i++){
		aux *= p.monomios_[i];
		result += aux;
		aux = *this;
	}
	*this = result;
	return *this;
}

ed::Polinomio &ed::Polinomio::operator*=(ed::Monomio const &m)
{
	for(int i=0;i <this->getNumeroMonomios();i++){
		this->monomios_[i]*=m;
	}
	return *this;
}

ed::Polinomio &ed::Polinomio::operator*=(double const &x)
{
	for(int i=0;i <this->getNumeroMonomios();i++){
		this->monomios_[i]*=x;
	}
	return *this;
}

ed::Polinomio &ed::Polinomio::operator/=(ed::Polinomio const &p)
{
	ed::Polinomio aux;
	Polinomio dividiendo(*(this));
	Polinomio divisor(p);
	Monomio cociente;
	this->monomios_.clear();
	if(dividiendo.getGrado() < divisor.getGrado()){
		this->monomios_.clear();
		this->anadirMonomio(cociente);
		return *this;
	}

	while(dividiendo.getGrado() > divisor.getGrado()){
		cociente = dividiendo.getMonomio(dividiendo.getGrado())/
		divisor.getMonomio(divisor.getGrado());
		dividiendo -= divisor * cociente;
		aux.anadirMonomio(cociente);

		if(dividiendo.monomios_.empty()){
			ed::Monomio aux;
			dividiendo.monomios_.push_back(aux);
		}
	}
	*(this) = aux;
	return *this;
}

ed::Polinomio &ed::Polinomio::operator/=(ed::Monomio const &m)
{
	for(int i=0;i < this->getNumeroMonomios();i++){
		this->monomios_[i] /=m;

	}
	return *this;
}

ed::Polinomio &ed::Polinomio::operator/=(double const &x)
{
	*this *=(1/x);
	return *this;
}

// Funciones lectura y escritura de la clase Polinomio

void ed::Polinomio::leerPolinomio()
{
	char opcion = 's';
	ed::Monomio personalizadoMonomio;
	this->monomios_.clear();
	while (opcion == 's')
	{
		personalizadoMonomio.ed::Monomio::leerMonomio();
		anadirMonomio(personalizadoMonomio);
		cout << "Desea anadir otro monomio mas al polinomio? [s/n]: ";
		cin >> opcion;
	}
}

void ed::Polinomio::escribirPolinomio()
{
	if (this->esNulo())
	{
		std::cout << "0";
		return;
	}
	this->monomios_[0].ed::Monomio::escribirMonomio();
	for (int i = 1; i < this->getNumeroMonomios(); i++)
	{
		if (this->monomios_[i].getCoeficiente() > 0)
			std::cout << "+";
		this->monomios_[i].ed::Monomio::escribirMonomio();
	}
}

// Funciones auxiliares de la clase Polinomio

double ed::Polinomio::calcularValor(double const x)
{
	double resultado = 0.0;
	for (int i = 0; i < this->getNumeroMonomios(); i++)
		resultado += this->monomios_[i].calcularValor(x);
	return resultado;
}

void ed::Polinomio::anadirMonomio(ed::Monomio const &m)
{
	if (std::abs(m.getCoeficiente()) < COTA_ERROR)
		return;

	if (this->esNulo())
	{
		this->monomios_.push_back(m);
		return;
	}

	std::vector<ed::Monomio>::iterator it;

	if (this->existeMonomio(m.getGrado()))
		for (it = this->monomios_.begin(); it != this->monomios_.end(); it++)
			if (it->getGrado() == m.getGrado())
			{
				(*it) += m;
				if ((std::abs(it->getCoeficiente())) < COTA_ERROR)
					this->monomios_.erase(it);
				return;
			}

	for (it = this->monomios_.begin(); it != this->monomios_.end(); it++)
		if (m.getGrado() > it->getGrado())
		{
			this->monomios_.insert(it, m);
			return;
		}

	this->monomios_.push_back(m);
}

std::vector<ed::Monomio> ed::Polinomio::getPolinomio() const
{
	return this->monomios_;
}
