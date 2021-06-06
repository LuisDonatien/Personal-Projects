library IEEE;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;


library WORK;
use WORK.VGA_PKG.ALL; 

entity P_cont_px is
  Port ( 
    CLK : in std_logic;
    RESET : in std_logic;
    NEW_PXL : in std_logic;
    HSYNCH : out std_logic;
    VISIBLE_PXL : out std_logic;
    NEW_LINE : out std_logic;
    CONT_PXL : out std_logic_vector(9 downto 0)
  );
end P_cont_px;

architecture Behavioral of P_cont_px is
    signal npixel : unsigned (9 downto 0);
begin
 cont_pixel : process(CLK,RESET)
 variable reg: integer;
    begin
        if RESET = '1'then
            reg:=0; 
            npixel <= (others => '0');
        elsif falling_edge(CLK) then
            if NEW_PXL = '1' then
                reg := 1;
            end if;
            if  reg = 1 then
                if npixel < c_pxl_total-1 then 
                     npixel <= npixel + 1;
                 reg := 0;
                 else
                    npixel <= (others => '0');
                 reg := 0;
                 end if;
            end if;
        end if;            

 end process;   
    CONT_PXL <= std_logic_vector(npixel);
         VISIBLE_PXL <= '0' when RESET = '1' else
                        '1' when npixel < c_pxl_visible  else
                        '0' when npixel >= c_pxl_visible else
                        '0';
        NEW_LINE <= '0' when RESET = '1' else
                    '1' when npixel = c_pxl_total -1  else
                    '0' when npixel< c_pxl_total -1 else
                    '0';
        HSYNCH <= '1' when  npixel< c_pxl_2_fporch  else
                    '1' when npixel>c_pxl_2_synch -1 else
                    '0';
 
end Behavioral;
