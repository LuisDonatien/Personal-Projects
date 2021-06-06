library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity TOP_DEBOUNCER_tb is
end TOP_DEBOUNCER_tb;

architecture Behavioral of TOP_DEBOUNCER_tb is
  signal CLK     :   std_logic;
  signal ASYNC_IN :  std_logic;
  signal EDGE_OUT :  std_logic;
  
COMPONENT TOP_DEBOUNCER 
PORT(
  CLK : in std_logic;
  ASYNC_IN : in std_logic;
  EDGE_OUT : out std_logic
);
END COMPONENT;

    constant CLK_PERIOD : time := 1 sec / 100_000_000; --Clock period 100MHz 
begin

debouncer_t : TOP_DEBOUNCER PORT MAP(
  CLK     => CLK,
  ASYNC_IN => ASYNC_IN,
  EDGE_OUT => EDGE_OUT
);

ASYNC_IN <= '0' , '1' after 10ms , '0' after 10 ms + 10000ns , 
'1' after 13 ms , '0' after 23ms + 10ns , 
'1' after 24 ms , '0' after 36 ms ,
 '1' after 36ms + 14ns , '0' after 40 ms ,
  '1' after 49 ms + 14ns , '0' after 50 ms ;
 clock : process
    begin 
        CLK <= '0';
        wait for 0.5*CLK_PERIOD;
        CLK <= '1' ;
        wait for 0.5*CLK_PERIOD;
end process;
      
temp : process
    begin

    wait for 1sec ;
    assert false
 		report "[SUCCESS]: simulation finished."
	 	severity failure;
    end process;

end Behavioral;