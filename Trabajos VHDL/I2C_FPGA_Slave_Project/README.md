# I2C Slave FPGA Project
![Imagen Inicial I2c](https://user-images.githubusercontent.com/62206349/149641326-9ff2163f-3b0c-4be1-9822-385a5bdee8fb.png)
This personal project aims to increase my knowledge of interface protocols. In this case the chosen protocol is the I2C communication protocol. The objective is to emulate this protocol in vhdl and test its correct operation with an arduino master and other I2C devices connected in the same network.
## Components
1. Arduino UNO (Master I2C) 
2. FPGA Basys3 Xilinx (Slave I2C)
3. MPU-9250 (Slave I2C (Read Temperature Register))
4. Level Shifter 5v-3.3v 


### Descriptions
+ **Arduino UNO**: has the purpose of being the master on the I2C comunication. It has the followings task: 
    + Write a unsigned byte number to the FPGA.
    + Read the temperature from the MPU-9250 register device.
                                                                                                            
+ **FPGA BASYS3**: The FPGA act has a slave on the I2C comunication. The HDL files are write on VHDL format. This is the structure of components inside the Top.vhd.
    + _Top.vhd_ : Use to unify all the separate components.
      + _I2CFsm_Slave.vhd_ : This component is the FSM which controls the diferents phase of the I2C slave protocole (start,ack,receive,read,write).
      + _I2C_ReceiveSCL.vhd_ : This component it´s use to take the SCLK signal generate from the master. We also declare another component called _SYNCHRNZR.vhd_. The  main purpose of this last component is to synchronise the asynchronous input signal(SCLK). Finally, another signal is generate "SdCLK" to create a Clock signal out-of-phase SCLK which allow us to make change before the rising edge of the I2C clock.
+ **MPU-9250**: The arduino UNO master reads from this device the register of temperature 0x41 and 0x42 (2 bytes).
+ **Level Shifter**: The FPGA only accepts a 3.3v logic input/output and the Arduino Uno outputs 5V on the I2C output. To solve this problem, a level shifter is used to convert the voltage.

## Operating Image.
The following image shows the Arduino UNO reading from the temperature sensor and sending a byte number to the FPGA. You can also see that the FPGA displays the number sent from the Master through the 8 LEDs.
![Imagen I2c](https://user-images.githubusercontent.com/62206349/149642828-08f16a13-a1dd-4b68-8109-58dff67b7b00.png)

The FPGA slave HDL module has also the capacity to perform a read operation from the Master but in this case is not use it.
