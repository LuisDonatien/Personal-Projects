library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity TOP_FSM_SINCRONA is
  Port ( 
  	RESET	 : in std_logic;
    BUTTON	 : in std_logic;
    CLK	 	 : in std_logic;
    COMP_IN  : in std_logic_vector(1 downto 0);
    SQUARE	 : out std_logic_vector(0 to 4);
    ENABLE   : out std_logic;
    RED         : out std_logic_vector(3 downto 0); 
    BLUE        : out std_logic_vector(3 downto 0); 
    GREEN       : out std_logic_vector(3 downto 0);
    NIVEL       : out std_logic_vector(3 downto 0);
    ESTADO      : out std_logic_vector(3 downto 0)
  );
end TOP_FSM_SINCRONA;

architecture Behavioral of TOP_FSM_SINCRONA is
COMPONENT FSM 
    PORT(
    RESET	 : in std_logic;
    BUTTON	 : in std_logic;
    TICKUP   : in std_logic;
    NIVEL_OUT : out std_logic_vector(3 downto 0);
    COMP_IN   : in std_logic_vector(1 downto 0);
    ENABLE_CLK : out std_logic;
    ENABLE      : out std_logic;
    CLK	 	 : in std_logic;
    SQUARE	 : out std_logic_vector(0 to 4);
    RED        : out  std_logic_vector(3 downto 0); 
    BLUE       : out std_logic_vector(3 downto 0); 
    GREEN      : out std_logic_vector(3 downto 0);
    NIVEL_OUT_FSM : out std_logic_vector(3 downto 0);
    ESTADO_OUT : out std_logic_vector(3 downto 0)
    );
END COMPONENT;

COMPONENT TOP_DEBOUNCER
    PORT(
  CLK : in std_logic;
  ASYNC_IN : in std_logic;
  EDGE_OUT : out std_logic
    );
END COMPONENT;

COMPONENT FSM_CLK 
    PORT(
    CLK : in std_logic;
    ENABLE : in std_logic;
    TIMEOUT : out std_logic;
    NIVEL_IN : in std_logic_vector(3 downto 0)
    );    
END COMPONENT;

COMPONENT EDGEDTCTR
    PORT(
 CLK : in std_logic;
 SYNC_IN : in std_logic;
 EDGE : out std_logic
    );
END COMPONENT;

COMPONENT SYNCHRNZR
    PORT(
 CLK : in std_logic;
 ASYNC_IN : in std_logic;
 SYNC_OUT : out std_logic
    );
END COMPONENT;
signal button_c : std_logic;
signal button_e : std_logic;
signal button_CCC : std_logic_vector(0 to 1);
signal enable_clk_fsm : std_logic;
signal timeout_clk : std_logic;
signal nivel_c : std_logic_vector(3 downto 0);
begin
FSM_t  : FSM PORT MAP(
    RESET	 =>RESET,
    BUTTON	 =>button_e,
    TICKUP  => timeout_clk,
    ENABLE_CLK => enable_clk_fsm,
    ENABLE => ENABLE,
    COMP_IN => COMP_IN,
    CLK	 	 =>CLK,
    SQUARE	 =>SQUARE,
    NIVEL_OUT => nivel_c,
    RED  => RED,       
    BLUE => BLUE,        
    GREEN => GREEN,
    NIVEL_OUT_FSM => NIVEL,
    ESTADO_OUT => ESTADO      
);

--EDGE_t : EDGEDTCTR PORT MAP(
--CLK => CLK,
-- SYNC_IN =>button_c,
-- EDGE => button_e   
--);

--SYNCH_t : SYNCHRNZR PORT MAP ( 
 --CLK      => CLK,
 --ASYNC_IN => BUTTON,
 --SYNC_OUT => button_c    
--);

deb : TOP_DEBOUNCER PORT MAP (
  CLK => CLK,
  ASYNC_IN =>BUTTON,
  EDGE_OUT => button_e
);

clk_fsmt : FSM_CLK PORT MAP(
    CLK => CLK,
    ENABLE => enable_clk_fsm,
    TIMEOUT => timeout_clk,
    NIVEL_IN => nivel_c
);
end Behavioral;
