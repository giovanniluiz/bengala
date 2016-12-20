#include <Ultrasonic.h>

//Define os pinos do Arduino ligados ao Trigger e Echo
#define PINO_TRG  9
#define PINO_ECHO 8
#define PINO_TRG2 12
#define PINO_ECHO2 11
#define VIBRADOR 6
#define VIBRADOR2 5

//Inicializa o sensor ultrasonico nos pinos especificados
Ultrasonic ultrasonic(PINO_TRG, PINO_ECHO);
Ultrasonic ultrasonic2(PINO_TRG2, PINO_ECHO2);
int valPot = 0; 
float cmMsec,cmMsec2;

void setup()
{
	//Inicializa a serial
	pinMode(VIBRADOR, OUTPUT);
	pinMode(VIBRADOR2 , OUTPUT);
	Serial.begin(57600);
}

void loop()
{
	long microsec = ultrasonic.timing();
	long microsec2 = ultrasonic2.timing();
	//Atribui os valores em cm ou polegadas as variaveis
	cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
	cmMsec2 = ultrasonic2.convert(microsec2, Ultrasonic::CM);
  
	Serial.print("Centimetros 2: ");
	Serial.println(cmMsec2);
	Serial.print("Centimetros 1: ");
	Serial.println(cmMsec);
    if(cmMsec2 <100){
		digitalWrite(VIBRADOR, true); 
		delay(1000/cmMsec2);
		digitalWrite(VIBRADOR, false);
    }
    if(cmMsec <100){
		digitalWrite(VIBRADOR2, true); 
		delay(1000/cmMsec);
		digitalWrite(VIBRADOR2, false);
    }
  delay(10);
}