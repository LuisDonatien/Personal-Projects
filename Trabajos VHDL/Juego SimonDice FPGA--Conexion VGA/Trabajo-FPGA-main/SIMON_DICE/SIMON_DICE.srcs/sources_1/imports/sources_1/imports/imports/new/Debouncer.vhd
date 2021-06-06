
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;

entity Debouncer is
  Port (
  CLK       : in std_logic;
  DEBOUNCER_IN : in std_logic;
  DEBOUNCER_OUT : out std_logic
   );
end Debouncer;

architecture Behavioral of Debouncer is
signal count : unsigned(20 downto 0); -- Mas o menos 10 ms
signal reg : std_logic;
begin

debouncer : process(CLK,DEBOUNCER_IN)
begin
    if DEBOUNCER_IN = '0' then 
        count <= TO_UNSIGNED(0,21);
        reg <= '0';
    elsif rising_edge(clk) then 
        if DEBOUNCER_IN = '1' then
            if count = TO_UNSIGNED(1E6,21) then   
                reg<= '1';
            else
                count <= count + 1;
            end if;    
        end if;
    end if;         
end process;
DEBOUNCER_OUT <= reg ; 
end Behavioral;
