library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Mux_2x1 is
  Port (
  SQUARE_FSM : in std_logic_vector(0 to 4);
  SQUARE_BUTTON : in std_logic_vector(0 to 4);
  ENABLE_FSM    : in std_logic;
  SQUARE_OUT    : out std_logic_vector(0 to 4)
   );
end Mux_2x1;

architecture Behavioral of Mux_2x1 is

begin

with ENABLE_FSM select
    SQUARE_OUT <=   SQUARE_FSM when '0',
                    SQUARE_BUTTON when '1',
                    SQUARE_FSM when others;      

end Behavioral;
