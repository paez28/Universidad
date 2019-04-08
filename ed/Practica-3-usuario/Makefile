CPPFLAGS = -g -Wall -ansi

all: main

main: main.cpp persona.cpp persona.hpp arbolbinarioordenadoenlazado.hpp operadornodo.hpp generarpersona.cpp generarpersona.hpp
	g++  $(CPPFLAGS) main.cpp persona.cpp generarpersona.cpp -o main.exe
	@echo
	@echo " * main. Programa compilado. "
	@echo
	@echo  "////////////////////////////////////////////////////"
	@echo

# Generación de la documentación
doc: Doxyfile 
	@echo "Generando la documentación con doxygen"
	@doxygen
	
# Borrado
.PHONY: clean  
clean:
	@echo "Borrando los ficheros superfluos"
	@rm -f $(OBJECTS) *~ 
	
