#include "EmonLib.h"
#include <stdio.h>   

EnergyMonitor emon1;
const int CT_PIN = 0;          /* pino do sensor */


void setup()
{
          Serial.begin(9600);
/*emon1.current(1, 111.1); // Current: input pin, calibration.*/
}

void loop()
{

          double Corrente = emon1.calcCorrente(1480); // mede a corrente
          double Potencia = Corrente * 127.0; // calcula a potência multiplicando a corrente por 127 

          Serial.print("Corrente: ");
          Serial.print(Corrente); /* imprime a corrente */
          Serial.print(" A \t");
          Serial.print("Potencia: ");
          Serial.print(Potencia); /* imprime a potencia */
          Serial.print(" W");
          Serial.println();
          delay(2000);

}
