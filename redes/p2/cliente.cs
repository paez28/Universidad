    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;
    using System.Net;
    using System.Net.Sockets;
     
    namespace ircCtf
    {
        class Program
        {
            static void Main(string[] args)
            {
                string botInServer = "PepeGrillo";
                ClienteIrc ircclient = new ClienteIrc("213.56.152.135",6667,"s0d0maP");
     
                if(ircclient.SockIrc.Connected == true)
                {
                    Console.WriteLine(
                        "\nConectado {0} : {1} : {2}\n", 
                        ircclient.direccion,  
                        ircclient.puerto, 
                        ircclient.username
                    );
     
                    ircclient.Command(String.Format("NICK {0}",ircclient.username));
                    ircclient.Command(String.Format("USER {0} * * :{0}", ircclient.username));
     
                    for( int i = 0; i<5; i++)
                    {
                        ircclient.Recibir();
                    }
     
                    ircclient.Command(String.Format("PRIVMSG {0} :!ep1", botInServer));
                    ircclient.Recibir();
                    Console.Write("{0}",ircclient.recvString);
     
                    string[] segmentos = ircclient.recvString.Split(':');
                    string[] segmentos2 = segmentos[2].Split(':');
                    string[] tempNum = segmentos2[0].Split('/');
     
                    int num1 = int.Parse(tempNum[0]);
                    int num2 = int.Parse(tempNum[1]);
                    double result = Math.Sqrt(num1) * num2;
     
                    Console.WriteLine(String.Format("PRIVMSG {0} :!problema1 -rep {1}", botInServer, result.ToString("F").Replace(',', '.')));
                    ircclient.Command(String.Format("PRIVMSG {0} :!problema1 -rep {1}", botInServer, result.ToString("F").Replace(',', '.')));
                    ircclient.Recibir();
                    Console.Write("{0}", ircclient.recvString);
     
                    ircclient.SockIrc.Close();
     
                    Console.Read();
                }
     
            }
        }
     
        // clase ClienteIrc
        class ClienteIrc
        {
            public string direccion;
            public Int32 puerto;
            public Socket SockIrc;
            public string username;
            public string recvString;
            public string bot;
     
            public ClienteIrc(string ip, Int32 puerto, string username)
            {
                // inicializar datos
                this.direccion  = ip;
                this.puerto = puerto;
                this.username = username;
     
                try
                {
                    // inicializar socket
                    this.SockIrc = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                    IPEndPoint dire_socket = new IPEndPoint(IPAddress.Parse(this.direccion), this.puerto);
     
                    // realizar conexion
                    this.SockIrc.Connect(dire_socket);
                }
                catch
                {
                    Console.WriteLine("ERROR de conexion");
                }
            }
     
            public void Recibir()
            {
                byte[] respuesta = new byte[2000];
                int ret = this.SockIrc.Receive(respuesta);
     
                this.recvString = Encoding.ASCII.GetString(respuesta,0,ret);
            }
     
            public void Command(string command)
            {
                command += "\r\n";
                byte[] datasend = Encoding.ASCII.GetBytes(command);
                this.SockIrc.Send(datasend);
            }
     
            public void Cerrar()
            {
                this.Command("QUIT : IRC Rulez");
                this.recvString = "";
                this.puerto = 0;
                this.username = "";
                this.direccion = "";
                this.SockIrc.Close();
            }
        }
    }
     
