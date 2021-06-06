library IEEE;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

entity P_countclk is
  Port (
    CLK  : in std_logic;
    RESET : in std_logic;
    NEW_PXL : out std_logic
   );
end P_countclk;

architecture Behavioral of P_countclk is
        signal regout : std_logic;
begin
    contador_clk : process(CLK,RESET)
    variable reg : integer := 0;
        begin
            if RESET = '1' then 
                regout <= '0';
                reg := 0;
            elsif falling_edge(CLK) then 
                 if reg = 3 then
                    reg := 0;
                    regout <= '1';
                else 
                    reg := reg +1;
                    regout <= '0';
                end if;
            end if;
    end process;
    NEW_PXL <=  '0' when  RESET = '1' else    
                '0' when  regout= '0' else 
                '1' when  regout=  '1';  
end Behavioral;
