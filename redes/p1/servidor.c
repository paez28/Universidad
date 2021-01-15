/*
  REDES Práctica 1
*/

// Ficheros de cabecera obligatorios
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Ficheros de cabecera para la función tiempo
#include <time.h>
#include <locale.h>

// Ficheros de cabecera opcionales
#include <stdlib.h> // Para EXIT_FAILURE
#include <string.h> // Para 'strcmp()'

// Tamaño del buffer de datos
#define MAX 100

// Definición de funciones para evitar warnings de compilación
void close(int socket);

int main()
{
  /*----------------------------------------------------------------
                      DECLARACIÓN DE VARIABLES
    ----------------------------------------------------------------*/

  int socket_servidor; // Descriptor del socket.
  struct sockaddr_in servidor; /* Usaremos esta estructura para entablar la
  conexión con el cliente mediante la función 'bind()'. */
  char datos[MAX]; // Buffer usado para intercambiar mensajes.

  /* Con las dos siguientes variables recogemos los datos que nos envía el cliente
  y le enviamos una respuesta mediante las funciones 'recvfrom()' y 'sendto()'. */
  struct sockaddr_in cliente;
  socklen_t longitud; // Tamaño de la estructura.

  int recibido; // Para hacer comprobaciones de errores en 'recvfrom()'
  int enviado; // Para hacer comprobaciones de errores en 'sendto()'

  // Variables para la función tiempo
  time_t tiempo;
  struct tm* stTm;


  /*----------------------------------------------------------------
                      APERTURA DEL SOCKET SERVIDOR
    ----------------------------------------------------------------*/
  // Usamos la función 'socket()' con los mismos parámetros que en el cliente.

  socket_servidor = socket(AF_INET, SOCK_DGRAM, 0);

  if(socket_servidor == -1) // Comprobación de seguridad
  {
    printf("ERROR en la apertura del socket servidor...\n");
    exit(EXIT_FAILURE);
  }


  /*----------------------------------------------------------------
              RELLENO DE LA ESTRUCTURA 'sockaddr_in servidor'
    ----------------------------------------------------------------*/

  /* Rellenamos la estructura 'servidor' de la misma forma que en el fichero
  de cliente, con la única diferencia de que le diremos al sistema que use atienda
  a cualquier cliente mediante el uso de INADDR_ANY y el uso de la función 'htonl()'. */

  servidor.sin_family = AF_INET;
  servidor.sin_port = htons(2000);
  servidor.sin_addr.s_addr = htonl(INADDR_ANY);


  /*----------------------------------------------------------------
                          USO DE LA FUNCIÓN 'bind()'
    ----------------------------------------------------------------*/

  /* Para asociar el socket del servidor con un puerto usamos la función 'bind()'
  la cual recibe 3 parámetros:

  -> socket_servidor: Descriptor del socket.
  -> (struct sockaddr*) &servidor: Estructura 'servidor' rellena con los datos
  de socket y de la IP que queremos atender.
  -> sizeof(servidor): Tamaño de la estructura 'servidor'.

  ATENCIÓN: Hay que comprobar que bind se ejecuta correctamente, en caso de error
  esta devuelve el valor -1. */

  if(bind(socket_servidor, (struct sockaddr*) &servidor, sizeof(servidor)) == -1)
  {
    printf("ERROR al asociar el socket con un puerto...\n");
    close(socket_servidor); // Cerramos el socket
    exit(EXIT_FAILURE);
  }


  /*----------------------------------------------------------------
                    ESPERA DEL MENSAJE DEL CLIENTE
    ----------------------------------------------------------------*/

  /* Guardamos el tamaño de la estructura 'cliente' en la variable 'longitud' ya
  que será necesaria en las funciones 'recvfrom()' y 'sendto()'. */

  longitud = sizeof(cliente);

  // Utilizamos un bucle infinito que espere recibir mensajes del cliente
  while(1)
  {
    // Usamos 'recvfrom()' para esperar la llamada de algún cliente

    printf("\nRecibiendo mensaje del cliente...\n");

    recibido = recvfrom(socket_servidor, datos, MAX, 0, (struct sockaddr*) &cliente,
    &longitud);

    if(recibido <= 0) // Comprobación de seguridad
      printf("ERROR al leer del cliente...\n");
    else
    {
      printf("Recibida la cadena: %s\n", datos);


      /*----------------------------------------------------------------
                USO DE LA FUNCION TIEMPO Y ENVIO DE LA RESPUESTA
        ----------------------------------------------------------------*/

      /* Utilizamos la función de tiempo para obtener los datos necesarios y,
      según de la entrada recibida por teclado, envíamos al cliente los datos
      adecuados */

      tiempo = time(NULL);

      setlocale(LC_ALL, "");

      stTm = localtime(&tiempo);

      printf("Preparando la información...\n");

      if(strcmp(datos, "DAY") == 0)
      {
        // Envía el formato: Lunes, 17 de Septiembre de 2018
        strftime(datos, MAX, "%A, %d de %B de %Y", stTm);
      }
      else if(strcmp(datos, "TIME") == 0)
      {
        // Envía el formato: 16:00:00
        strftime(datos, MAX, "%H:%M:%S", stTm);
      }
      else if(strcmp(datos, "DAYTIME") == 0)
      {
        // Envía el formato: Lunes, 17 de Septiembre de 2018; 16:00:00
        strftime(datos, MAX, "%A, %d de %B de %Y; %H:%M:%S", stTm);
      }
      else
      {
        printf("ERROR, la cadena introducida es errónea...\n");
      }

      // Una vez relleno el buffer de datos, enviamos el resultado al cliente.

      printf("Enviando información al cliente...\n");

      enviado = sendto(socket_servidor, datos, MAX, 0, (struct sockaddr*) &cliente,
      longitud);

      if(enviado < 0) // Comprobación de seguridad
      {
        printf("ERROR al enviar el mensaje al cliente...\n");
      }

      printf("INFORMACIÓN ENVIADA\n");
    }
  }

  close(socket_servidor); // Cerramos el socket

  return 0;
}
