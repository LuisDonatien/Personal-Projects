library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;

entity BLOQUE_COMPARADOR_TESTBENCH is
end;

architecture bench of BLOQUE_COMPARADOR_TESTBENCH is


  signal Secuencia : std_logic_vector(24 downto 0);
  signal Nivel    : std_logic_vector(3 downto 0);
  Signal Enable         : std_logic;
  signal Salida     : std_logic_vector(1 downto 0);
  signal  CLK      : std_logic;	 
        
 component BLOQUE_COMPARADOR
   --generic(    WIDTH: positive := 10       );
   port (
	   Secuencia      : in std_logic_vector(24 downto 0);
       CLK            : in std_logic;	 
       Nivel          : in std_logic_vector(3 downto 0);
       Enable         : in std_logic;
       Salida         : out std_logic_vector(1 downto 0)     
       );
 end component;

constant CLK_PERIOD : time := 1 sec / 100_000_000;

begin
  uut: BLOQUE_COMPARADOR 
  port map ( 
  		 Secuencia => secuencia,   
         CLK       => clk,        
         Salida    => salida,
         Nivel     => Nivel,
         Enable => Enable
        );
        
 clkgen: process
    begin 
    	CLK <= '0';
        wait for 0.5 * CLK_PERIOD;
        CLK <= '1';
        wait for 0.5 * CLK_PERIOD;
    end process;
    
 tester:process
   begin 
   secuencia <= "0000000000000000000000000" , "0000000000000000000000001" after 50ns, "0000000000000000000000010" after 100ns, "0000000000000001000001000" after 150 ns,  "0000000000000010010010000" after 200 ns, "0000000010010001000000100" after 250 ns, "1000001000100000010000001" after 300 ns;
   Nivel     <= "0000", "0001" after 50 ns, "0010" after 150 ns, "0011" after 200ns, "0100" after 250ns, "0101" after 300ns;
   Enable    <= '0', '1' after 50 ns;
   
 	 wait for 35*CLK_PERIOD;
 	 --wait for 350ns;
  	 assert false
       report "[SUCCESS]: simulation finished."
            severity failure;
     end process;

end architecture;
