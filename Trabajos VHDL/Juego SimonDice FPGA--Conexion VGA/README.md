# Trabajo-FPGA
# Objetivo del proyecto
**El siguiente trabajo se realizó en el contexto de la asignatura de Sistemas Electrónicos Digitales de la universidad.**

La implementación del juego popular SimonDice mediante la repetición de las secuencias mostradas por pantalla.
El entorno de desarrollo es la Placa de desarrollo FPGA Nexys 4 DDR Artix-7 de Digilent

![image](https://user-images.githubusercontent.com/62206349/120924240-e9a0e680-c6d2-11eb-8237-0b0ce9e3bd05.png)

En ella se procede a mostrar el nivel mediante los displays de 7 segmentos. 
La secuencia a introducir se realiza mediante los pulsadores disponibles en la placa de desarrolllo.
La secuencia a introducir es mostrada previamente en una pantalla por salida VGA con resolucion 640x480.

# --------Aportación Personal al Proyecto--------------
En este proyecto me encargué personalmente del desarrollo de los siguientes módulos:
- Debouncer (Módulo dedicado a la deteccion de rebotes durante la estabilización al pulsar un botón).
- FMS (Maquina de Estados de Moore dedicada a la gestion de los estados, niveles , y secuencias a mostrar en función del nivel).
- Protocolo Conexion VGA : La programacion de la conexion VGA para una resolucion 640x480 a 25 MHz.
- Displays 7 segmentos : Para mostrar el estado y niveles del juegos.
- Testbenches : Respectivos a los módulos mencionados anteriormente.

# --------Aportación del Resto del equipo---------------
Los demás integrantes del grupo realizaron el siguiente módulo:
- Deteccion de la secuencia introducida en función del nivel actual.
