#include <Servo.h>
#define DEBUG(a) Serial.println(a);
Servo miservo;

int posicion=0;                       //Declaro la variable que guardara los angulos de posicion que quiero que escriba el servo.
void setup() {
/////////////////////////////////////////////////////////////////////////////////// Coloco aqui mi codigo de setup,corre esto codigo una vez al principio.
miservo.attach(9);                 // Declaro en el pin 9(PWM) que va a estar cogido por "miservo".
Serial.begin(9600);
}

void loop() {
/////////////////////////////////////////////////////////////////////////////////// Coloco aqui mi codigo main,corre esto en bucle.
for(posicion=60;posicion<=120;posicion++){               //Hago un bucle for que me sume la posicion hasta 180 
  miservo.write(posicion);
  delay(10);                                            //Espera de 15ms hasta volver a realizar el bucle for
}
for(posicion=120;posicion>=60;posicion--){             //Hago un bucle for que me sume la posicion hasta 180
  miservo.write(posicion);
  delay(10);                                            //Espera de 15ms hasta volver a realizar el bucle for
}
  // if (Serial.available() > 0)
 //  {
   //   String str = Serial.readStringUntil('\n');
    // posicion = str.toInt();
    //  DEBUG(posicion);
      //miservo.write(posicion);
}
