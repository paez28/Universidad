/*!
    \file Monomio.hpp
    \brief Definición de la clase Monomio
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

#include <cmath>
#include <cassert>

#define COTA_ERROR 1.0e-6    //!< Cota de error para la comparación números reales

namespace ed
{
//! Definición de la clase Monomio: \f$ coeficiente \hspace{1ex} X^{grado} \f$
class Monomio
{
    //! \name Atributos privados de la clase Monomio
    private:

        double coeficiente_;    //!< Coeficiente del monomio
        int grado_;    //!< Grado del monomio

    //! \name Funciones o métodos públicos de la clase Monomio
    public:

        //! \name Constructores de la clase Monomio

        /**
         * \brief Constructor
         * \param double coeficiente: coeficiente del monomio
         * \param int grado: grado del monomio
         * \pre El grado debe ser mayor o igual que 0
         * \warning Si no recibe algun valor, a este se le asigna 0
        */
        Monomio (double coeficiente = 0.0, int grado = 0);

        /**
         * \brief Constructor de copia
         * \param Monomio &monomio: referencia de un objeto monomio
        */
        Monomio (const Monomio &monomio);

        //! \name Observadores: funciones de consulta de la clase Monomio

        /**
         * \brief Lectura del coeficiente
         * \retval Valor del coeficiente
        */
        inline double getCoeficiente () const {return this->coeficiente_;};

        /**
         * \brief Lectura del grado
         * \retval Valor del grado
        */
        inline int getGrado () const {return this->grado_;};

        //! \name Funciones de modificación de la clase Monomio

        /**
         * \brief Escritura del coeficiente
         * \param double coeficiente: coeficiente del monomio
        */
        void setCoeficiente (double coeficiente);

        /**
         * \brief Escritura del coeficiente
         * \param double coeficiente: coeficiente del monomio
         * \pre El grado debe ser mayor o igual que 0
        */
        void setGrado (int grado);

        //! \name Operadores de la clase Monomio

        /**
         * \brief Operador de asignacion
         * \param Monomio &m: referencia de un objeto monomio
         * \retval Monomio actualizado
        */
        Monomio & operator = (const Monomio &m);

        /**
         * \brief Operador de asignacion
         * \param const double x: coeficiente del monomio
         * \retval Monomio actualizado (con grado 0)
        */
        Monomio & operator = (const double &x);

        /**
         * \brief Operador aritmetico de suma y asignacion
         * \param Monomio &m: referencia de un objeto monomio
         * \retval Monomio actualizado
        */
        Monomio & operator += (Monomio const &m);

        /**
         * \brief Operador aritmetico de resta y asignacion
         * \param Monomio &m: referencia de un objeto monomio
         * \retval Monomio actualizado
        */
        Monomio & operator -= (Monomio const &m);

        /**
         * \brief Operador aritmetico de multiplicacion y asignacion
         * \param Monomio &m: referencia de un objeto monomio
         * \retval Monomio actualizado
        */
        Monomio & operator *= (Monomio const &m);

        /**
         * \brief Operador aritmetico de division y asignacion
         * \param Monomio &m: referencia de un objeto monomio
         * \retval Monomio actualizado
        */
        Monomio & operator /= (Monomio const &m);

        /**
         * \brief Operador aritmetico de multiplicacion y asignacion
         * \param const double x: coeficiente del monomio
         * \retval Monomio actualizado
        */
        Monomio & operator *= (const double x);

        /**
         * \brief Operador aritmetico de division y asignacion
         * \param const double x: coeficiente del monomio
         * \retval Monomio actualizado
        */
        Monomio & operator /= (const double x);

        //! \name Funciones lectura y escritura de la clase Monomio

        /**
         * \brief Lectura de monomio por teclado
        */
        void leerMonomio ();

        /**
         * \brief Escritura de monomio por pantalla
        */
        void escribirMonomio ();

        //! \name Funciones auxiliares de la clase Monomio

        /**
         * \brief Calculo del valor de un monomio
         * \param double x: valor que toma x en el monomio
        */
        double calcularValor (double x);

};

}

#endif
