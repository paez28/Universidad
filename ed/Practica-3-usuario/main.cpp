#include <iostream>
#include <cstdlib> //para usar srand()
#include <cctype>

#include "macros.hpp"

#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"
#include "generarpersona.hpp"

using namespace ed;

void insertar(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a);
void mostrar(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a);
void Buscar(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a);
void BorrarPersona(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a);
void BorrarArbol(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a);

int main()
{
  //srand(time(0));
  ArbolBinarioOrdenadoEnlazado<Persona> a;
  //EscribirNodo<Persona> aux;
  int opcion = 0;
  int posicion = 0;

  do{
      
      posicion = 2;

      system ("clear");
      
      std::cout<<endl<< "**** Menu ****"<<endl;
      
      posicion++;
      
      std::cout<< "[1] Insertar Personas."<<endl;
      std::cout<< "[2] Mostrar personas."<<endl;
      std::cout<< "[3] Buscar una persona."<<endl;
      std::cout<< "[4] Borrar una persona." <<endl;
      std::cout<< "[5] Borrar arbol"<<endl;
      
      posicion++;
      std::cout << BRED;
      std::cout << "[0] Fin del programa" << std::endl;
      std::cout << RESET;

      posicion++;
      std::cout<< BLUE;
      std::cout<<endl<<"\t"<<"Introducir opcion del menu:";
      std::cout<< RESET;
     
      std::cin >> opcion; 

      switch (opcion)
      {
        case 1:
          insertar(a);
          std::cin.ignore();
          break;
        case 2:
          mostrar(a);
          std::cin.ignore();
          break;
        case 3:
          Buscar(a);
          std::cin.ignore();
          break;
        case 4:
          BorrarPersona(a);
          std::cin.ignore();
          break;
        case 5:
          BorrarArbol(a);
          std::cin.ignore();
          break;
        /*default:
				  std::cout << BIRED;
				  std::cout << "Opción incorrecta ";
			  	std::cout << RESET;
			  	std::cout << "--> ";
			    std::cout << ONIRED;
			  	std::cout << opcion << std::endl;
				  std::cout << RESET;*/
      }
      /*switch (opcion)
      {
        case 0:{

          system("clear");
          exit(EXIT_SUCCESS);
          break;
        
        case 1:
          
          //std::cout << CLEAR_SCREEN;
          system("clear");
          int nPersonas,cont;
				  std::cout << "Numero de personas a insertar: ";
          std::cin>>nPersonas;
          std::cout << RESET;
          cont = 0;
          for(int i=0; i < nPersonas; i++){
            if(a.insertar(generarDatosPersonales())){
                cont++;
            }

          }
          //std::cout<< CLEAR_SCREEN;
          std::cout << BYELLOW;
          std::cout<< "Se han insertado: "<<cont << " personas.";
          std::cout<< RESET;

          break;
        }
          
        case 2:{
          system("clear");

          std::cout << BIBLUE;
          std::cout << "Mostrar Arbol";
          std::cout<< RESET;

          std::cout<<"PreOrden";
          a.recorridoPreOrden(aux);
          std::cout<<"\n";

          std::cout<<"PostOrden";
          a.recorridoPostOrden(aux);
          std::cout<<"\n";

          std::cout<<"InOrden";
          a.recorridoInOrden(aux);
          std::cout<<"\n";

          break;
        }

        case 5:{
          system("clear");
          std::cout << "Arbol borrado.\n";
          a.borrarArbol();
          break;
        }


        

        default:
				  std::cout << BIRED;
				  std::cout << "Opción incorrecta ";
			  	std::cout << RESET;
			  	std::cout << "--> ";
			    std::cout << ONIRED;
			  	std::cout << opcion << std::endl;
				  std::cout << RESET;

      
      
        
      }*/
      
  }while(opcion!=0);

  return 0;
}

void insertar (ed::ArbolBinarioOrdenadoEnlazado<Persona> &a){

  system("clear");
  EscribirNodo<Persona> aux;
  int nPersonas,cont;
	std::cout << "Numero de personas a insertar: ";
  std::cin>>nPersonas;
  std::cout << RESET;
  cont = 0;
  for(int i=0; i < nPersonas; i++){
    if(a.insertar(generarDatosPersonales())){
      cont++;
    }

  }
  std::cout << BYELLOW;
  std::cout<< "Se han insertado: "<<cont << " personas.";
  std::cout<< RESET;

  std::cin.ignore();

}

void mostrar(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a){

  system("clear");
  EscribirNodo<Persona> aux;

  std::cout << BIBLUE;
  std::cout << "Mostrar Arbol" <<std::endl;
  std::cout<< RESET;

  std::cout<< BIYELLOW;
  std::cout<<"PreOrden"<<std::endl;
  std::cout<< RESET;
  a.recorridoPreOrden(aux);
  std::cout<<"\n\n";

  std::cout<< BIYELLOW;
  std::cout<<"PostOrden"<<std::endl;
  std::cout<< RESET;
  a.recorridoInOrden(aux);
  std::cout<<"\n\n";

  std::cout<< BIYELLOW;
  std::cout<<"InOrden"<<std::endl;
  std::cout<< RESET;
  a.recorridoPostOrden(aux);
  std::cout<<"\n\n";

  std::cin.ignore();

}

void Buscar(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a){
  system("clear");
  Persona persona;

  std::cout << BIYELLOW;
  std::cout << "Introduzca el nombre de la persona: ";
  std::cout<< RESET;

  cin>>persona;

  if(a.buscar(persona)){
    std::cout<<"Persona encontrada\n\n";
    
  }else{
    std::cout << BIRED;
    std::cout<<"Persona no encontrada\n\n";
    std::cout << RESET;
  }
  std::cin.ignore();

}
void BorrarPersona(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a){
  system("clear");
  EscribirNodo<Persona> aux;
  Persona persona;
  std::cout<<"Introduzca la persona: "<<std::endl;
  std::cin>>persona;

  if(a.buscar(persona)){
    if(a.borrar()){
      std::cout<<"\n\n" << persona << "borrada" << std::endl;
    }else{
        std::cout << BIRED;
        std::cout<<"El elemento no ha sido borrado\n";
        std::cout << RESET;
        a.recorridoInOrden(aux); 
      }
  }else{
    std::cout << BIRED;
    std::cout<<"Persona no borrada\n\n";
    std::cout << RESET;
  }
  std::cin.ignore();
}

void BorrarArbol(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a){
  system("clear");
  if(!a.estaVacio()){
    a.borrarArbol();
  }
  if(a.estaVacio()){
    std::cout << BIYELLOW;
    std::cout<<"El arbol se ha borrado"<<std::endl;
    std::cout << RESET;
  }else{
    std::cout << BIRED;
    std::cout<<"Error al borrar el arbol"<<std::endl;
    std::cout << RESET;

  }
  std::cin.ignore();

}
