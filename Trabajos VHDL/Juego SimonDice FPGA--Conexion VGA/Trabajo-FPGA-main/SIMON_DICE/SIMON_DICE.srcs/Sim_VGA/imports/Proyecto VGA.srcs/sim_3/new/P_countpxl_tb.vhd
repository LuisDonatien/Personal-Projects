library IEEE;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

entity P_countpx_tb is
end P_countpx_tb;

architecture Behavioral of P_countpx_tb is

    signal CLK   : std_logic;
    signal RESET :  std_logic;
    signal NEW_PXL :  std_logic;
    signal HSYNCH :  std_logic;
    signal VISIBLE_PXL :  std_logic;
    signal NEW_LINE :  std_logic;
    signal CONT_PXL : std_logic_vector(9 downto 0);   
    
    
COMPONENT P_cont_px
  Port( 
    CLK : in std_logic;
    RESET : in std_logic;
    NEW_PXL : in std_logic;
    HSYNCH : out std_logic;
    VISIBLE_PXL : out std_logic;
    NEW_LINE : out std_logic;
    CONT_PXL : out std_logic_vector(9 downto 0)
  );
END COMPONENT;
component P_countclk 
    port(
        CLK  : in std_logic;
        RESET : in std_logic;
        NEW_PXL : out std_logic
    );
end component ;

constant CLK_PERIOD : time := 1 sec / 100_000_000; --Clock period 100MHz

begin
 uut : P_countclk 
port map(
    CLK =>CLK,
    RESET => RESET,
    NEW_PXL => NEW_PXL
);   

uut2 : P_cont_px 
    port map (
    CLK => CLK,
    RESET => RESET,
    NEW_PXL => NEW_PXL,
    HSYNCH => HSYNCH,
    VISIBLE_PXL => VISIBLE_PXL,
    NEW_LINE  => NEW_LINE,
    CONT_PXL => CONT_PXL
    );
    
    clock : process
    begin 
        CLK <= '0';
        wait for 0.5*CLK_PERIOD;
        CLK <= '1' ;
        wait for 0.5*CLK_PERIOD;
end process;

temp : process
    begin
    RESET <= '0';
    wait for 100 ns;
    RESET <= '1';
     wait for 50 ms;
    assert false
 		report "[SUCCESS]: simulation finished."
	 	severity failure;
end process;
end architecture;