/*!
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"

// Operadores de asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator=(ed::Monomio const &m)
{
	this->setCoeficiente(m.getCoeficiente());
	this->setGrado(m.getGrado());
	#ifndef NDEBUG
	assert(this->getGrado() == m.getGrado());
	assert(this->getCoeficiente() == m.getCoeficiente());
	#endif //NDEBUG

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator=(double const &x)
{
	this->setGrado(0);
	this->setCoeficiente(x);
	#ifndef NDEBUG
	assert(this->getGrado() == 0);
	assert(std::abs(this->getCoeficiente() - x) < COTA_ERROR );
	#endif //NDEBUG

	// Se devuelve el objeto actual
	return *this;
}



//////////////////////////////////////////////////////////////

// Operadores aritméticos y asignación



ed::Monomio & ed::Monomio::operator+=(ed::Monomio const &m)
{
	#ifndef NDEBUG
	assert(this->getGrado() == m.getGrado());
	#endif //NDEBUG
	//this->setGrado(getGrado() + m.getGrado());
	//this->setCoeficiente(getCoeficiente() + m.getGrado());
	ed::Monomio aux;
	aux.setCoeficiente(this->getCoeficiente()+m.getCoeficiente());
	aux.setGrado(this->getGrado()+m.getGrado());
	#ifndef NDEBUG
	assert(std::abs((this->getCoeficiente() - (aux.getCoeficiente()+m.getCoeficiente())) < COTA_ERROR));
	assert(this->getGrado() == m.getGrado());
	#endif //NDEBUG

	// Se devuelve el objeto actual
	return aux;
}

ed::Monomio & ed::Monomio::operator-=(ed::Monomio const &m)
{
	#ifndef NDEBUG
	assert(this->getGrado() == m.getGrado());
	#endif //NDEBUG	

	//this->setGrado(getGrado() - m.getGrado());
	//this->setCoeficiente(getCoeficiente() - m.getCoeficiente());
	ed::Monomio aux;
	aux.setCoeficiente(this->getCoeficiente()-m.getCoeficiente());
	aux.setGrado(this->getGrado()-m.getGrado());

	#ifndef NDEBUG
	assert(std::abs(this->getCoeficiente() -(aux.getCoeficiente() + m.getCoeficiente()) < COTA_ERROR));
	assert(this->getGrado() == m.getGrado());
	#endif //NDEBUG
	
	return aux;
}
ed::Monomio & ed::Monomio::operator*=(ed::Monomio const &m)
{
	Monomio aux;
  aux.setGrado(getGrado() + m.getGrado());
  aux.setCoeficiente(getCoeficiente()*m.getCoeficiente());

	#ifndef NDEBUG
	assert(std::abs(this->getCoeficiente()*m.getCoeficiente() - m) < COTA_ERROR);

	#endif //NDEBUG

  return aux;
}

ed::Monomio & ed::Monomio::operator/=(ed::Monomio const &m)
{
	return *this;
}
ed::Monomio & ed::Monomio::operator*=(double const &m)
{
	return *this;
}

ed::Monomio & ed::Monomio::operator/=(double const &m)
{
	return *this;
}


///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

void ed::Monomio::leerMonomio()
{
	int grado;
  double coeficiente;
	std::cout<<"Introduzca el coeficiente"<<std::endl;
  std::cin>>coeficiente;

  std::cout<<"Introduzca el grado"<<std::endl;
  std::cin>>grado;

  if(grado<0)
  {
    do{
    	std::cout << "introduzca un grado mayor o igual que 0" << std::endl;
      std::cin>>grado;
    }while(grado<0);
  }

  setCoeficiente(coeficiente);
  setGrado(grado);

}

void ed::Monomio::escribirMonomio()
{

	if(coeficiente_!=0)
	{
	  if(grado_==0)
	    std::cout<<coeficiente_;

	  else if(grado_==1)
	  {
	    if(coeficiente_==1)
	      std::cout<<"x";

	  	else if(coeficiente_==-1)
	    	std::cout<<"-x";

	  }
	  else
	  {
	    if(coeficiente_==1)
	      std::cout <<"x^"<<grado_;

	    else if(coeficiente_==-1)
	      std::cout<<"-x^"<<grado_;

	    else
	   		std::cout << coeficiente_<<"x^"<<grado_;

	  }
	}
}


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio
double ed::Monomio::calcularValor(double const &x)
{
	return getCoeficiente()*pow(x, getGrado());
}
