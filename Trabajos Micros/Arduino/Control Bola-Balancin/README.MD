# Proyecto Bola-Balancín
**Contexto:** Proyecto Personal realizado durante la pandemia (abril-mayo 2020).

A continuación se adjunta la imagen del proyecto(En los archivos del proyecto se puede encontrar un video de un ensayo satisfactorio).
![image](https://user-images.githubusercontent.com/62206349/120928080-82d7f900-c6e3-11eb-868a-e04c22eb927b.png)


Este proyecto se realizó durante la pandemia con el objetivo de dar un punto de vista práctico de las tecnicas de control aprendidas en el cuatrimestre anterior
en la asignatura de Regulación Automática. 

En este proyecto se distiguen los siguientes elementos:
- Estructura balancín: Por la cual rueda una bola.
- Servomotor : El encargado de variar la inclinación del balancín
- Sensor óptico laser : Este sensor mide por tiempo de vuelo la distancia a la que se encuentra la bola de este mismo.
- Arduino : Para este proyecto se utilizó como micro un arduino UNO el cual suple perfectamente las necesidades del proyecto.
-
Detalles en programación:
- Servomotor: Se declara de forma bastante sencilla usando la libreria Servo.h
- Sensor óptico de distancia se le realiza un filtrado debido a la oscilación de los valores entrantes. Realizando una media de cada X medidas configurable a gusto del programador.
- PID : El PID se programó utilizando las librerias estándar provistas por ARDUINO IDE. Las constantes Kp , Ki y Kd para este proyecto se introdujeron de forma manual, en busca de un compromiso entre oscilación y tiempo de establecimiento.


