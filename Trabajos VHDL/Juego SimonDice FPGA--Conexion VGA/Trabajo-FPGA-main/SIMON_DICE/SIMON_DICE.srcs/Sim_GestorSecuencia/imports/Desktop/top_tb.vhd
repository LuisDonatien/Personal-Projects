library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity gestor_secuencia_tb is
end entity;

architecture test of gestor_secuencia_tb is

  -- Inputs
  signal B1, B2, B3, B4, B5, enable, clk, enable_comp : std_logic;
  signal nivel : std_logic_vector(1 downto 0);

  -- Outputs
  signal secuencia : std_logic_vector(9 downto 0);
  
  component gestor_secuencia is
  	port(
        B1        : in std_logic;
    	B2        : in std_logic;
    	B3        : in std_logic;
    	B4        : in std_logic;
    	B5        : in std_logic;
    	enable    : in std_logic;
        nivel     : in std_logic_vector(1 downto 0);
        clk       : in std_logic;
        secuencia : out std_logic_vector(9 downto 0);
        enable_comp : out std_logic
    );
  end component;
  
  constant CLK_PERIOD : time := 1 sec / 100_000_000;  -- Clock period
  
  begin
  
  -- Unit Under Test
  uut: gestor_secuencia
    port map (
      B1 => B1,
      B2 => B2,
      B3 => B3,
      B4 => B4,
      B5 => B5,
      enable => enable,
      clk => clk,
      nivel => nivel,
      secuencia => secuencia,
      enable_comp => enable_comp
    );
    
   clkgen: process
   begin
    CLK <= '0';
    wait for 0.5 * CLK_PERIOD;
    CLK <= '1';
    wait for 0.5 * CLK_PERIOD;
    end process;
      
    tester: process
  	begin
        B1 <= '0';
        B2 <= '0';
        B3 <= '0';
        B4 <= '0';
        B5 <= '0'; 
        enable <= '0';
        wait for 20 ns;
        nivel <= "01";
        enable <= '1';
        wait for 5 ns;
        B1 <= '1';
        wait for 5 ns;
        B1 <= '0';
        wait for 7 ns;
        enable <= '0';
        wait for 8 ns;
        enable <= '1';
        nivel <= "10";
        wait for 10 ns;
        B1 <= '1';
        wait for 6 ns;
        B1 <= '0';
        wait for 6 ns;
        B2 <= '1';
        wait for 10 ns;
        B2 <= '0';
    
    	wait for 50 ns;
    	assert false
    	  report "[SUCCESS]: simulation finished."
    	  severity failure;
  		end process;
  
  end architecture;