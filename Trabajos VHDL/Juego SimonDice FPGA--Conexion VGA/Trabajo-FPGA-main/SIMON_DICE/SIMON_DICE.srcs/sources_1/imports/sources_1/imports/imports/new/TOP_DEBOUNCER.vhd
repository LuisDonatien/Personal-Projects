----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 22.01.2021 22:41:18
-- Design Name: 
-- Module Name: TOP_DEBOUNCER - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity TOP_DEBOUNCER is
  Port (
  CLK : in std_logic;
  ASYNC_IN : in std_logic;
  EDGE_OUT : out std_logic
   );
end TOP_DEBOUNCER;

architecture Behavioral of TOP_DEBOUNCER is
COMPONENT Debouncer
PORT(
  CLK       : in std_logic;
  DEBOUNCER_IN : in std_logic;
  DEBOUNCER_OUT : out std_logic
);
END COMPONENT;

COMPONENT SYNCHRNZR
PORT(
 CLK : in std_logic;
 ASYNC_IN : in std_logic;
 SYNC_OUT : out std_logic
);
END COMPONENT;

COMPONENT EDGEDTCTR
PORT(
 CLK : in std_logic;
 SYNC_IN : in std_logic;
 EDGE : out std_logic
);
END COMPONENT;

signal debouncer_out_c : std_logic;
signal debouncer_in_c : std_logic;
begin

synch_c :  SYNCHRNZR PORT MAP (
 CLK => CLK,
 ASYNC_IN => ASYNC_IN,
 SYNC_OUT => debouncer_in_c
);
debouncer_c : Debouncer PORT MAP(
  CLK     => CLK,
  DEBOUNCER_IN => debouncer_in_c,
  DEBOUNCER_OUT => debouncer_out_c
);

edge_c :  EDGEDTCTR PORT MAP (
 CLK => CLK,
 SYNC_IN => debouncer_out_c,
 EDGE => EDGE_OUT
);

end Behavioral;
