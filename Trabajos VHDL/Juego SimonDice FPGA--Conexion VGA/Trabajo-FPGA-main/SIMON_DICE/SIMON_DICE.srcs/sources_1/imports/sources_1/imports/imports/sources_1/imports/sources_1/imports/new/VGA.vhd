library IEEE;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

library WORK;
use WORK.VGA_PKG.ALL; 

entity VGA is
  Port ( 
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
    --VISIBLE     : OUT std_LOGIC;
   -- PXL_NUM     : OUT std_logic_vector(9 downto 0);
   -- LINE_NUM    : OUT std_logic_vector(9 downto 0)
  );
end VGA;

architecture Behavioral of VGA is
--------------------------------COMPONENTES----------------------------------
COMPONENT SINCRO_VGA 
    PORT(
    CLK : in std_logic;
    RESET : in std_logic;
    PXL_NUM : out std_logic_vector(9 downto 0);
    LINE_NUM : out std_logic_vector(9 downto 0);
    VISIBLE : out std_logic;
    HSYNCH  : out std_logic;
    VSYNCH  : out std_logic
    );
END COMPONENT;
    
COMPONENT DIBUJASIMON_VGA 
    PORT(
    PXL_NUM     : IN std_logic_vector(9 downto 0);
    LINE_NUM    : IN std_logic_vector(9 downto 0);
    VISIBLE     : IN std_logic;
    SQUARE      : IN std_logic_vector(0 to 4);
    RESET       : IN std_logic;
    RED         : OUT std_logic_vector(3 downto 0); 
    BLUE        : OUT std_logic_vector(3 downto 0); 
    GREEN       : OUT std_logic_vector(3 downto 0);
    
    RED_IN         : in std_logic_vector(3 downto 0); 
    BLUE_IN        : in std_logic_vector(3 downto 0); 
    GREEN_IN       : in std_logic_vector(3 downto 0)
    );
END COMPONENT;
------------------------------------------------------------------------------
------------------------------------------------------------------------------
-------------------------SEÑALES----------------------------------------------
    signal visible_c : std_logic;
    signal pxl_num_c : std_logic_vector(9 downto 0);
    signal line_num_c : std_logic_vector(9 downto 0);
------------------------------------------------------------------------------
begin

SINCRO : SINCRO_VGA PORT MAP (
    CLK => CLK,
    RESET => RESET,
    PXL_NUM => pxl_num_c,
    LINE_NUM => line_num_c,
    VISIBLE => visible_c,
    HSYNCH => HSYNCH,
    VSYNCH => VSYNCH
);

DIBUJA : DIBUJASIMON_VGA PORT MAP (
    PXL_NUM => pxl_num_c,
    LINE_NUM => line_num_c,
    VISIBLE => visible_c,
    SQUARE => SQUARE,
    RESET => RESET,
    RED => RED,
    BLUE => BLUE,
    GREEN => GREEN,
    
    RED_IN => RED_IN,
    GREEN_IN => GREEN_IN,
    BLUE_IN => BLUE_IN
    
);
--PXL_NUM <= pxl_num_c;
--LINE_NUM <= line_num_c;
--VISIBLE <= visible_c;
end Behavioral;
