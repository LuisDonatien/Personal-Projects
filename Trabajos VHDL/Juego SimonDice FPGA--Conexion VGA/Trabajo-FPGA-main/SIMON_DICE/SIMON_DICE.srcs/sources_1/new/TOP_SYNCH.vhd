library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity TOP_SYNCH is
  Port (
  CLK       : in std_logic;
  SQUARE_IN : in std_logic_vector(0 to 4);
  SQUARE_OUT : out std_logic_vector(0 to 4)
   );
end TOP_SYNCH;

architecture Behavioral of TOP_SYNCH is
COMPONENT SYNCHRNZR 
PORT(
 CLK : in std_logic;
 ASYNC_IN : in std_logic;
 SYNC_OUT : out std_logic
);
END COMPONENT;
begin

sync_0 : SYNCHRNZR PORT MAP(
 CLK => CLK,
 ASYNC_IN => SQUARE_IN(1),
 SYNC_OUT => SQUARE_OUT(0)
);

sync_1 : SYNCHRNZR PORT MAP(
 CLK => CLK,
 ASYNC_IN => SQUARE_IN(3),
 SYNC_OUT => SQUARE_OUT(1)
);

sync_2 : SYNCHRNZR PORT MAP(
 CLK => CLK,
 ASYNC_IN => SQUARE_IN(4),
 SYNC_OUT => SQUARE_OUT(2)
);

sync_3 : SYNCHRNZR PORT MAP(
 CLK => CLK,
 ASYNC_IN => SQUARE_IN(2),
 SYNC_OUT => SQUARE_OUT(3)
);

sync_4 : SYNCHRNZR PORT MAP(
 CLK => CLK,
 ASYNC_IN => SQUARE_IN(0),
 SYNC_OUT => SQUARE_OUT(4)
);

end Behavioral;
