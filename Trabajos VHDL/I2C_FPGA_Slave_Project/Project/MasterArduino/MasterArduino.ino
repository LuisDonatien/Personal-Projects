// Arduino master 
#include <Wire.h>
uint8_t value=0;    


#define    MPU9250_ADDRESS            0x68

//Funcion auxiliar lectura
void I2Cread(uint8_t Address, uint8_t Register, uint8_t Nbytes, uint8_t* Data)
{
   Wire.beginTransmission(Address);
   Wire.write(Register);
   Wire.endTransmission();

   Wire.requestFrom(Address, Nbytes);
   uint8_t index = 0;
   while (Wire.available())
      Data[index++] = Wire.read();
}

void setup(){
  Serial.begin(115200);
  Wire.begin(); // join I2C bus as the master
value=0;

}

void loop(){
//  int readval;
  Wire.beginTransmission(0x07); // informs the bus that we will be sending data to slave device(0x07)
  Wire.write(value);        // send value
  Wire.endTransmission();    
 Serial.print("Byte send to FPGA: ");
 Serial.print(value);
 Serial.print("        ");
value++;
    
  uint8_t buf1[2];
     I2Cread(MPU9250_ADDRESS, 0x41, 2, buf1);
    //Convertir registro temperatura.
    int16_t temp= (buf1[0] << 8 | buf1[1]);
    float temp2=(float) (temp-831.455) / 333.87 + 21.0;
     Serial.print("I2C Sensor Temperature: ");
     Serial.print(temp2, DEC);

   Serial.println("");


delay(100);
}
