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


	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2)
	{

		bool k;
		if((m1.getGrado() != m2.getGrado()) and (m1.getCoeficiente()!=m2.getCoeficiente())){
		k = true;
		}else{
		
		k = false;
		
		}
		#ifndef NDEBUG
		assert((m1.getGrado()-m2.getGrado()) == k);
		assert((std::abs(m1.getCoeficiente()-m2.getCoeficiente())) > COTA_ERROR);
		#endif //NDEBUG
		return k;
	}

	bool operator==(ed::Monomio const & m1, double x)
	{



		return true;
	}
	bool operator==(double x, ed::Monomio const & m2)
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

	bool operator!=(double x, ed::Monomio const & m2)
	{


		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return true;
	}

	bool operator!=(ed::Monomio const & m1, double x)
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

		nuevo->setGrado(m.getGrado());
		nuevo->setCoeficiente(m.getCoeficiente());
		
		#ifndef NDEBUG
		assert(nuevo->getGrado() == m.getGrado());
		assert((std::abs(nuevo->getCoeficiente() - m.getCoeficiente())) < COTA_ERROR);
		#endif //NDEBUG

		return *nuevo;
	}

	ed::Monomio & operator-(ed::Monomio const & m)
	{

		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setGrado(m.getGrado());
		nuevo->setCoeficiente(-m.getCoeficiente());
		
		#ifndef NDEBUG
		assert(nuevo->getGrado() == m.getGrado());
		assert((std::abs(nuevo->getCoeficiente() - m.getCoeficiente())) > COTA_ERROR);
		#endif //NDEBUG
		
		return *nuevo;
	}




	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		ed::Monomio *nuevo = new ed::Monomio();
		#ifndef NDEBUG
		assert(m1.getGrado() == m2.getGrado());
		#endif

		nuevo->setCoeficiente(m1.getCoeficiente() + m2.getCoeficiente());
		#ifndef NDEBUG
		assert(nuevo->getGrado() == (m1.getGrado() -m2.getGrado()));
		assert(std::abs(nuevo->getCoeficiente() - (m1.getCoeficiente()+m2.getCoeficiente())) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}


	////////////
	// Resta

	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		ed::Monomio *nuevo = new ed::Monomio();
		#ifndef NDEBUG
		assert(m1.getGrado() == m2.getGrado());
		#endif
		
		nuevo->setCoeficiente(m1.getCoeficiente() - m2.getCoeficiente());
		
		#ifndef NDEBUG
		assert(nuevo->getGrado() == (m1.getGrado() -m2.getGrado()));
		assert(std::abs(nuevo->getCoeficiente() - (m1.getCoeficiente()-m2.getCoeficiente())) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}


	//////////////////
	// Multiplicación

	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2)
	{

		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setGrado(m1.getGrado()+m2.getGrado());
		nuevo->setCoeficiente(m1.getCoeficiente()*m2.getCoeficiente());

		#ifndef NDEBUG

		assert(nuevo->getGrado()==(m1.getGrado()+m2.getGrado()));
		assert(std::abs(nuevo->getCoeficiente()-(m1.getCoeficiente()*m2.getCoeficiente()))<COTA_ERROR);

		#endif

		return *nuevo;
	}

	ed::Monomio & operator* (ed::Monomio const &m1, double x)
	{

		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setGrado(m1.getGrado()+ x);
		nuevo->setCoeficiente(m1.getCoeficiente()* x );

		#ifndef NDEBUG

		assert(nuevo->getGrado()==(m1.getGrado()+x));
		assert(std::abs(nuevo->getCoeficiente()-(m1.getCoeficiente()* x ))<COTA_ERROR);

		#endif

		return *nuevo;
	}

	ed::Monomio & operator* (double x, ed::Monomio const &m2)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setGrado( x + m2.getGrado());
		nuevo->setCoeficiente( x * m2.getCoeficiente());

		#ifndef NDEBUG

		assert(nuevo->getGrado()==( x + m2.getGrado()));
		assert(std::abs(nuevo->getCoeficiente()-( x * m2.getCoeficiente()))<COTA_ERROR);

		#endif

		return *nuevo;
	
	}


	////////////
	// División
	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2)
	{

		#ifndef NDEBUG

			assert(m2.getGrado()<=m1.getGrado());
			assert(not(std::abs(m2.getCoeficiente()-0)<COTA_ERROR));

		#endif

		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setGrado(m1.getGrado()-m2.getGrado());
		nuevo->setCoeficiente(m1.getCoeficiente()/m2.getCoeficiente());

		#ifndef NDEBUG

			assert(nuevo->getGrado()==(m1.getGrado()-m2.getGrado()));
			assert(std::abs(nuevo->getCoeficiente()-(m1.getCoeficiente()/m2.getCoeficiente()))<COTA_ERROR);

		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator/ (ed::Monomio const &m1, double x)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setGrado(m1.getGrado()- x );
		nuevo->setCoeficiente(m1.getCoeficiente()/x);

		#ifndef NDEBUG

		assert(nuevo->getGrado()==(m1.getGrado()-x));
		assert(std::abs(nuevo->getCoeficiente()-(m1.getCoeficiente()/x))<COTA_ERROR);

		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator/ (double x, ed::Monomio const &m2)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setGrado(x-m2.getGrado());
		nuevo->setCoeficiente(x/m2.getCoeficiente());

		#ifndef NDEBUG

			assert(nuevo->getGrado()==(x-m2.getGrado()));
			assert(std::abs(nuevo->getCoeficiente()-(x/m2.getCoeficiente()))<COTA_ERROR);

		#endif

		// Se devuelve el resultado
		return *nuevo;
	
	}



	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m)
	{
		double coeficiente;
        int grado;
        std::cout<<"Introduzca el coeficiente"<<std::endl;
        stream>>coeficiente;

        std::cout<<"Introduzca el grado"<<std::endl;
        stream>>grado;

        m.setCoeficiente(coeficiente);
        m.setGrado(grado);	

   		// Se devuelve el flujo de entrada
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m)
	{
	if(m.getCoeficiente() != 0){
                if(m.getCoeficiente() == 1){
                    if(m.getGrado() == 0)
                        stream << m.getCoeficiente();
                    else if(m.getGrado() == 1)
                        stream << "x";
                    else
                        stream<< "x^" << m.getGrado();
                }
                else if(m.getCoeficiente() == -1){
                    if(m.getGrado() == 0)
                        stream << m.getCoeficiente();
                    else if(m.getGrado() == 1)
                        stream << "-x";
                    else
                        stream << "-x^" << m.getGrado();
                }
                else{
                    if(m.getGrado() == 0)
                        stream << m.getCoeficiente();
                    else if(m.getGrado() == 1)
                        stream << m.getCoeficiente() << "x";
                    else
                        stream << m.getCoeficiente() << "x^" << m.getGrado();
                }
            }
        
		return stream;
	}


}  // namespace ed
