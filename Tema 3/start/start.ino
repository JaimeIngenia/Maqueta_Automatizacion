//BOTÓN CON AUTOSOSTENIMIENTO Y PULLDOWN
//SE PRENDE O APAGA DISPOSITIVO CON EL MISMO BOTÓN

int estado = 0;                                            //Guarda estado del botón
int estadoAnterior = 0;                                    //Guarda estado anterior del botón (para que se lea bien pulso)
int salida = 0;                                            //Guarda estado del Led

void setup() {
  
   pinMode (48, INPUT_PULLUP);
   Serial.begin(9600);

}

void loop() {

  estado = digitalRead(48);
  if((estado == HIGH) && (estadoAnterior == LOW)) 
  {
    salida = 1 - salida;                                   //Modifica el estado de la variable salida
    delay (20);                                            //Evitar el rebote del pulsador
  }
  estadoAnterior = estado;                                //Guarda el valor actual 



                                                                                                              
  if (salida == 1)
  {
    Serial.println("Boton presionado");
  }
  if (salida ==0) 
  {
    Serial.println("Boton en espera");
  }
}
