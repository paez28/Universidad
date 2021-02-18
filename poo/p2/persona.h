#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>
using namespace std;


class Persona
{
private:
   string DNI_;
   string nombre_;
   string apellidos_;
   int edad_;
   string direccion_;
   string localidad_;
   string provincia_;
   string pais_;

public:
    
    inline void setDNI(string dni){DNI_=dni;}
    inline string getDNI(){return DNI_;}
    inline void setNombre(string nombre){nombre_=nombre;}
    inline string getNombre(){return nombre_;}
    inline void setApellidos(string apellidos){apellidos_=apellidos;}
    inline string getApellidos(){return apellidos_;}
    inline bool setEdad(int edad){
        if(edad >=0 ){
            edad_=edad;
            return true;
        }else{
            return false;
        }
    }
    inline int getEdad(){return edad_;}
    inline void setDireccion(string direccion){direccion_=direccion;}
    inline string getDireccion(){return direccion_;}
    inline string getLocalidad(){return localidad_;}
    inline void setLocalidad(string localidad){localidad_=localidad;}
    inline string getProvincia(){return provincia_;}
    inline void setProvincia(string provincia){provincia_=provincia;}
    inline string getPais(){return pais_;}
    inline void setPais(string pais){pais_=pais;}
    
    bool mayor();
    inline string getApellidosyNombre(){
        return getApellidos()+", "+getNombre(); 
    }

    Persona(string DNI,string nombre="",string apellidos="",int edad=0,
    string direccion="",string localidad="", string provincia="",string pais="" ){
        setDNI(DNI);
        setNombre(nombre);
        setApellidos(apellidos);
        setEdad(edad);
        setDireccion(direccion);
        setLocalidad(localidad);
        setProvincia(provincia);
        setPais(pais);
    }



};
#endif