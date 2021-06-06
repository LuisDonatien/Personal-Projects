library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;


entity Display_CLK is
  Port (
    RESET : in std_logic;
    CLK : in std_logic;
    DisplayAN :out std_logic_vector(0 to 7);
    Displaycode : out std_logic_vector(3 downto 0)
   );
end Display_CLK;

architecture Behavioral of Display_CLK is
signal ticks : unsigned(31 downto 0);
signal display_c : unsigned (3 downto 0);
begin

    timer_clk : process(CLK,RESET)
    variable disp : unsigned(3 downto 0);
 begin
    if RESET = '1' then
    disp := TO_UNSIGNED(0,4);
    ticks<= TO_UNSIGNED(0,32);
    elsif falling_edge(CLK) then          
            if ticks=TO_UNSIGNED((5E4),32) then
                ticks<= TO_UNSIGNED(0,32);
                    if disp < 7 then
                    disp := disp + 1;
                    else
                    disp := TO_UNSIGNED(0,4);
                    end if;            
                else
                ticks<=ticks+1;
                end if;
            
            if disp = 0 then
                DisplayAN <= "01111111";
            elsif disp = 1 then 
                DisplayAN <= "10111111";
            elsif disp = 2 then 
                DisplayAN <= "11011111";   
            elsif disp = 3 then 
                DisplayAN <= "11101111";
            elsif disp = 4 then 
                DisplayAN <= "11110111";
            elsif disp = 5 then 
                DisplayAN <= "11111011"; 
            elsif disp = 6 then 
                DisplayAN <= "11111101"; 
            elsif disp = 7 then 
                DisplayAN <= "11111110";
            else
                DisplayAN <= "00000000"; 
            end if;
    display_c <= disp;                                   
    end if;
end process;

Displaycode <= std_logic_vector(display_c);
end Behavioral;