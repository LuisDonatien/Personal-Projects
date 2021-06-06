library IEEE;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

library WORK;
use WORK.VGA_PKG.ALL; 

entity DIBUJASIMON_VGA is
 Port ( 
    PXL_NUM     : IN std_logic_vector(9 downto 0);
    LINE_NUM    : IN std_logic_vector(9 downto 0);
    VISIBLE     : IN std_logic;
    RESET       : IN std_logic;
    SQUARE      : IN std_logic_vector(0 to 4);
    RED         : OUT std_logic_vector(3 downto 0); 
    BLUE        : OUT std_logic_vector(3 downto 0); 
    GREEN       : OUT std_logic_vector(3 downto 0);
    
    RED_IN         : in std_logic_vector(3 downto 0); 
    BLUE_IN        : in std_logic_vector(3 downto 0); 
    GREEN_IN       : in std_logic_vector(3 downto 0)
 );
end DIBUJASIMON_VGA;

architecture Behavioral of DIBUJASIMON_VGA is
    constant c_bar_width : natural := 2;
    constant c_sqare_width : natural := 60;
    signal regsq : std_logic_vector(0 to 4);
begin
 P_pinta: Process (RESET,visible, pxl_num, line_num)
    begin 
        RED <= (others=>'0');
        GREEN <= (others=>'0');
        BLUE <= (others=>'0');
        regsq <= SQUARE;
        if VISIBLE = '0' OR RESET = '1' then       
        elsif VISIBLE = '1' then
         -- linea blanca de 1 pixel en los bordes
            if PXL_NUM = 0 OR PXL_NUM = c_pxl_visible -1 OR
                LINE_NUM=0 OR LINE_NUM= c_line_visible - 1 then
               RED <= (others=>'1');
               GREEN <= (others=>'1');
               BLUE <= (others=>'1');
            end if;
------------------------------------------Cuadricula---------------------------------------------------------
                    
            if   (LINE_NUM>=199-c_bar_width AND LINE_NUM<=199+c_bar_width) OR (LINE_NUM>=279-c_bar_width AND LINE_NUM<=279+c_bar_width) then
                if PXL_NUM>=199 AND PXL_NUM<=439 then
                   RED <= (others=>'1'); 
                   GREEN <= (others=>'1');
                   BLUE <= (others=>'1');
                end if;
            end if;
                 
            if (PXL_NUM>=279-c_bar_width AND PXL_NUM<=279+c_bar_width) OR (PXL_NUM>=359-c_bar_width AND PXL_NUM<=359+c_bar_width) then
                if LINE_NUM>=119 AND LINE_NUM<=359 then
                    RED <= (others=>'1'); 
                    GREEN <= (others=>'1');
                    BLUE <= (others=>'1');
                end if;
            end if;
            
            if (LINE_NUM>=119-c_bar_width AND LINE_NUM<=119+c_bar_width) OR (LINE_NUM>=359-c_bar_width AND LINE_NUM<=359+c_bar_width) then 
                if PXL_NUM>=279 AND PXL_NUM<=359 then
                    RED <= (others=>'1'); 
                    GREEN <= (others=>'1');
                    BLUE <= (others=>'1');
                end if;
            end if;
            
            if (PXL_NUM>=199-c_bar_width AND PXL_NUM<=199+c_bar_width) OR (PXL_NUM>=439-c_bar_width AND PXL_NUM<=439+c_bar_width) then
                if LINE_NUM>=199 AND LINE_NUM<=279 then
                    RED <= (others=>'1'); 
                    GREEN <= (others=>'1');
                    BLUE <= (others=>'1');      
                end if;
            end if;                                                  
--------------------------------------------------------------------------------------------------------------
-------------------------------------------CUADRADOS------------------------------------------------------------------
            if  PXL_NUM>=289 AND PXL_NUM<= 289+c_sqare_width then -------------------------------1
                if LINE_NUM>=129 AND LINE_NUM<=129+c_sqare_width then
                    if regsq(0)= '1' then
                        RED <= RED_IN;   --Amarillo
                        GREEN <= GREEN_IN;
                        BLUE <= BLUE_IN;  
                    end if;
                end if;
            end if;
            
            if  PXL_NUM>=369 AND PXL_NUM<= 369+c_sqare_width then -------------------------------2
                if LINE_NUM>=209 AND LINE_NUM<=209+c_sqare_width then
                    if regsq(1)= '1' then
                        RED <= RED_IN;   --Amarillo
                        GREEN <= GREEN_IN;
                        BLUE <= BLUE_IN;  
                    end if;
                end if;
            end if;
               
            if  PXL_NUM>=289 AND PXL_NUM<= 289+c_sqare_width then -------------------------------3
                if LINE_NUM>=289 AND LINE_NUM<=289+c_sqare_width then
                    if regsq(2)= '1' then
                        RED <= RED_IN;   --Amarillo
                        GREEN <= GREEN_IN;
                        BLUE <= BLUE_IN;  
                    end if;
                end if;
            end if;

            if  PXL_NUM>=209 AND PXL_NUM<= 209+c_sqare_width then -------------------------------4
                if LINE_NUM>=209 AND LINE_NUM<=209+c_sqare_width then
                    if regsq(3)= '1' then
                        RED <= RED_IN;   --Amarillo
                        GREEN <= GREEN_IN;
                        BLUE <= BLUE_IN;  
                    end if;
                end if;
            end if;          

            if  PXL_NUM>=289 AND PXL_NUM<= 289+c_sqare_width then -------------------------------3
                if LINE_NUM>=209 AND LINE_NUM<=209+c_sqare_width then
                    if regsq(4)= '1' then
                        RED <= RED_IN;   --Amarillo
                        GREEN <= GREEN_IN;
                        BLUE <= BLUE_IN;  
                    end if;
                end if;
                        
            end if;
        end if;
 end process;

end Behavioral;