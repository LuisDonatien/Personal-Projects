library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity FSM_tb is
end FSM_tb;

architecture Behavioral of FSM_tb is
       signal  CLK,CLK100 :  std_logic;
       signal SCL_in,SCL_inpin,SCL_inpin1,SCL_inpin2 :  std_logic; -- Async in CLK.
       signal SCL_out : std_logic; --Sincronized SCL
       signal SdCLK :  std_logic;
        signal RESET :  std_logic;
        signal SDA:  std_logic;
        signal DATAREAD :  std_logic_vector(7 downto 0);
COMPONENT I2C_ReceiveSCL
  Port ( 
        CLK: in std_logic;
        SCL_in : in std_logic; -- Async in CLK.
        SCL_out : out std_logic; --Sincronized SCL
        SdCLK : out std_logic
  );
END COMPONENT;

COMPONENT I2CFsm_Slave
  Port (
  SCL : in std_LOGIC;
  CLK_DATA : in std_logic; --CLK for changing data.
  RESET : in std_logic;
  SDA: inout std_logic;
  DATAREAD : out std_logic_vector(7 downto 0)
   );
END COMPONENT;
constant  CLK100Mhz : time := 1 sec / 100_000_000; --Clock period 100MHz  
constant  CLK100Khz : time := 1 sec / 100_000; --Clock period 100MHz   
begin

I2C_uut: I2C_ReceiveSCL
PORT  MAP(
        CLK =>CLK,
        SCL_in => SCL_in,
        SCL_out =>SCL_out,
        SdCLK =>SdCLK
);
I2C_Fs: I2CFsm_Slave
PORT MAP(
  SCL =>SCL_out,
  CLK_DATA=>SdCLK,
  RESET=>RESET,
  SDA=>SDA,
  DATAREAD=>DATAREAD
   );
RESET<= '1' , '0' after 1 ms ;
SCL_inpin<='1','0' after 1ms +15us;
SCL_inpin1<='0','1' after 1 ms+204us ,'0' after 7 ms + 300us;
--SDA<='1' , '0' after 1 ms+10us ,'1', after 1 ms + 10 us;
SCL_in<= '1' when SCL_inpin='1' else
        '1' when SCL_inpin1='1' else
            CLK100;
 clock : process
    begin 
        CLK <= '0';
        wait for 0.5*CLK100Mhz;
        CLK <= '1' ;
        wait for 0.5*CLK100Mhz;
end process;

 clock100khz : process
    begin 
        CLK100 <= '0';
        wait for 0.5*CLK100khz;
        CLK100 <= '1' ;
        wait for 0.5*CLK100khz;
end process;


process 
begin 
wait for 1ms+ 10 us;
SDA<= '0' ;
wait for 15 us;
SDA<='0';
wait for 10 us;
SDA<='0';
wait for 10 us;
SDA<= '0' ;
wait for 10 us;
SDA<='0';
wait for 10 us;
SDA<='1';
wait for 10 us;
SDA<='1';
wait for 10 us;
SDA<='1';
wait for 10 us;
SDA<='1';
wait for 10 us;
SDA<='0';
wait for 1ms;
--wait for 10 us;
--SDA<='1';
--wait for 8 us;
end process;
end Behavioral;
