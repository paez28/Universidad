/*
  REDES PRÁCTICA 1

  Autor: Alejandro Siles Jiménez
  Usuario UCO: i72sijia
*/

// Ficheros de cabecera obligatorios
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Fichero de cabecera para la función 'select()'
#include <sys/time.h>

// Ficheros de cabecera opcionales
#include <stdlib.h> // Para EXIT_FAILURE

//Tamaño máximo de la cadena de datos usada en la práctica
#define TAM 100

// Definición de funciones para eliminar warnings de compilación.
in_addr_t inet_addr(const char *cp);
void close(int socket);
int inet_pton(int family, const char *ip, void *dst);

// Con esta función comprobamos que el primer argumento sea una IP válida
int isIP(char *ip)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
    return result;
}

int main(int argc, char** argv)
{

  /*----------------------------------------------------------------
              CONTROL DE ERRORES EN LA LÍNEA DE ARGUMENTOS
   ----------------------------------------------------------------*/
  if(argc != 3) // Si el programa no recibe el número argumentos requeridos...
  {
    printf("ERROR en la línea de argumentos...\n");
    printf("Se esperaban dos argumentos del tipo <IP> <Segundos de espera>\n");

    exit(EXIT_FAILURE);
  }

  else // Si los recibe, controlamos que los argumentos sean adecuados
  {
    if(isIP(argv[1]) == 0) // Controlamos que el primer argumento sea una IP válida.
    {
      printf("ERROR, se esperaba que el primer argumento fuera una IP válida...\n");
      exit(EXIT_FAILURE);
    }
    
    if(atoi(argv[2]) < 1 || atoi(argv[2]) > 5)// Controlamos que el segundo argumento sea un entero aceptable.
    {
      printf("ERROR, se esperaba que el segundo argumento fuera un argumento de tipo entero comprendido entre 1 y 5\n");

      exit(EXIT_FAILURE);
    }
  }

  /*----------------------------------------------------------------
                    DECLARACIÓN DE VARIABLES
    ----------------------------------------------------------------*/

  /* Declaramos una variable de tipo entero 'socket_cliente' para guardar el
  descriptor del socket que usará el servidor para intercambiar información*/
  int socket_cliente;
  char datos[TAM]; // Aquí guardamos la cadena con la que intercambiamos información.

  /* Ahora declaramos una variable de tipo struct sockaddr_in en la que alojaremos
  información relacionada con el socket en el formato:

    struct sockaddr_in
    {
      short sin_family; -> Usaremos AF_INET para esta práctica.
      u_short sin_port; -> Guardamos el puerto a utilizar, usaremos la función htons(puerto)
      struct in_addr sin_addr -> Usamos inet_addr(IP), información al respecto más adelante
      char sin_zero[8]; -> Este campo no lo usaremos
    }*/

  struct sockaddr_in servidor;
  socklen_t longitud; /* Aquí guardamos el tamaño de la estructura 'servidor',
  necesaria para las funciones 'sendto()' y 'recvfrom()'*/

  // Variables necesarias en la función select:
  struct timeval timeout; // Estructura timeval que marca el tiempo de espera de 'select()'
  fd_set lectura; // Se usa para inicializar los conjuntos fd_set.

  int enviado; /* Aquí guardamos el número de bytes mandados al servidor, nos
  sirve para hacer la comprobación de seguridad de que se ha mandado correctamente. */
  int recibido; /* Mismo uso que enviado, guardamos el número de bytes recibidos,
  sirve para realizar la comprobación de seguridad de que se ha recibido todo correctamente. */
  int salida; /* Guardamos el valor retornado de la función select y lo usamos
  para comprobaciones de seguridad */
  int contador = 3; /* Tenemos 3 intentos para hacer la llamada, lo controlamos con
  el contador. */

  /*----------------------------------------------------------------
                    APERTURA DEL SOCKET CLIENTE
    ----------------------------------------------------------------*/

  /* El socket es el descriptor de la conexión existente entre el cliente
  y el servidor, necesitamos usar la función 'socket()' y guardar su valor
  en una variable para abrir el propio socket y obtener su valor.

  La función 'socket()' recibe los siguientes tres parámetros:
  -> AF_INET: Familia que usaremos.
  -> SOCK_DGRAM: Indica que usaremos un socket tipo UDP, si queremos un socket
  tipo TCP usamos SOCK_STREAM.
  -> 0: Protocolo a usar, con este indicamos al sistema que use el más conveniente

  ATENCION: Si la función 'socket()' falla a la hora de ser ejecutada, esta
  devuelve -1, es importante realizar la comprobación de seguridad */

  socket_cliente = socket(AF_INET, SOCK_DGRAM, 0);

  if(socket_cliente == -1) // Comprobación de seguridad
  {
    printf("ERROR en la apertura del socket cliente...\n");
    exit (EXIT_FAILURE);
  }


  /*----------------------------------------------------------------
                RELLENO DE LA ESTRUCTURA 'sockaddr_in'
    ----------------------------------------------------------------*/

  /* Rellenamos la estructura según las especificaciones anteriores.

  Para rellenar el campo 'sin_addr.s_addr' usamos la función 'inet_addr()'
  ya que este necesita que la dirección IP tenga un formato adecuado y esta
  función nos convierte una cadena al formato necesario. */

  servidor.sin_family = AF_INET;
  servidor.sin_port = htons(2000);
  servidor.sin_addr.s_addr = inet_addr(argv[1]);

  // Guardamos la longitud de la estructura servidor en la variable longitud.

  longitud = sizeof(servidor);


  /*----------------------------------------------------------------
                    RELLENO DE LA CADENA 'datos'
    ----------------------------------------------------------------*/

  printf("\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n");
  printf("\tSERVICIO DE OBTENCION DE DIA Y HORA");
  printf("\n\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n");

  printf("Elige que tipo de información deseas introduciendo la cadena adecuada:\n\n");
  printf("DAY -> Obtienes el formato: 'Lunes, 17 de Septiembre de 2018'\n");
  printf("TIME -> Obtienes el formato: '16:00:00'\n");
  printf("DAYTIME -> Obtienes el formato: 'Lunes, 17 de Septiembre de 2018; 16:00:00'\n");

  printf("\nIntroduce la cadena: ");
  scanf("%s", datos);

  printf("\nObteniendo datos...\n");


  /*----------------------------------------------------------------
                    ENVÍO DEL MENSAJE AL SERVIDOR
    ----------------------------------------------------------------*/

  /* Para enviar el mensaje al servidor usamos la función 'sendto()' la cual
  recibe los siguientes 6 parámetros:

  -> socket_cliente: Descriptor del socket utilizado.
  -> (char*) &datos: Buffer de datos a enviar con casting a (char*).
  -> TAM: También se puede ver como sizeof(datos), tamaño del buffer.
  -> 0: Opción que usaremos en la práctica.
  -> (struct sockaddr* ) &servidor: Mandamos la estructura servidor a la que le
  realizamos un casting a (sockaddr*), no hay problema ya que las estructuras
  'sockaddr' y 'sockaddr_in' son compatibles para el casting.
  -> longitud: Tamaño de la estructura 'servidor'.

  IMPORTANTE: Guardamos el valor retornado de 'sendto()' en la variable 'enviado'
  y comprobamos que el número de bytes enviado sea el indicado mediante un control
  de errores. */

  enviado = sendto(socket_cliente, datos, TAM, 0,
  (struct sockaddr*) &servidor, longitud);

  if(enviado < 0) // Control de errores, si enviado < 0 indica que no ha enviado nada.
    printf("ERROR al solicitar el servicio...\n\n");
  else // Si se ha enviado bien, esperamos la respuesta del servidor
  {

    /*----------------------------------------------------------------
                      USO DE LA FUNCIÓN 'select()'
      ----------------------------------------------------------------*/

    /* Usamos la función 'select()' para establecer un tiempo límite para la
    respuesta del servidor */

    while(contador > 0) // Controlamos el contador
    {
      /* IMPORTANTE: En cada vuelta del bucle tenemos que rellenar la estructura
      timeval e inicializar los conjuntos */

      // Primero inicializamos la estructura timeval:
      timeout.tv_sec = atoi(argv[2]); // Segundos que 'select()' espera a la respuesta del servidor.
      timeout.tv_usec = 0; // Igualamos siempre a 0.

      // Ahora inicializamos los conjuntos fd_set.
      FD_ZERO(&lectura); // Inicializamos el conjunto 'lectura'
      FD_SET(socket_cliente, &lectura); // Asocia el socket con el conjunto fd_set.

      /* Ahora utilizamos la función 'select()' la cual recibe 5 parámetros:

      -> socket_cliente+1: Valor incrementado en una unidad del socket utilizado.
      -> &lectura: Estructura 'fd_set' asociada al socket donde guardamos la
         salida de 'select()'
      -> NULL: Socket de escritura, usamos NULL ya que no vamos a escribir.
      -> NULL: Socket de excepciones, usamos NULL ya que no lo vamos a mirar.
      -> &timeout: Estructura 'timeval' con el tiempo de espera de 'select()'.

      IMPORTANTE: Las salidas de 'select()' son:
      -> -1: Si se produce un error.
      -> 0: Si agota el tiempo de espera.
      -> Cualquier otra: Si ha funcionado correctamente.  */

      salida = select(socket_cliente+1, &lectura, NULL, NULL, &timeout);

      if(salida == -1) // Control de errores.
      {
        printf("ERROR producido en select...\n");
      }
      else if(salida == 0) // Si se termina el tiempo de espera.
      {
        if(contador != 1) // Si falla la llamada al servidor hacemos otra.
        {
          printf("Se ha agotado el tiempo de espera, haciendo otra llamada...\n");

          // Hacemos otro envío al servidor
          enviado = sendto(socket_cliente, datos, TAM, 0,
          (struct sockaddr*) &servidor, longitud);

          if(enviado < 0) // Control de errores, si enviado < 0 indica que no ha enviado nada.
            printf("ERROR al solicitar el servicio...\n\n");
        }
        else // Agotamos los intentos, cerramos bucle y terminamos el programa
          printf("Se ha agotado el tiempo de espera, ya no se producen más llamadas... \n");

        contador--;
      }
      else
      {

        /*----------------------------------------------------------------
                        ESPERA DE RESPUESTA DEL SERVIDOR
          ----------------------------------------------------------------*/

        /* Para recibir los datos del servidor usamos la función 'recvfrom()', la
        cual recibe de 6 parámetros muy parecidos a los de la función 'sendto()'
        pero con ligeras diferencias:

        -> socket_cliente: Descriptor del socket utilizado.
        -> (char*) &datos: Buffer donde guardamos la información recibida con
        casting a (char*).
        -> TAM: También puede usarse 'sizeof(Datos)', tamaño del buffer.
        -> 0: Opciones de recepción, en esta práctica usamos 0.
        -> (struct sockaddr*) &servidor: La función 'recvfrom()' rellena la estructura
        con los datos del que nos ha enviado el mensaje, podemos usarla para responder.
        Si no vamos a responder podemos usar NULL directamente.
        -> &longitud: Puntero al tamaño de la estructura 'servidor'

        IMPORTANTE: En la variable recibido guardamos el valor retornado por 'recvfrom()',
        es decir, el número de bytes recibidos, falla si recibimos bytes de más. */

        recibido = recvfrom(socket_cliente, datos, TAM, 0,
           (struct sockaddr*) &servidor, &longitud);

        if(recibido <= 0) // Comprobación de seguridad
          printf("ERROR al leer del servidor...\n\n");
        else
          printf("[[%s]]\n\n", datos);

        contador = 0; // Salimos del bucle ya que hemos obtenido nuestro resultado.
      }
    }
  }

  // Cerramos el socket con la función 'close()'.
  close(socket_cliente);

  return 0;
}
