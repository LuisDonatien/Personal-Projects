library IEEE;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

library WORK;
use WORK.VGA_PKG.ALL; 

entity P_count_line is
  Port (
    CLK : IN std_logic;
    RESET : IN std_logic;
    NEW_LINE : IN std_logic;
    VISIBLE_LINE : OUT std_logic;
    VSYNCH : OUT std_logic;
    CONT_LINE : OUT std_logic_vector(9 downto 0)
   );
end P_count_line;

architecture Behavioral of P_count_line is
        signal nline : unsigned (9 downto 0) := (others => '0');
begin
cont_linea : process(CLK,RESET)
    variable reg : integer;
    begin
        if RESET = '1' then 
            nline <= (others => '0');
            reg :=0;
        elsif falling_edge (CLK) then
            if NEW_LINE = '1' then
                reg:=reg+1;
            end if;
                if reg = 4 then
                    if nline < c_line_total-1 then 
                         nline <= nline + 1 ;
                         reg:=0;
                     else
                         nline <= (others => '0');
                         reg:= 0; 
                    end if;
                end if; 

        end if;    
end process;
    CONT_LINE <= std_logic_vector(nline);
    
    VISIBLE_LINE <= '0' when RESET = '1' else
                    '1' when nline < c_line_visible else
                    '0' when nline >= c_line_visible OR RESET='1' else
                    '0';
    VSYNCH <= '1' when  nline< c_line_2_fporch  else
                    '1' when nline>c_line_2_synch -1 else
                    '0';
    
end Behavioral;
