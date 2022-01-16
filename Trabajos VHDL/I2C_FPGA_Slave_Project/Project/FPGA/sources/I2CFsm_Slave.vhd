library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_arith.all;

entity I2CFsm_Slave is
  Port (
  SCL : in std_LOGIC;
  CLK_DATA : in std_logic; --CLK for changing data.
  RESET : in std_logic;
  START : in std_logic; --When it s '1' inform that the i2c scl are enable and prepare to start
  SDA: inout std_logic;
  DATAREAD : out std_logic_vector(7 downto 0);   --Data received from the Master I2C
  DATAWRITE: in std_logic_vector(7 downto 0)     --Data sent to the Master I2C
   );
end I2CFsm_Slave;

architecture Behavioral of I2CFsm_Slave is
type state is (state0_idle,state1_start,state2_ReceiveSlaveAdress,state3_ack1,state4_ReadData,state5_ack2,state6_stop,state7_WriteData);
signal current_state,next_state:state;
signal dclk , Slck,DATA , flag,In_Condition: std_logic;
signal data_count : natural range 0 to 8 ;
signal delay:  natural range 0 to 8;  -- For 8 bites times
signal DATA_READ,ADRESS_READ,DATA_WRITE:std_logic_vector(7 downto 0):=(others=>'0');
signal RdWr_option : std_logic_vector(1 downto 0); --"00" Nothing , "01" Read , "10" Write

constant Slave_AdressREAD: std_logic_vector(7 downto 0):="00001110";  --Direction and the Read/write option "X07" last "0" is write on the slave fpga register
constant Slave_AdressWRITE: std_logic_vector(7 downto 0):="00001111";  --Direction and the Read/write option "X07" last "1" is write to the master.
begin

clk_fsm: process(CLK_DATA,RESET)
begin
    if RESET='1' then
        current_state<=state0_idle;
        data_count<=0;
        
    elsif rising_edge(CLK_DATA) then
        DATA_WRITE<=DATAWRITE; -- Introduce the requiered data at the starting comunication 
        if current_state=state0_idle AND START='1' then
            current_state<=next_state;
            data_count<=0;
        elsif data_count=(delay-1)  AND START='0'then
            if  IN_Condition='1' then
                current_state<=next_state;
                data_count <=0;
            else
                current_state<=state0_idle;
            end if;
        else
            data_count <=data_count +1;          
            
        end if; 
     end if;
end process;

out_state_fsm: process(data_count,current_state)    --This process is used to control the output slave FPGA on the SDA bus. To ensure to have a stable data to sample from master, the data is put following the data_count rising edge.
begin
    case current_state is
        when state0_idle =>
            SDA<='Z';
            delay<=1; 
            next_state<= state2_ReceiveSlaveAdress;
        when state2_ReceiveSlaveAdress =>
            SDA <='Z';
            delay<=8;
            next_state<=state3_ack1;   
        when state3_ack1 =>
            SDA<='0';
            delay<=1;
            if RdWr_option="01" then --Read Data from master
                next_state<= state4_ReadData;           
            elsif RdWr_option="10" then --Write Data to master
                next_state<= state7_WriteData;           
            else
                next_state<= state0_idle;   
            end if;
        when state4_ReadData => 
            SDA<='Z';
            delay<=8;   
            next_state<= state5_ack2;          
        when state7_WriteData => 
            SDA<=DATA_WRITE(7- data_count);
            delay<=8;   
            next_state<= state5_ack2;               
        when state5_ack2 =>    
            SDA<='Z';
            delay<=1;
            next_state<= state6_stop;
        when state6_stop => 
            SDA<= 'Z';
            delay<=1;
            next_state<= state0_idle;           
        when others=>
            SDA<='1';
            delay<=1;        
            next_state<= state0_idle;  
        end case;
end process;
InCLK_fsm: process(SCL) --This process is used to receive data from the SDA on the SLC rising edge

begin
    if rising_edge(SCL) then
       if current_state=state2_ReceiveSlaveAdress then
            ADRESS_READ(7- data_count)<=SDA;
            if data_count=7 AND Slave_AdressREAD=ADRESS_READ(7 downto 1) & SDA then
                IN_Condition<='1';
                RdWr_option<="01";
            elsif data_count=7 AND Slave_AdressWRITE=ADRESS_READ(7 downto 1) & SDA then
                IN_Condition<='1';
                RdWr_option<="10";
            else
                IN_Condition<='0'; 
                RdWr_option<="00";           
            end if;           
       elsif current_state=state3_ack1 then
                IN_Condition<='1';
              --  DATAREAD<="11000001";
       elsif current_state=state4_ReadData then
            DATA_READ(7- data_count)<=SDA;
            if data_count=7 then
                flag<='1';
                IN_Condition<='1';
            else
                flag<='0';
                IN_Condition<='0';
            end if;
       elsif current_state=state7_WriteData then
            if data_count=7 then
                IN_Condition<='1';
            else
                IN_Condition<='0';
            end if;
        elsif current_state=state5_ack2 then
                IN_Condition<='1';
        elsif current_state=state6_stop then
                IN_Condition<='1';
        end if;
        if flag='1' then
            DATAREAD<=DATA_READ;
            flag<='0';
        end if;
    end if;
end process;
end Behavioral;
