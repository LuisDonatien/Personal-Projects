library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity TOP_DISPLAY_tb is
end TOP_DISPLAY_tb;
architecture Behavioral of TOP_DISPLAY_tb is
    signal CLK : std_logic;
    signal RESET :  std_logic;
    signal nivel :  std_logic_vector(3 downto 0);
    signal estado :  std_logic_vector(3 downto 0);
    signal DisplayAN :  std_logic_vector(0 to 7);
    signal displayseg :  std_logic_vector(6 downto 0);

COMPONENT TOP_DISPLAY
port(
    CLK : in std_logic;
    RESET : in std_logic;
    nivel    : in std_logic_vector(3 downto 0);
    estado   : in std_logic_vector(3 downto 0);
    DisplayAN : out std_logic_vector(0 to 7);
    displayseg : out std_logic_vector(6 downto 0) 
);
END COMPONENT;
    constant CLK_PERIOD : time := 1 sec / 100_000_000; --Clock period 100MHz  
begin

uut : TOP_DISPLAY PORT MAP(
    CLK => CLK,
    RESET => RESET,
    nivel => nivel,
    estado => estado,
    DisplayAN => DisplayAN,
    displayseg => displayseg
);
RESET <= '1' after 10 ms , '0' after 11 ms ;
estado <= "0100";
nivel <= "0011";

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
