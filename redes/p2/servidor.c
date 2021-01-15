// Librerias basicas para
 
#include <stdio.h>         //   I/O
#include <stdlib.h>         //   Libreria standar para manejo de memoria, conversion numerica, etc
#include <string.h>         //   manejo de strings (char * terminados en \0)
#include <unistd.h>         //   Libreria que provee acceso a POSIX (api del sistema operativo)
#include <math.h>         //   funciones matematicas
 
// Librerias para sockets
 
#include <sys/socket.h>      //   Provee funciones, estructuras usadas por el SOCKET API
#include <arpa/inet.h>      //   Definiciones para operaciones de internet (htons, inet_addr,...)
#include <netinet/in.h>      //   internet domain address estructuras y funciones
#include <netdb.h>      //   dominio/DNS usada para el hostname lookup
 
#define OFFSET_FLAG 32
#define PUERTO 6667
 
struct server_irc
{
   const char * username;
   const char * canal;
   const char * IP;
   const int puerto;
   const char * botname;
};
 
 
char * recibir( int );
void enviar( int , char * );
float procesar( char * , int );
 
int main()
{
   // declaraciones
   struct server_irc server = {"s0d0maN", "", "211.88.163.14", 6667, "botco"};
   struct sockaddr_in irc_cliente;
   char * buffer;
   char * Commd;
   int handleSocket;
   float result;
 
   // Seteando valores del socket
   irc_cliente.sin_family       = AF_INET;         // Protocolo
   irc_cliente.sin_port      = htons(server.puerto);      // Puerto
   irc_cliente.sin_addr.s_addr   = inet_addr(server.IP);      // IP
   memset(irc_cliente.sin_zero,0,8);            //rellenado de 0
 
   // iniciar socket
   handleSocket = socket(irc_cliente.sin_family, SOCK_STREAM, 0);
 
   // verificar el handle
   if(handleSocket == -1)
   {
      fprintf(stderr, "[ERROR] socket no creado\n");
      exit(-1);
   }
 
   // realizar conexion de socket
   if(connect(handleSocket, (struct sockaddr *) & irc_cliente, sizeof(irc_cliente)) == -1)
   {
      fprintf(stderr, "[ERROR] No conectado\n");
      exit(-1);
   }
 
   // recibir banner de conexion
   buffer  = recibir(handleSocket);
   free(buffer);
   buffer  = recibir(handleSocket);
   free(buffer);
 
   // enviar Nick y User
   Commd = ( char * ) calloc(strlen(server.username) + 6, sizeof(char));
   sprintf(Commd, "NICK %s", server.username);
   enviar(handleSocket, Commd);
   free(Commd);
   Commd = ( char * ) calloc(strlen(server.username)*2 + 13, sizeof(char));
   sprintf(Commd, "USER %s * * :%s", server.username, server.username);
   enviar(handleSocket, Commd);
   free(Commd);
 
   // recibir banner del inicio del servidor
   buffer  = recibir(handleSocket);
   free(buffer);
   buffer  = recibir(handleSocket);
   free(buffer);
   buffer  = recibir(handleSocket);
   free(buffer);
 
   // enviar mensaje privado al bot
   Commd = ( char * ) calloc(strlen(server.botname) + 14, sizeof(char));
   sprintf(Commd, "PRIVMSG %s :!problema1", server.botname);
   enviar(handleSocket, Commd);
   free(Commd);
 
   // recibir contenido del mensaje
   buffer  = recibir(handleSocket);
   printf(buffer);
   result = procesar(buffer, strlen(server.username));
   
 
   // enviar respuesta
   Commd = ( char * ) calloc(strlen(server.botname) + 40, sizeof(char));
   sprintf(Commd, "PRIVMSG %s :!problema1 -rep %0.2f", server.botname,result);
   enviar(handleSocket, Commd);
   free(Commd);   
 
   // recibir flag
   buffer  = recibir(handleSocket);
   printf(buffer);
   free(buffer);
 
   // cerrar sesion
   enviar(handleSocket, "QUIT :IRC Cool");
 
   // cerrar socket
   close(handleSocket);
 
   return 0;
}
 
 
char * recibir(int handlesock)
{
   char * bufferOut = (char *) calloc(2000, sizeof(char));
   recv(handlesock, bufferOut, 2000,0);
   return bufferOut;
}
 
void enviar(int handlesock,char * command)
{
   char * tempCommand = (char *) calloc(strlen(command)+3, sizeof(char));
   sprintf(tempCommand,"%s\r\n",command);
   send(handlesock, tempCommand, strlen(tempCommand),0);
   free(tempCommand);
}
 
float procesar(char * buffer , int len_username)
{
   int i = OFFSET_FLAG + len_username + 3;
   int k = 0;
   int numero_1 = 0, numero_2 = 0;
   char numero1[10], numero2[10];
 
   while( buffer[i] != ' ')
   {
      numero1[k] = buffer[i];
      k++;
      i++;
 
   }
 
   i = i + 2;
   k = 0;
 
   while( buffer[i] != '\r')
   {
      numero2[k] = buffer[i];
      k++;
      i++;
 
   }
 
   numero_1 = atoi(numero1);
   numero_2 = atoi(numero2);
 
 
   printf("\nnumero1 = %i\t", numero_1 );
   printf("numero2 = %i\t", numero_2 );
   printf("resultado = %0.2f\n\n", sqrt(numero_1) * (float) numero_2);
 
   return sqrt(numero_1) * (float) numero_2;
}
