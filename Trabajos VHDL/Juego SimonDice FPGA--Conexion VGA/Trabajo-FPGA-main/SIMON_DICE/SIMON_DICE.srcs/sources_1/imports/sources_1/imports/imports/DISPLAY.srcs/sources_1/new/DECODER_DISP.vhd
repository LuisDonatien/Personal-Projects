LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;
ENTITY decoder IS
PORT (
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
END ENTITY decoder;

ARCHITECTURE dataflow OF decoder IS
BEGIN
    process (CLK)
    begin                                           
        if rising_edge(CLK) then
            if nivel = 0 then
                segment7 <= "0000001";
            elsif nivel = 1 then
                segment7 <= "1111001";
            elsif nivel = 2 then
                segment7 <= "0010010";
            elsif nivel = 3 then
                segment7 <= "0000110";
            elsif nivel = 4 then
                segment7 <= "1001100";
            elsif nivel = 5 then 
                segment7 <= "0100100";
            end if;
            
            if estado=  "0000" then  -------------------INICIO
                        segment0 <= "1001111";
                        segment1 <= "0001001";
                        segment2 <= "1001111";
                        segment3 <= "0110001";
                        segment4 <= "1111001";
                        segment5 <= "0000001";
                        segment6 <= "1111111";
            elsif estado = "0001" then -------------------DIBUJA
                        segment0 <= "1000010";
                        segment1 <= "1111001";
                        segment2 <= "1100000";
                        segment3 <= "1000001";
                        segment4 <= "1000111";
                        segment5 <= "0001000";
                        segment6 <= "1111111";  
            elsif estado = "1111" then --------------------PULSA
                        segment0 <= "0011000";
                        segment1 <= "1000001";
                        segment2 <= "1110001";
                        segment3 <= "0100100";
                        segment4 <= "0001000";
                        segment5 <= "1111111";
                        segment6 <= "1111111";                        
            elsif estado = "0010" then -------------------WAIT
                        segment0 <= "1000001";
                        segment1 <= "0001000";
                        segment2 <= "1111001";
                        segment3 <= "0111001";
                        segment4 <= "1111111";
                        segment5 <= "1111111";
                        segment6 <= "1111111";
            elsif estado = "0100" then -------------------FIN VIC
                        segment0 <= "0111000";
                        segment1 <= "1111001";
                        segment2 <= "0001001";
                        segment3 <= "1111111";
                        segment4 <= "1000001";
                        segment5 <= "1111001";
                        segment6 <= "0110001";  
            elsif estado = "1000" then -------------------FIN DER
                        segment0 <= "0111000";
                        segment1 <= "1111001";
                        segment2 <= "0001001";
                        segment3 <= "1111111";
                        segment4 <= "1000010";
                        segment5 <= "0110000";
                        segment6 <= "1111010";                                                                                    
            end if; 
        end if;
        
    end process;
            END ARCHITECTURE dataflow;

