
#include <infrarrojo.h>
infrarrojo estado_1(48);
int VALOR_1; 
int led_estado_1;


void setup()
{
  Serial.begin(9600);
}

void loop() 
{
  Serial.println(estado_1.lectura(VALOR_1));
  delay(100); 

}
