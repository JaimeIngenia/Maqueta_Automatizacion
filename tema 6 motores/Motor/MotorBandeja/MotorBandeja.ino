#define PIN_MOTOR_1_EN 9                                                                                                                      //BANDEJA PUERTA
#define PIN_MOTOR_1_N1 10                                                                                                                     //BANDEJA PUERTA
#define PIN_MOTOR_1_N2 11                                                                                                                     //BANDEJA PUERTA
#define MOTOR_1_STOP digitalWrite(PIN_MOTOR_1_EN, LOW);digitalWrite(PIN_MOTOR_1_N1,LOW);digitalWrite(PIN_MOTOR_1_N2,LOW)                      //BANDEJA PUERTA
#define MOTOR_1_FORWARD   digitalWrite(PIN_MOTOR_1_EN, HIGH);digitalWrite(PIN_MOTOR_1_N1,LOW);digitalWrite(PIN_MOTOR_1_N2,HIGH)               //BANDEJA PUERTA
#define MOTOR_1_BACKWARD   digitalWrite(PIN_MOTOR_1_EN, HIGH);digitalWrite(PIN_MOTOR_1_N1,HIGH);digitalWrite(PIN_MOTOR_1_N2,LOW)              //BANDEJA PUERTA

void setup() 
{
  Serial.begin(9600);
  pinMode(PIN_MOTOR_1_EN, OUTPUT);      //BANDEJA
  pinMode(PIN_MOTOR_1_N1, OUTPUT);      //BANDEJA
  pinMode(PIN_MOTOR_1_N2, OUTPUT);      //BANDEJA

}

void loop() 
{

      MOTOR_1_BACKWARD; //abrir BANDEJA 
      delay(1000);
      MOTOR_1_STOP;
      delay(6000);   
  
}
