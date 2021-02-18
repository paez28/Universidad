#include "ruleta.h"

bool Ruleta::addJugador(Jugador new_player){
  string filename;

    //Comprueba si el jugador existe
    if(player_exist(new_player)){
        return false;
    }

    //Añade el nuevo jugador
    jugadores_.push_back(new_player);


    filename = new_player.getDNI() + ".txt";
    //Comprueba si el archivo ya existe
    if (ifstream(filename)){
        return true;
    }
    std::ofstream file;
    file.open(filename);
    file.close();
    return true;

}
bool Ruleta::player_exist(Jugador player){
    //Recorremos una lista de la siguiente forma (IMPORTANTE)
    //Equivalente a "for itplayer in jugadores_:" (python)
    list<Jugador>::iterator itplayer;
    for(itplayer = jugadores_.begin(); itplayer != jugadores_.end(); itplayer++){
        if (itplayer->getDNI() == player.getDNI()){
            return true;
        }
    }
    return false;
}

int Ruleta::deleteJugador(string DNI){
list<Jugador>::iterator ite;

	if(jugadores_.empty()){
		return -1;
	}

	for(ite=jugadores_.begin(); ite != jugadores_.end();ite++){
		if(DNI == ite->getDNI()){
			ite=jugadores_.erase(ite);

			return 1;
		}
	}
	return -2;

}
void Ruleta::escribeJugadores(){
    fstream f;
    f.open("jugadores.txt",std::ios::out);
    list<Jugador>::iterator it;
    for(it=jugadores_.begin();it !=jugadores_.end();it++){
        f<<it->getDNI()<<","<<
	it->getCodigo()<<","<<
	it->getNombre()<<","<<
	it->getApellidos()<<","<<
	it->getEdad()<<","<<
	it->getDireccion()<<","<<
	it->getLocalidad()<<","<<
	it->getProvincia()<<","<<
	it->getPais()<<","<<
	it->getDinero()<<endl;
	}


	f.close();

    
}

void Ruleta::leeJugadores()
{
	Jugador jugador("44XX","jugador1");
	char DNI[50], codigo[50], nombre[50], apellidos[50], direccion[50], localidad[50], provincia[50], pais[50], dinero[50];
	int dineroint;
	jugadores_.clear(); //limpiamos la lista de jugadores

	ifstream archivoEntrada("jugadores.txt");

	while (archivoEntrada.getline(DNI,256,',')) //mientras haya un elemento hacemos el bucle y lo extraemos
    {
		archivoEntrada.getline(codigo,256,',');
		archivoEntrada.getline(nombre,256,',');
		archivoEntrada.getline(apellidos,256,',');
		archivoEntrada.getline(direccion,256,',');
		archivoEntrada.getline(localidad,256,',');
		archivoEntrada.getline(provincia,256,',');
		archivoEntrada.getline(pais,256,',');
		archivoEntrada.getline(dinero,256,'\n');
		jugador.setDNI(DNI);
		jugador.setCodigo(codigo);
		jugador.setNombre(nombre);
		jugador.setApellidos(apellidos);
		jugador.setDireccion(direccion);
		jugador.setLocalidad(localidad);
		jugador.setProvincia(provincia);
		jugador.setPais(pais);
		dineroint=atoi(dinero);
		jugador.setDinero(dineroint);
		jugadores_.push_back(jugador); //metemos todo en la lista del jugador con push, el tipo de dato es jugador
	}

	archivoEntrada.close(); //cerramos el fichero
}

void Ruleta::getPremios(){

    list<Jugador>::iterator itplayer;

    for (itplayer = jugadores_.begin(); itplayer != jugadores_.end(); itplayer++){
        itplayer->setApuestas();
        list<Apuesta>::iterator itapuesta;
        for (itapuesta = itplayer->getApuestas().begin(); itapuesta != itplayer->getApuestas().end(); itapuesta++){
            if (itapuesta->tipo == 1){
                if(stoi(itapuesta->valor) == bola_){
                    banca_ = banca_ - (35 * itapuesta->cantidad);
                    itplayer->setDinero(itplayer->getDinero() + (35 * itapuesta->cantidad));
                }
                else{
                    banca_ = banca_ + itapuesta->cantidad;
                    itplayer->setDinero(itplayer->getDinero() - itapuesta->cantidad);
                }
            }
            else if (bola_ == 0){
                banca_ = banca_ + itapuesta->cantidad;
                itplayer->setDinero(itplayer->getDinero() - itapuesta->cantidad);
            }
            
            else if(itapuesta->tipo == 3){
                if((itapuesta->valor == "par")&& (bola_%2==0)){
                    banca_ = banca_ - itapuesta->cantidad;
                    itplayer->setDinero(itplayer->getDinero() + itapuesta->cantidad);
                }
                else if((itapuesta->valor == "impar")&& (bola_%2!=0)){
                    banca_ = banca_ - itapuesta->cantidad;
                    itplayer->setDinero(itplayer->getDinero() + itapuesta->cantidad);
                }
                else {
                    banca_ = banca_ + itapuesta->cantidad;
                    itplayer->setDinero(itplayer->getDinero() - itapuesta->cantidad);
                }
            }
            else if(itapuesta->tipo == 4){
                if((itapuesta->valor == "alto") && (bola_>18)){
                    banca_ = banca_ - itapuesta->cantidad;
                    itplayer->setDinero(itplayer->getDinero() + itapuesta->cantidad);
                }
                else if((itapuesta->valor == "bajo")&&(bola_<18)){
                    banca_ = banca_ - itapuesta->cantidad;
                    itplayer->setDinero(itplayer->getDinero() + itapuesta->cantidad);
                }
                else {
                    banca_ = banca_ + itapuesta->cantidad;
                    itplayer->setDinero(itplayer->getDinero() - itapuesta->cantidad);
                }
            }
            
        }

    }

}

void Ruleta::giraRuleta()
{
	srand(time(NULL));
    bola_= rand() % 37;
}