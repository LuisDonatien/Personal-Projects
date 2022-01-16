library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity I2C_ReceiveSCL_tb is
--  Port ( );
end I2C_ReceiveSCL_tb;

architecture Behavioral of I2C_ReceiveSCL_tb is
       signal  CLK:  std_logic;
       signal  SCL_in,SCL_CLK , init:  std_logic; -- Async in CLK.
       signal  SCL_out : std_logic; --Sincronized SCL
       signal  START   :  std_logic; --Detect the start event and send it to the FSM
       signal SdCLK :  std_logic;
COMPONENT I2C_ReceiveSCL
  Port ( 
        CLK: in std_logic;
        SCL_in : in std_logic; -- Async in CLK.
        SCL_out : out std_logic; --Sincronized SCL
        START   : out std_logic; --Detect the start event and send it to the FSM
        SdCLK : out std_logic
  );
END COMPONENT;

constant  CLK100Mhz : time := 1 sec / 100_000_000; --Clock period 100MHz  
constant  CLK100Khz : time := 1 sec / 100_000; --Clock period 100MHz  
begin

uut: I2C_ReceiveSCL
PORT MAP(
      CLK =>CLK,
      SCL_in=>SCL_in,
      SCL_out=>SCL_out,
      START=>START,
      SdCLK =>SdCLK
);
 clock100Mhz : process
    begin 
        CLK <= '0';
        wait for 0.5*CLK100Mhz;
        CLK <= '1' ;
        wait for 0.5*CLK100Mhz;
end process;

init<='1' , '0' after 1 ms , '1' after 2ms , '0' after 3ms;
SCL_in<= '1' when init='1' else
        SCL_CLK;
 clock100khz : process
    begin 
        SCL_CLK <= '0';
        wait for 0.5*CLK100Khz;
        SCL_CLK <= '1' ;
        wait for 0.5*CLK100Khz;
end process;

end Behavioral;
