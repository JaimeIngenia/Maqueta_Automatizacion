#define PIN_MOTOR_1_EN 9                                                                                                                      //BANDEJA PUERTA
#define PIN_MOTOR_1_N1 10                                                                                                                     //BANDEJA PUERTA
#define PIN_MOTOR_1_N2 11                                                                                                                     //BANDEJA PUERTA
#define MOTOR_1_STOP digitalWrite(PIN_MOTOR_1_EN, LOW);digitalWrite(PIN_MOTOR_1_N1,LOW);digitalWrite(PIN_MOTOR_1_N2,LOW)                      //BANDEJA PUERTA
#define MOTOR_1_FORWARD   digitalWrite(PIN_MOTOR_1_EN, HIGH);digitalWrite(PIN_MOTOR_1_N1,LOW);digitalWrite(PIN_MOTOR_1_N2,HIGH)               //BANDEJA PUERTA
#define MOTOR_1_BACKWARD   digitalWrite(PIN_MOTOR_1_EN, HIGH);digitalWrite(PIN_MOTOR_1_N1,HIGH);digitalWrite(PIN_MOTOR_1_N2,LOW)              //BANDEJA PUERTA

#define LED_ROJO 2                     //LED ROJO-->PESADO
#define LED_AZUL 3                     //LED AZUL-->LIVIANO
#define PIN_START  48                    // PULSADOR START

int estado = 0;                         //START
int estadoAnterior = 0;                 //START
int salida = 0;                         //START

#include <infrarrojo.h>                 //SENSORES DE PRESENCIA      
infrarrojo estado_1(8);                 //SENSORES DE PRESENCIA 
int VALOR_1;                            //SENSORES DE PRESENCIA 
int led_estado_1;                       //SENSORES DE PRESENCIA 

void setup() 
{
  pinMode(PIN_MOTOR_1_EN, OUTPUT);      //BANDEJA
  pinMode(PIN_MOTOR_1_N1, OUTPUT);      //BANDEJA
  pinMode(PIN_MOTOR_1_N2, OUTPUT);      //BANDEJA
  Serial.begin(9600);                 
  pinMode(LED_ROJO, OUTPUT);            //LEDS
  pinMode(LED_AZUL, OUTPUT);            //LEDS
  pinMode(PIN_START, INPUT_PULLUP);     //PULSADOR START
}

enum estados {  
  EST_ENCENDIDO,//1
  EST_APAGADO,  //0
  EST_CERRAR_PUERTA, 
  EST_DETECCION,//2                        //INICIO
  EST_CERRADO
};
int estado_actual = EST_ENCENDIDO;
int estado_anterior = EST_APAGADO;
int estado_puerta=0;  //0cerrado 1abierto

void loop() 
{
  arrancar();
  Serial.println(estado_actual);
  while (salida != 0)
  {
    switch (estado_actual)
    { 
      case EST_DETECCION:
        Serial.println("2.ABRIENDO LA HP PUERTA");
        detectar_objeto();
        break;
      case EST_CERRAR_PUERTA:
        Serial.println("2.CERRANDO LA HP PUERTA");
        cerrando_la_puerta();
        break;
      case EST_CERRADO:
        cerrar();
        break;  
      
      default:
        break;  
    }
  }
}








//*******************************************************
//FUNCIÓN PULSADOR SOSTENIDO START
void arrancar()
{
  if (estado_actual == EST_ENCENDIDO)
  {
    estado = digitalRead(PIN_START);
    if((estado == HIGH)&&(estadoAnterior == LOW))
    {
      salida = 1;
      delay (20);            
      estado_actual = EST_DETECCION;   
    }
    estadoAnterior = estado;
  }  
}
//*******************************************************
//FUNCION DETECTAR OBJETO
void detectar_objeto(){
  if (estado_actual == EST_DETECCION)
  {
    Serial.println(estado_1.lectura(VALOR_1));
    Serial.println(estado_puerta);
    if(estado_1.lectura(VALOR_1) == 0)
    {
      MOTOR_1_BACKWARD; //abrir BANDEJA
      delay(500);
      MOTOR_1_STOP; //ADELANTE
      estado_puerta=1;
      estado_actual = EST_CERRAR_PUERTA;   
    }
  }    
}
//*******************************************************
//FUNCION CERRAR PUERTA
void cerrando_la_puerta(){
  if (estado_actual == EST_CERRAR_PUERTA)
  {
    Serial.println(estado_1.lectura(VALOR_1));
    Serial.println(estado_puerta);
    if ((estado_1.lectura(VALOR_1) == 1)&&(estado_puerta==1))
    {
      MOTOR_1_FORWARD; //CERRAR BANDEJA
      delay(500);
      MOTOR_1_STOP; //ADELANTE
      estado_puerta=0;
      estado_actual = EST_CERRADO;   
    }
  }    
}
//*******************************************************
//FUNCIÓN ENCENDER LED
void encender_led()
{
  if (estado_actual == EST_DETECCION)
  {
      digitalWrite(LED_ROJO,HIGH);
      estado_actual = EST_CERRADO;     
  }
}
//*******************************************************
//FUNCIÓN CERRAR
void cerrar()
{
  if (estado_actual == EST_CERRADO)
  {
   estado_actual = EST_DETECCION;
  }
}
