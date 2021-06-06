#define DEBUG(a) Serial.println(a);
 
void setup()
{
   Serial.begin(9600);
}
 
void loop()
   if (Serial.available() > 0)
   {
      String str = Serial.readStringUntil('\n');
     posicion = str.toInt();
      DEBUG(posicion);
      miservo.write(posicion);
}
