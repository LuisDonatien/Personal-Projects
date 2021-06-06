/********************************************************
 * PID Basic Example
 * Reading analog input 0 to control analog PWM output 3
 ********************************************************/
#include <PID_v1.h>
#include <Servo.h>
#include <Wire.h>
#include <VL53L0X.h>
#include <MedianFilter.h>
VL53L0X sensor;

Servo miservo;
MedianFilter test(10,0);                                            
int Servoposicion;
int Ultimadistancia,Distancia;

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp=4 ,Ki=2.1, Kd=3.5;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  Serial.begin(9600);//iniciailzamos la comunicación
  Wire.begin();
  sensor.setTimeout(500);
  
  if (!sensor.init()){
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }

#if defined LONG_RANGE
  // lower the return signal rate limit (default is 0.25 MCPS)
  sensor.setSignalRateLimit(0.1);
  // increase laser pulse periods (defaults are 14 and 10 PCLKs)
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
#endif

#if defined HIGH_SPEED
  // reduce timing budget to 20 ms (default is about 33 ms)
  sensor.setMeasurementTimingBudget(20000);
#elif defined HIGH_ACCURACY
  // increase timing budget to 200 ms
  sensor.setMeasurementTimingBudget(200000);
#endif
 
  miservo.attach(9);                                            //Inicializo servo en el pin 9
  miservo.write(90);                                            //Su valor inicial sera 90 grados
  // Declaro en el pin 9(PWM) que va a estar cogido por "miservo"
  //initialize the variables we're linked to
  Setpoint = 20;                                                  
  myPID.SetOutputLimits(-30,30);                                //Max y min salida del Pid ser an -30 a 30 grados
 //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

void loop()
{
  
   float val=sensor.readRangeSingleMillimeters();
  test.in(val);                                                         //Aplico "filtro" a la medida de distancia
  val=test.out();
  Serial.print(19);
  Serial.print(",");
  Serial.print(val/10);
  Serial.print(",");
  Serial.print(20);
  Serial.print(",");
  Serial.println(21);
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  Input=val/10;
  myPID.Compute();
  //Enviamos serialmente el valor de la distancia
  Servoposicion=85+Output;
 miservo.write(Servoposicion);

 }
