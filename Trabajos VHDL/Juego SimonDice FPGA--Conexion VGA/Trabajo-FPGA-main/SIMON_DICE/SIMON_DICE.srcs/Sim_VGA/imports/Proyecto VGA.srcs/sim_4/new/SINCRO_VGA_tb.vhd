library IEEE;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

library WORK;
use WORK.VGA_PKG.ALL; 

entity SINCRO_VGA_tb is
end SINCRO_VGA_tb ;

architecture Behavioral of SINCRO_VGA_tb is
    signal CLK : std_logic;
    signal RESET : std_logic;
    signal PXL_NUM : std_logic_vector(9 downto 0);
    signal LINE_NUM : std_logic_vector(9 downto 0);
    signal VISIBLE : std_logic;
    signal HSYNCH : std_logic;
    signal VSYNCH : std_logic;
    
    constant CLK_PERIOD : time := 1 sec / 100_000_000; --Clock period 100MHz
    
    COMPONENT SINCRO_VGA 
    PORT(
         CLK : in std_logic;
         RESET : in std_logic;
         PXL_NUM : out std_logic_vector(9 downto 0);
         LINE_NUM : out std_logic_vector(9 downto 0);
         VISIBLE : out std_logic;
         HSYNCH  : out std_logic;
         VSYNCH  : out std_logic        
    );
END COMPONENT;
begin

uut : SINCRO_VGA PORT MAP (
         CLK     => CLK,
         RESET   => RESET,
         PXL_NUM => PXL_NUM,
         LINE_NUM => LINE_NUM,
         VISIBLE => VISIBLE,
         HSYNCH => HSYNCH,
         VSYNCH => VSYNCH
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