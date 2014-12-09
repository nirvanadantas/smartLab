#include <SPI.h>        //servidor
#include <Ethernet.h>  // Biblioteca utilizada para comunicação com o Arduino
#include <stdio.h>   /* pra input e output */
#include <sys/types.h> /* ele tem a definição dos system calls (como o read() e o write() */
#include <sys/socket.h> /* tem as definições das estruturas necessarias pro uso do socket */
#include <netinet/in.h>

// A linha abaixo permite definir o endereço físico (MAC ADDRESS) da placa de rede.
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
//byte ip[] = { 10, 18, 1, 299 };  // Define o endereço IP.
byte ip[] = { 0, 0, 0, 0 };   
   
EthernetServer server(2330);  // Porta onde estará aberta para comunicação Internet e Arduino.

String readString;
int Pin = 9;  //  Pino digital onde será ligado e desligado o LED.
int acessa;
void setup(){

  pinMode(Pin, OUTPUT);  // Define o Pino 9 como saída.
  Ethernet.begin(mac, ip);  // Chama o MAC e o endereço IP da placa Ethernet.
  server.begin();  //  Inicia o servidor que esta inserido junto a placa Ethernet.
  digitalWrite(Pin, HIGH);  // Liga LED.
  acessa = 1;
}

void loop(){
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
       
         char c = client.read();  
        if (c=='a'){
           digitalWrite(Pin, HIGH);  // Liga LED.
           acessa = 1;
        }
        else if (c=='b'){
           digitalWrite(Pin, LOW);  // Liga LED.
           acessa = 0;
        } else if (c=='c'){
          if (acessa==1)
              client.println("ACESA");
          else
              client.println("APAGADA");
            }
            client.println("Hello world");
      
        delay(1);
      }
    }
  }
}
