library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity TOP_DISPLAY is
  Port (
    CLK : in std_logic;
    RESET : in std_logic;
    nivel    : in std_logic_vector(3 downto 0);
    estado   : in std_logic_vector(3 downto 0);
    DisplayAN : out std_logic_vector(0 to 7);
    displayseg : out std_logic_vector(6 downto 0)        
   );
end TOP_DISPLAY;

architecture Behavioral of TOP_DISPLAY is
COMPONENT Display_CLK
PORT(
    RESET : in std_logic;
    CLK : in std_logic;
    DisplayAN :out std_logic_vector(0 to 7);
    Displaycode : out std_logic_vector(3 downto 0)
);
END COMPONENT;

COMPONENT Display_Mux_7x1
PORT(
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
END COMPONENT;

COMPONENT decoder
PORT(
    CLK      : in std_logic;
    nivel    : in std_logic_vector(3 downto 0);
    estado   : in std_logic_vector(3 downto 0);
    segment0 : out std_logic_vector(6 downto 0);
    segment1 : out std_logic_vector(6 downto 0);
    segment2 : out std_logic_vector(6 downto 0);
    segment3 : out std_logic_vector(6 downto 0);
    segment4 : out std_logic_vector(6 downto 0);
    segment5 : out std_logic_vector(6 downto 0);
    segment6 : out std_logic_vector(6 downto 0);
    segment7 : out std_logic_vector(6 downto 0)  
);
END COMPONENT;
------------------------Señales-----------------------------------------------------
    signal segment0_c :  std_logic_vector(6 downto 0);
    signal segment1_c :  std_logic_vector(6 downto 0);
    signal segment2_c :  std_logic_vector(6 downto 0);
    signal segment3_c :  std_logic_vector(6 downto 0);
    signal segment4_c :  std_logic_vector(6 downto 0);
    signal segment5_c :  std_logic_vector(6 downto 0);
    signal segment6_c :  std_logic_vector(6 downto 0);
    signal segment7_c :  std_logic_vector(6 downto 0);
    signal code_c     :  std_logic_vector(3 downto 0);
begin

Disp_clk : Display_CLK PORT MAP (
    RESET => RESET,
    CLK => CLK,
    DisplayAN => DisplayAN ,
    Displaycode => code_c
);
Disp_mux : Display_Mux_7x1 PORT MAP (
    segment0 =>segment0_c,
    segment1 =>segment1_c,
    segment2 =>segment2_c,
    segment3 =>segment3_c,
    segment4 =>segment4_c,
    segment5 =>segment5_c,
    segment6 =>segment6_c,
    segment7 =>segment7_c,
    code     => code_c,
    displayseg => displayseg
);

Disp_decod : decoder PORT MAP(
    CLK     => CLK,
    nivel   => nivel,
    estado  => estado,
    segment0 =>segment0_c,
    segment1 =>segment1_c,
    segment2 =>segment2_c,
    segment3 =>segment3_c,
    segment4 =>segment4_c,
    segment5 =>segment5_c,
    segment6 =>segment6_c,
    segment7 =>segment7_c
);


end Behavioral;
