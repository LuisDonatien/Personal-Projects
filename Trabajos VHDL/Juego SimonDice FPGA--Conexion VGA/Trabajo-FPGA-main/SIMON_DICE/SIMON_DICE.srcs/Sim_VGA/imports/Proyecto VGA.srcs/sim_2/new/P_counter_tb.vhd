----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 26.11.2020 15:12:16
-- Design Name: 
-- Module Name: P_countclk_tb - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
entity P_countclk_tb is
end P_countclk_tb;
architecture Behavioral of P_countclk_tb is
    signal CLK   : std_logic;
    signal RESET :  std_logic;
    signal NEW_PXL :  std_logic;
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
    wait for 7ns;
    RESET <= '1';
           wait for 50 ms;
    assert false
 		report "[SUCCESS]: simulation finished."
	 	severity failure;
end process;

end Behavioral;