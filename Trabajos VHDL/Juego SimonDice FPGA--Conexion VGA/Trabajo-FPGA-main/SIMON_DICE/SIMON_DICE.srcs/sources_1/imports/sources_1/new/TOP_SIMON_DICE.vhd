library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity TOP_SIMON_DICE is
  Port (
    RESET	 : in std_logic;
    BUTTON	 : in std_logic_vector(0 to 4);
    CLK	 	 : in std_logic;
    RED         : OUT std_logic_vector(3 downto 0); 
    BLUE        : OUT std_logic_vector(3 downto 0); 
    GREEN       : OUT std_logic_vector(3 downto 0);
    HSYNCH      : OUT STD_LOGIC;
    VSYNCH      : OUT STD_LOGIC;


    DisplayAN : out std_logic_vector(0 to 7);
    displayseg : out std_logic_vector(6 downto 0)
    );
end TOP_SIMON_DICE; 

architecture Behavioral of TOP_SIMON_DICE is
COMPONENT VGA 
    PORT(
    CLK         : IN STD_LOGIC;
    RESET       : IN STD_LOGIC;
    SQUARE      : IN STD_LOGIC_VECTOR(0 to 4);
    RED         : OUT std_logic_vector(3 downto 0); 
    BLUE        : OUT std_logic_vector(3 downto 0); 
    GREEN       : OUT std_logic_vector(3 downto 0);
    RED_IN         : in std_logic_vector(3 downto 0); 
    BLUE_IN        : in std_logic_vector(3 downto 0); 
    GREEN_IN       : in std_logic_vector(3 downto 0);
    HSYNCH      : OUT STD_LOGIC;
    VSYNCH      : OUT STD_LOGIC
    );
END COMPONENT;

COMPONENT TOP_DEBOUNCER 
PORT(
  CLK : in std_logic;
  ASYNC_IN : in std_logic;
  EDGE_OUT : out std_logic
);
END COMPONENT;

COMPONENT TOP_FSM_SINCRONA 
port(
  	RESET	 : in std_logic;
    BUTTON	 : in std_logic;
    CLK	 	 : in std_logic;
    COMP_IN  : in std_logic_vector(1 downto 0);
    SQUARE	 : out std_logic_vector(0 to 4);
    ENABLE   : out std_logic;
    RED         : OUT std_logic_vector(3 downto 0); 
    BLUE        : OUT std_logic_vector(3 downto 0); 
    GREEN       : OUT std_logic_vector(3 downto 0);
    NIVEL       : out std_logic_vector(3 downto 0);
    ESTADO      : out std_logic_vector(3 downto 0)  
);
END COMPONENT;

COMPONENT TOP_DISPLAY
PORT(
    CLK : in std_logic;
    RESET : in std_logic;
    nivel    : in std_logic_vector(3 downto 0);
    estado   : in std_logic_vector(3 downto 0);
    DisplayAN : out std_logic_vector(0 to 7);
    displayseg : out std_logic_vector(6 downto 0)
);
END COMPONENT;

COMPONENT TOP 
PORT(
    	B1        : in std_logic; --Botón 1
    	B2        : in std_logic; --Botón 2
    	B3        : in std_logic; --Botón 3
    	B4        : in std_logic; --Botón 4
    	B5        : in std_logic; --Botón 5
    	enable    : in std_logic; --Enable
        nivel     : in std_logic_vector(3 downto 0); --Nivel en el que nos encontramos
        clk       : in std_logic; --Reloj
        salida    : out std_logic_vector(1 downto 0)
);
END COMPONENT; 

COMPONENT TOP_SYNCH 
PORT(
  CLK       : in std_logic;
  SQUARE_IN : in std_logic_vector(0 to 4);
  SQUARE_OUT : out std_logic_vector(0 to 4)
);
END COMPONENT;

COMPONENT Mux_2x1 
PORT(
  SQUARE_FSM : in std_logic_vector(0 to 4);
  SQUARE_BUTTON : in std_logic_vector(0 to 4);
  ENABLE_FSM    : in std_logic;
  SQUARE_OUT    : out std_logic_vector(0 to 4)
);
END COMPONENT;
    signal square_c : std_logic_vector(0 to 4);
    signal square_Muxout_c : std_logic_vector(0 to 4);
    signal RED_IN_c         :  std_logic_vector(3 downto 0); 
    signal BLUE_IN_c        :  std_logic_vector(3 downto 0); 
    signal GREEN_IN_c       :  std_logic_vector(3 downto 0);
    signal ESTADO_c         :  std_logic_vector(3 downto 0);
    signal NIVEL_c          :  std_logic_vector(3 downto 0); 
    signal COMP_IN_c        :  std_logic_vector(1 downto 0);
    signal ENABLE_c         : std_logic;
    signal RESET_in         : std_logic;
    signal RESET_out        :std_logic;
    signal square_button    : std_logic_vector(0 to 4);
    signal SQUARE_IN_MUX_c    : std_logic_vector(0 to 4);
begin
vgat : VGA PORT MAP (
    CLK       =>CLK,
    RESET     =>RESET_OUT,
    SQUARE    =>square_Muxout_c,
    RED    =>RED,    
    BLUE    => BLUE,   
    GREEN   => GREEN ,
    RED_IN    =>RED_IN_c,    
    BLUE_IN    => BLUE_IN_c,   
    GREEN_IN   => GREEN_IN_c ,
    HSYNCH  => HSYNCH,
    VSYNCH  => VSYNCH
);

fsm_t : TOP_FSM_SINCRONA  PORT MAP (
  	RESET	=>RESET_OUT, 
    BUTTON	 => BUTTON(0),
    CLK	 	 => CLK,
    SQUARE	=> square_c,
    COMP_IN => COMP_IN_c,
    ENABLE  => ENABLE_c,
    RED    => RED_IN_c,
    BLUE   => BLUE_IN_c,
    GREEN  => GREEN_IN_c,
    NIVEL  => NIVEL_c,
    ESTADO => ESTADO_c
);

display_t : TOP_DISPLAY PORT MAP (
    CLK => CLK,
    RESET => RESET_OUT,
    nivel => NIVEL_c,
    estado  => ESTADO_c,
    DisplayAN => DisplayAN,
    displayseg => displayseg
);

comp_t : TOP PORT MAP (
    	B1 => BUTTON(0),
    	B2 => BUTTON(1), 
    	B3 => BUTTON(2),  
    	B4 => BUTTON(3),  
    	B5 => BUTTON(4),    
    	enable => ENABLE_c,
        nivel => NIVEL_C,
        clk => CLK,
        salida => COMP_IN_C  
);

deb_t : TOP_DEBOUNCER PORT MAP(
  CLK => CLK,
  ASYNC_IN => RESET_IN,
  EDGE_OUT => RESET_OUT
);

synch5_t : TOP_SYNCH PORT MAP(
  CLK  => CLK,
  SQUARE_IN => BUTTON,
  SQUARE_OUT => SQUARE_IN_MUX_c
);

mux_but_fsmt : Mux_2x1 PORT MAP(
  SQUARE_FSM => square_c,
  SQUARE_BUTTON => SQUARE_IN_MUX_c,
  ENABLE_FSM  => ENABLE_c,
  SQUARE_OUT => square_Muxout_c
);

RESET_IN <= NOT RESET;
end Behavioral;

