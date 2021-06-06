library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity FSM_tb is
end FSM_tb;

architecture Behavioral of FSM_tb is
    signal RESET	 :  std_logic;
    signal BUTTON	 :  std_logic;
    signal CLK	 	 :  std_logic;
    signal RED         :  std_logic_vector(3 downto 0); 
    signal BLUE        :  std_logic_vector(3 downto 0); 
    signal GREEN       :  std_logic_vector(3 downto 0);
    signal HSYNCH      :  STD_LOGIC;
    signal VSYNCH      :  STD_LOGIC;
    
COMPONENT TOP_FSM_VGA 
    PORT(
    RESET	 : in std_logic;
    BUTTON	 : in std_logic;
    CLK	 	 : in std_logic;
    RED         : OUT std_logic_vector(3 downto 0); 
    BLUE        : OUT std_logic_vector(3 downto 0); 
    GREEN       : OUT std_logic_vector(3 downto 0);
    HSYNCH      : OUT STD_LOGIC;
    VSYNCH      : OUT STD_LOGIC
    );
END COMPONENT;
    constant CLK_PERIOD : time := 1 sec / 100_000_000; --Clock period 100MHz  
begin

uut : TOP_FSM_VGA PORT MAP(
    RESET => RESET,
    BUTTON => BUTTON,
    CLK => CLK,
    RED => RED, 
    BLUE => BLUE,
   GREEN => GREEN,
    HSYNCH => HSYNCH,
    VSYNCH => VSYNCH
);
 clock : process
    begin 
        CLK <= '0';
        wait for 0.5*CLK_PERIOD;
        CLK <= '1' ;
        wait for 0.5*CLK_PERIOD;
end process;

BUTTO : process     
begin
    BUTTON <= '0';
    wait for 1ms;
    BUTTON <= '1'; 
    wait for 1ms;
end process;    
      RESET <= '1', '0' after 10ms , '1' after 26 ms , '0' after 27 ms;
      
temp : process
    begin

    wait for 1sec ;
    assert false
 		report "[SUCCESS]: simulation finished."
	 	severity failure;
    end process;
end Behavioral;