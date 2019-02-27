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
		if((m1.getGrado() == m2.getGrado()) and (m1.getCoeficiente()==m2.getCoeficiente())){
		k = true;
		}else{
		
		k = false;
		
		}
		#ifndef NDEBUG
		if(k == true){
		assert(m1.getGrado()==m2.getGrado());
		assert((std::abs(m1.getCoeficiente()-m2.getCoeficiente())) < COTA_ERROR);
		}
		#endif //NDEBUG
		return k;
	}

	bool operator==(ed::Monomio const & m1, double x)
	{
		bool k;
		if((m1.getGrado()==0) and (m1.getCoeficiente()==x)){
		k = true;
		}else{
		
		k = false;
		
		}
		#ifndef NDEBUG
		if(k == true){
		assert(m1.getGrado()==0);
		assert((std::abs(m1.getCoeficiente()- x )) < COTA_ERROR);
		}
		#endif //NDEBUG
		return k;


	}
	bool operator==(double x, ed::Monomio const & m2)
	{
		bool k;
		if((0 == m2.getGrado()) and ( x == m2.getCoeficiente())){
		k = true;
		}else{
		
		k = false;
		
		}
		#ifndef NDEBUG
		if(k == true){
		assert(x==m2.getGrado());
		assert((std::abs(x-m2.getCoeficiente())) < COTA_ERROR);
		}
		#endif //NDEBUG
		return k;

		

	}



	// Operadores de desigualdad


	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		bool k;
		if((m1.getGrado() != m2.getGrado()) or (m1.getCoeficiente()!=m2.getCoeficiente())){
		k = true;
		}else{
		
		k = false;
		
		}
		#ifndef NDEBUG
		if(k == true){
			if(m1.getGrado()!=m2.getGrado()){
				assert(m1.getGrado()!=m2.getGrado());
			}
			if(not(std::abs(m1.getCoeficiente()-m2.getCoeficiente())< COTA_ERROR)){
				assert(not(std::abs(m1.getCoeficiente()-m2.getCoeficiente())< COTA_ERROR));
			}
		}
		#endif //NDEBUG
		return k;	

		
		
	}

	bool operator!=(double x, ed::Monomio const & m2)
	{
		bool k;
		if((0 != m2.getGrado()) or (x!=m2.getCoeficiente())){
		k = true;
		}else{
		
		k = false;
		
		}
		#ifndef NDEBUG
		if(k == true){
			if(0!=m2.getGrado()){
				assert(0!=m2.getGrado());
			}
			if(not(std::abs(x-m2.getCoeficiente())< COTA_ERROR)){
				assert(not(std::abs(x-m2.getCoeficiente())< COTA_ERROR));
			}
		}
		#endif //NDEBUG
		return k;

	
	}

	bool operator!=(ed::Monomio const & m1, double x)
	{
		bool k;
		if((m1.getGrado() != 0) or (m1.getCoeficiente()!=x)){
		k = true;
		}else{
		
		k = false;
		
		}
		#ifndef NDEBUG
		if(k == true){
			if(m1.getGrado()!=0){
				assert(m1.getGrado()!=0);
			}
			if(not(std::abs(m1.getCoeficiente()-x)< COTA_ERROR)){
				assert(not(std::abs(m1.getCoeficiente()-x)< COTA_ERROR));
			}
		}
		#endif //NDEBUG
		return k;	

	
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

		nuevo->setGrado(m1.getGrado());
		nuevo->setCoeficiente(m1.getCoeficiente()* x );

		#ifndef NDEBUG

		assert(nuevo->getGrado()==m1.getGrado());
		assert(std::abs(nuevo->getCoeficiente()-(m1.getCoeficiente()* x ))<COTA_ERROR);

		#endif

		return *nuevo;
	}

	ed::Monomio & operator* (double x, ed::Monomio const &m2)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setGrado(m2.getGrado());
		nuevo->setCoeficiente( x * m2.getCoeficiente());

		#ifndef NDEBUG

		assert(nuevo->getGrado()==m2.getGrado());
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
		#ifndef NDEBUG
		assert(not(std::abs(x - 0) < COTA_ERROR));
		#endif //NDEBUG
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setGrado(m1.getGrado());
		nuevo->setCoeficiente(m1.getCoeficiente()/x);

		#ifndef NDEBUG

		assert(nuevo->getGrado()==(m1.getGrado()));
		assert(std::abs(nuevo->getCoeficiente()-(m1.getCoeficiente()/x))<COTA_ERROR);

		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator/ (double x, ed::Monomio const &m2)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setGrado(m2.getGrado());
		nuevo->setCoeficiente(x/m2.getCoeficiente());

		#ifndef NDEBUG

			assert(nuevo->getGrado()==(m2.getGrado()));
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

		do{
        std::cout<<"Introduzca el grado"<<std::endl;
        stream>>grado;
		}while(grado <=0);


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
