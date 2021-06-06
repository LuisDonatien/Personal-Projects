library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity BLOQUE_COMPARADOR is
  --generic( WIDTH: integer := 10  );
  port (
	   Secuencia      : in std_logic_vector(24 downto 0);
       CLK            : in std_logic;	 
       Nivel          : in std_logic_vector(3 downto 0);
       Enable         : in std_logic;
       Salida         : out std_logic_vector(1 downto 0)     
       );
end entity;

architecture A1 of BLOQUE_COMPARADOR is
begin
 COMPARADOR_SECUENCIA:process (Enable,CLK)
 begin
  if Enable ='0' then
        salida<="00";
  elsif CLK'event and CLK='1' then
   case NIVEL is
    when "0001"=>   -- NIVEL 1
        if SECUENCIA = "0000000000000000000000010" then  -- Toca meter "00000-00000-00000-00000-01000"
            salida <= "10" ;
        else 
            salida <= "01" ;
        end if;
        
    when "0010"=>  -- NIVEL 2
        if SECUENCIA = "0000000000000001000001000" then   -- Toca meter "00000-00000-00000-10000-01000"
            salida <= "10" ;
        else 
            salida <= "01" ;
        end if;
        
    when "0011"=>  -- NIVEL 3
        if SECUENCIA = "0000000000000010010010000" then
            salida <= "10" ;
        else 
            salida <= "01" ;
        end if;
    when "0100"=> -- NIVEL 4
        if SECUENCIA = "0000000010010001000000100" then
            salida <= "10" ;
        else 
            salida <= "01" ;
        end if;
    when "0101"=> -- NIVEL 5
        if SECUENCIA = "0001001000100000010000001" then
            salida <= "10" ;
        else 
            salida <= "01" ;
        end if;
     when others =>
     	salida <= "00" ;
        
   end case;
  end if;
  end  process;       
end architecture;