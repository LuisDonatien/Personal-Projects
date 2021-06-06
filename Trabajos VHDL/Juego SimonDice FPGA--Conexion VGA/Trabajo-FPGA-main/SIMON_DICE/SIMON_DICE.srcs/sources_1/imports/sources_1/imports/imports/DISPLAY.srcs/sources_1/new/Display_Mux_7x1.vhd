library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
entity Display_Mux_7x1 is
  Port (
    segment0 : in std_logic_vector(6 downto 0);
    segment1 : in std_logic_vector(6 downto 0);
    segment2 : in std_logic_vector(6 downto 0);
    segment3 : in std_logic_vector(6 downto 0);
    segment4 : in std_logic_vector(6 downto 0);
    segment5 : in std_logic_vector(6 downto 0);
    segment6 : in std_logic_vector(6 downto 0);
    segment7 : in std_logic_vector(6 downto 0);  
    code     : in std_logic_vector(3 downto 0);
    displayseg : out std_logic_vector(6 downto 0)
   );
end Display_Mux_7x1;

architecture Behavioral of Display_Mux_7x1 is

begin

WITH code SELECT
displayseg <= segment0 WHEN "0000",
        segment1 WHEN "0001",
        segment2 WHEN "0010",
        segment3 WHEN "0011",
        segment4 WHEN "0100",
        segment5 WHEN "0101",
        segment6 WHEN "0110",
        segment7 WHEN "0111",
        "0100101" WHEN others;
    

end Behavioral;
