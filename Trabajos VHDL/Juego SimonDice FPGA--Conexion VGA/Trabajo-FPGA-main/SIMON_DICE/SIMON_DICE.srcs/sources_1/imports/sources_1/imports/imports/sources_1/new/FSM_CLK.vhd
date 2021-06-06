
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;
entity FSM_CLK is
  Port (
    CLK : in std_logic;
    NIVEL_IN : in std_logic_vector(3 downto 0); ---
    ENABLE : in std_logic;
    TIMEOUT : out std_logic  
   );
end FSM_CLK;

architecture Behavioral of FSM_CLK is
signal ticks : unsigned(31 downto 0);
signal nivel_c : unsigned (3 downto 0);
begin

    timer_clk : process(CLK,ENABLE)
    variable reg : std_logic;
 begin
    if ENABLE = '0' then
    ticks <= TO_UNSIGNED(0,32);
    reg := '0';
    elsif falling_edge(CLK) then
    if ENABLE = '1' then
        if nivel_c = 1  then       ----Nivel 1             
            if ticks=TO_UNSIGNED((3E8),32) then
                ticks<= TO_UNSIGNED(0,32);            
                else
                ticks<=ticks+1;
                reg:= '0';
                end if;
        elsif nivel_c = 2  then       ---Nivel2       
            if ticks=TO_UNSIGNED((2E8),32) then
                ticks<= TO_UNSIGNED(0,32);            
                else
                ticks<=ticks+1;
                reg:= '0';
                end if;            
        elsif nivel_c = 3  then        --Nivel3           
            if ticks=TO_UNSIGNED((1E8),32) then
                ticks<= TO_UNSIGNED(0,32);            
                else
                ticks<=ticks+1;
                reg:= '0';
                end if;
        elsif nivel_c = 4  then        --Nivel4           
            if ticks=TO_UNSIGNED((9E7),32) then
                ticks<= TO_UNSIGNED(0,32);            
                else
                ticks<=ticks+1;
                reg:= '0';
                end if;
        elsif nivel_c = 5  then        --Nivel5           
            if ticks=TO_UNSIGNED((7E7),32) then
                ticks<= TO_UNSIGNED(0,32);            
                else
                ticks<=ticks+1;
                reg:= '0';
                end if;       
        elsif nivel_c = 10 then        ----WAIT
            if ticks = TO_UNSIGNED((5E8),32) then
                ticks <= TO_UNSIGNED(0,32);
                else
                ticks<= ticks+1;
                reg:='0' ;
                end if;        
        end if;
 ----------------------------------------------------------
         if nivel_c = 1  then       ----Nivel 1             
            if ticks=TO_UNSIGNED((3E8)-3,32) then
                reg :='1';
            end if;
        elsif nivel_c = 2  then       ---Nivel2       
            if ticks=TO_UNSIGNED((2E8)-3,32) then
                reg :='1';
            end if;           
        elsif nivel_c = 3  then        --Nivel3           
            if ticks=TO_UNSIGNED((1E8)-3,32) then
                reg :='1';
            end if;
        elsif nivel_c = 4  then        --Nivel4           
            if ticks=TO_UNSIGNED((9E7)-3,32) then
                reg :='1';
            end if;
        elsif nivel_c = 5  then        --Nivel5           
            if ticks=TO_UNSIGNED((7E7)-3,32) then
                reg :='1';
            end if;
        elsif nivel_c = 10  then        --WAIT           
            if ticks=TO_UNSIGNED((5E8)-3,32) then
                reg :='1';
            end if;               
        end if;                       
    end if;        
    end if;
    TIMEOUT <= reg;
end process;

nivel_c <= unsigned(NIVEL_IN);
end Behavioral;
