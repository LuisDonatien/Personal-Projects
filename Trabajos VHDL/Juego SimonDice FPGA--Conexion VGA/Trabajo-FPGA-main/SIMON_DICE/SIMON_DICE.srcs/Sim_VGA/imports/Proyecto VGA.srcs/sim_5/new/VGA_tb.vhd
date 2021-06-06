library IEEE;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

library WORK;
use WORK.VGA_PKG.ALL; 

entity VGA_tb is
end entity;

architecture behavioral of VGA_tb is
   signal CLK      :  STD_LOGIC;
   signal RESET    :  STD_LOGIC;
   signal PXL_NUM  :  std_logic_vector(9 downto 0);
   signal SQUARE   : std_logic_vector(0 to 4);
   signal LINE_NUM :  std_logic_vector(9 downto 0);
   signal RED      :  std_logic_vector(3 downto 0); 
   signal BLUE     :  std_logic_vector(3 downto 0); 
   signal GREEN    :  std_logic_vector(3 downto 0);
   signal VISIBLE  :  std_logic;
   signal HSYNCH   :  STD_LOGIC;
   signal VSYNCH   :  STD_LOGIC; 
   
COMPONENT VGA
PORT(
    CLK         : IN STD_LOGIC;
    RESET       : IN STD_LOGIC;
    SQUARE      : IN STD_LOGIC_VECTOR(0 to 4);
    PXL_NUM     : OUT std_logic_vector(9 downto 0);
    LINE_NUM    : OUT std_logic_vector(9 downto 0);
    RED         : OUT std_logic_vector(3 downto 0); 
    BLUE        : OUT std_logic_vector(3 downto 0); 
    GREEN       : OUT std_logic_vector(3 downto 0);
    VISIBLE     : OUT std_logic;
    HSYNCH      : OUT STD_LOGIC;
    VSYNCH      : OUT STD_LOGIC
); 
END COMPONENT;

    constant CLK_PERIOD : time := 1 sec / 100_000_000; --Clock period 100MHz   
begin

uut : VGA PORT MAP (
    CLK => CLK,
    RESET => RESET,
    PXL_NUM => PXL_NUM,
    LINE_NUM => LINE_NUM,
    SQUARE => SQUARE,
    RED => RED,    
    BLUE => BLUE,
    GREEN => GREEN,  
    VISIBLE => VISIBLE,   
    HSYNCH => HSYNCH,    
    VSYNCH => VSYNCH
);
 
 SQUARE <="10000" ,
           "01001" after 5ms,
           "00001" after 9ms ;
           
 clock : process
    begin 
        CLK <= '0';
        wait for 0.5*CLK_PERIOD;
        CLK <= '1' ;
        wait for 0.5*CLK_PERIOD;
end process;

temp : process
    begin
    RESET <= '1';
    wait for 100 ns;
    RESET <= '0';
     wait for 50 ms;
    assert false
 		report "[SUCCESS]: simulation finished."
	 	severity failure;
end process;
end architecture;
