#define LED_ROJO 2                     //LED ROJO-->PESADO
#define LED_AZUL 3                     //LED AZUL-->LIVIANO
#define PIN_START  48                    // PULSADOR START

int estado_apagado = 0;                 //START
int estadoAnterior_apagado = 0;         //START
int estado = 0;                         //START
int estadoAnterior = 0;                 //START
int salida = 0;                         //START

void setup() 
{
  pinMode(LED_ROJO, OUTPUT);            //LEDS
  pinMode(LED_AZUL, OUTPUT);            //LEDS
  pinMode(PIN_START, INPUT_PULLUP);     //PULSADOR START
}

enum estados {  
  EST_ENCENDIDO,//
  EST_APAGADO,  //
  EST_DETECCION,//        //INICIO
  EST_CERRADO//
};

int estado_actual = EST_ENCENDIDO;
int estado_anterior = EST_APAGADO;

void loop() 
{
  arrancar();
  while (salida != 0)
  {
    switch (estado_actual)
    { 
      case EST_DETECCION:
        detectar_objeto();
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
void detectar_objeto()
{
  if (estado_actual == EST_DETECCION)
  {
      digitalWrite(LED_AZUL,HIGH);
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
