#include <infrarrojo.h>                  //SENSORES DE PRESENCIA      
infrarrojo estado_1(8);                 //S4 (sensor final banda 4)

//Pines de lectura de finales de carrera
int VALOR_1;                             //Recibe dato S1


int led_estado_1;                        // Variable de estado de sensor de arranque



void setup()
{
  Serial.begin(9600);
}

void loop()
{

Serial.println(estado_1.lectura(VALOR_1));
delay(100);//GENERA UN TIEMPO PARA LEER E IMPRIMIR EN PUERTO SERIE

}
