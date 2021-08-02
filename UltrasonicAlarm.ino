#include "SR04.h" //incluimos libreria del ultrasonidos
#define TRIG_PIN 10 //definimos el trig al pin 10
#define ECHO_PIN 11 //definimos el echo al pin 11
#define alarma 12 //definimos el pin de pitch

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);

long distancia;
long sonar_alarma = 300; // A que distancia suena la alarma (en centimetros)

void setup() {
   Serial.begin(9600);
   delay(1000);
   pinMode(alarma,OUTPUT); //hacemos constancia del pin alarma
}

void loop() {
   distancia=sr04.Distance();

//   Para testeo de distancia;
//
//   Serial.print(distancia);
//   Serial.println("cm");
//   delay(400);

   if(distancia <= 300) //si la distancia es menor o igual a 300cm sonara la alarma
   {
    analogWrite(alarma,1); //hacemos sonar la alarma con intensidad 1
   }

   else{
    digitalWrite(alarma,LOW); //apagamos la alarma
   }
}
