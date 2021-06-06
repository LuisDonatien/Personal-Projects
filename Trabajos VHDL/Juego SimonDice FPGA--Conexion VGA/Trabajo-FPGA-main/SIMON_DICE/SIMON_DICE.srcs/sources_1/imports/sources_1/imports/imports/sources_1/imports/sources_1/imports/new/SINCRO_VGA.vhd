library IEEE;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

library WORK;
use WORK.VGA_PKG.ALL; 

entity SINCRO_VGA is
  Port ( 
    CLK : in std_logic;
    RESET : in std_logic;
    PXL_NUM : out std_logic_vector(9 downto 0);
    LINE_NUM : out std_logic_vector(9 downto 0);
    VISIBLE : out std_logic;
    HSYNCH  : out std_logic;
    VSYNCH  : out std_logic
  );
end SINCRO_VGA;

architecture Behavioral of SINCRO_VGA is
----------------------------COMPONENTES-----------------------------------------------
     COMPONENT P_countclk 
         port(
             CLK  : in std_logic;
             RESET : in std_logic;
             NEW_PXL : out std_logic
         );
    END COMPONENT ;
    
    COMPONENT P_cont_px             
        Port( 
            CLK : in std_logic;
            RESET : in std_logic;
            NEW_PXL : in std_logic;
            HSYNCH : out std_logic;
            VISIBLE_PXL : out std_logic;
            NEW_LINE : out std_logic;
            CONT_PXL : out std_logic_vector(9 downto 0)
          );
     END COMPONENT;
     
    COMPONENT P_count_line 
        PORT(
            CLK : IN std_logic;
            RESET : IN std_logic;
            NEW_LINE : IN std_logic;
            VISIBLE_LINE : OUT std_logic;
            VSYNCH : OUT std_logic;
            CONT_LINE : OUT std_logic_vector(9 downto 0)
        );
    END COMPONENT;
----------------------------------------------------------------------------------    
----------------------------------------------------------------------------------
-------------------------------SEÑALES--------------------------------------------
    signal NEW_PXL :  std_logic;
    signal VISIBLE_PXL :  std_logic;
    signal VISIBLE_LINE :  std_logic;
    signal NEW_LINE :  std_logic;
    signal CONT_PXL : std_logic_vector(9 downto 0); 
begin

ContadorCLK : P_countclk PORT MAP (
    CLK     => CLK,
    RESET   => RESET,
    NEW_PXL => NEW_PXL
);

Contador_Pxl_Columnas : P_cont_px PORT MAP (
    CLK     => CLK,
    RESET   => RESET,
    NEW_PXL => NEW_PXL,
    HSYNCH  => HSYNCH,
    VISIBLE_PXL => VISIBLE_PXL,
    NEW_LINE => NEW_LINE,
    CONT_PXL => PXL_NUM   
);

 Contador_Pxl_Filas : P_count_line PORT MAP (
    CLK     => CLK,
    RESET   => RESET,
    NEW_LINE => NEW_LINE,
    VISIBLE_LINE => VISIBLE_LINE,
    VSYNCH       => VSYNCH,
    CONT_LINE    => LINE_NUM
 ); 
        VISIBLE <= VISIBLE_LINE AND VISIBLE_PXL;
        
end Behavioral;
