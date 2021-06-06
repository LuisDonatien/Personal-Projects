library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity DisP_CLK_tb is
end DisP_CLK_tb;
architecture Behavioral of DisP_CLK_tb is
    signal RESET :  std_logic;
    signal CLK :  std_logic;
    signal DisplayAN : std_logic_vector(0 to 7);
    signal Displaycode :  std_logic_vector(3 downto 0);

COMPONENT Display_CLK
port(
    RESET : in std_logic;
    CLK : in std_logic;
    DisplayAN :out std_logic_vector(0 to 7);
    Displaycode : out std_logic_vector(3 downto 0) 
);
END COMPONENT;
    constant CLK_PERIOD : time := 1 sec / 100_000_000; --Clock period 100MHz  
begin

uut : Display_CLK PORT MAP(
    RESET => RESET,
    CLK => CLK,
    DisplayAN => DisplayAN,
    Displaycode => Displaycode
);
RESET <= '1' after 10 ms , '0' after 11 ms ;


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