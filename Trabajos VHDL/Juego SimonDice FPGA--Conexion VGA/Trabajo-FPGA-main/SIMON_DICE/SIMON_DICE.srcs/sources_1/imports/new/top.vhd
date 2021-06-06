library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity gestor_secuencia is

	port(
    	B1        : in std_logic; --Botón 1
    	B2        : in std_logic; --Botón 2
    	B3        : in std_logic; --Botón 3
    	B4        : in std_logic; --Botón 4
    	B5        : in std_logic; --Botón 5
    	enable    : in std_logic; --Enable
        clk       : in std_logic; -- Reloj
        nivel     : in std_logic_vector(3 downto 0); --Nivel en el que nos encontramos
        secuencia : out std_logic_vector(24 downto 0); --Secuencia completa que pasa al comparador
        enable_comp    : out std_logic
    );
    
end entity;

architecture behavioral of gestor_secuencia is

	signal sec     : unsigned(secuencia'range) := "0000000000000000000000000";
    --signal counter : unsigned(1 downto 0) := "00";

begin
	process(clk, enable)
		    variable counter : integer := 0;
    begin
           
    if enable = '0' then
    	sec <= (others => '0');
        counter := 0;
        enable_comp <= '0';
        
    elsif rising_edge(clk) then
    
		if B1 = '1' or B2 = '1' or B3 = '1' or B4 = '1' or B5 = '1' then
        counter := counter + 1;
        end if;
        
        if nivel = "0001" then
        if counter = 1 then
            
    		if B1 = '1' then
        		sec(0) <= '1';
                enable_comp <= '1';
        	elsif B2 = '1' then
        		sec(1) <= '1';
                enable_comp <= '1';
        	elsif B3 = '1' then
        		sec(2) <= '1';
                enable_comp <= '1';
        	elsif B4 = '1' then
        		sec(3) <= '1';
                enable_comp <= '1';
        	elsif B5 = '1' then
        		sec(4) <= '1';
                enable_comp <= '1';
            end if;
        end if;
        end if;

        
        if nivel = "0010" then
        if counter = 1 then
            
    		if B1 = '1' then
        		sec(0) <= '1';
        	elsif B2 = '1' then
        		sec(1) <= '1';
        	elsif B3 = '1' then
        		sec(2) <= '1';
        	elsif B4 = '1' then
        		sec(3) <= '1';
        	elsif B5 = '1' then
        		sec(4) <= '1';
            end if;
        end if;
        
        if counter = 2 then  
    		if B1 = '1' then
        		sec(5) <= '1';
                enable_comp <= '1';
       	 	elsif B2 = '1' then
       	 		sec(6) <= '1';
                enable_comp <= '1';
        	elsif B3 = '1' then
        		sec(7) <= '1';
                enable_comp <= '1';
        	elsif B4 = '1' then
        		sec(8) <= '1';
                enable_comp <= '1';
        	elsif B5 = '1' then
        		sec(9) <= '1';
                enable_comp <= '1';
        	end if;
        end if;
     end if;
     
     if nivel = "0011" then
        if counter = 1 then
            
    		if B1 = '1' then
        		sec(0) <= '1';
        	elsif B2 = '1' then
        		sec(1) <= '1';
        	elsif B3 = '1' then
        		sec(2) <= '1';
        	elsif B4 = '1' then
        		sec(3) <= '1';
        	elsif B5 = '1' then
        		sec(4) <= '1';
            end if;
        end if;
        
        if counter = 2 then  
    		if B1 = '1' then
        		sec(5) <= '1';
       	 	elsif B2 = '1' then
       	 		sec(6) <= '1';
        	elsif B3 = '1' then
        		sec(7) <= '1';
        	elsif B4 = '1' then
        		sec(8) <= '1';
        	elsif B5 = '1' then
        		sec(9) <= '1';
        	end if;
        end if;
        
        if counter = 3 then  
    		if B1 = '1' then
        		sec(10) <= '1';
                enable_comp <= '1';
       	 	elsif B2 = '1' then
       	 		sec(11) <= '1';
                enable_comp <= '1';
        	elsif B3 = '1' then
        		sec(12) <= '1';
                enable_comp <= '1';
        	elsif B4 = '1' then
        		sec(13) <= '1';
                enable_comp <= '1';
        	elsif B5 = '1' then
        		sec(14) <= '1';
                enable_comp <= '1';
        	end if;
        end if;
     end if;

     if nivel = "0100" then
        if counter = 1 then
            
    		if B1 = '1' then
        		sec(0) <= '1';
        	elsif B2 = '1' then
        		sec(1) <= '1';
        	elsif B3 = '1' then
        		sec(2) <= '1';
        	elsif B4 = '1' then
        		sec(3) <= '1';
        	elsif B5 = '1' then
        		sec(4) <= '1';
            end if;
        end if;
        
        if counter = 2 then  
    		if B1 = '1' then
        		sec(5) <= '1';
       	 	elsif B2 = '1' then
       	 		sec(6) <= '1';
        	elsif B3 = '1' then
        		sec(7) <= '1';
        	elsif B4 = '1' then
        		sec(8) <= '1';
        	elsif B5 = '1' then
        		sec(9) <= '1';
        	end if;
        end if;
        
        if counter = 3 then  
    		if B1 = '1' then
        		sec(10) <= '1';
       	 	elsif B2 = '1' then
       	 		sec(11) <= '1';
        	elsif B3 = '1' then
        		sec(12) <= '1';
        	elsif B4 = '1' then
        		sec(13) <= '1';
        	elsif B5 = '1' then
        		sec(14) <= '1';
        	end if;
        end if;
        
        if counter = 4 then  
    		if B1 = '1' then
        		sec(15) <= '1';
                enable_comp <= '1';
       	 	elsif B2 = '1' then
       	 		sec(16) <= '1';
                enable_comp <= '1';
        	elsif B3 = '1' then
        		sec(17) <= '1';
                enable_comp <= '1';
        	elsif B4 = '1' then
        		sec(18) <= '1';
                enable_comp <= '1';
        	elsif B5 = '1' then
        		sec(19) <= '1';
                enable_comp <= '1';
        	end if;
        end if;
     end if;

     if nivel = "0101" then
        if counter = 1 then
            
    		if B1 = '1' then
        		sec(0) <= '1';
        	elsif B2 = '1' then
        		sec(1) <= '1';
        	elsif B3 = '1' then
        		sec(2) <= '1';
        	elsif B4 = '1' then
        		sec(3) <= '1';
        	elsif B5 = '1' then
        		sec(4) <= '1';
            end if;
        end if;
        
        if counter = 2 then  
    		if B1 = '1' then
        		sec(5) <= '1';
       	 	elsif B2 = '1' then
       	 		sec(6) <= '1';
        	elsif B3 = '1' then
        		sec(7) <= '1';
        	elsif B4 = '1' then
        		sec(8) <= '1';
        	elsif B5 = '1' then
        		sec(9) <= '1';
        	end if;
        end if;
        
        if counter = 3 then  
    		if B1 = '1' then
        		sec(10) <= '1';
       	 	elsif B2 = '1' then
       	 		sec(11) <= '1';
        	elsif B3 = '1' then
        		sec(12) <= '1';
        	elsif B4 = '1' then
        		sec(13) <= '1';
        	elsif B5 = '1' then
        		sec(14) <= '1';
        	end if;
        end if;
        
        if counter = 4 then  
    		if B1 = '1' then
        		sec(15) <= '1';
       	 	elsif B2 = '1' then
       	 		sec(16) <= '1';
        	elsif B3 = '1' then
        		sec(17) <= '1';
        	elsif B4 = '1' then
        		sec(18) <= '1';
        	elsif B5 = '1' then
        		sec(19) <= '1';
        	end if;
        end if;
        
        if counter = 5 then  
    		if B1 = '1' then
        		sec(20) <= '1';
                enable_comp <= '1';
       	 	elsif B2 = '1' then
       	 		sec(21) <= '1';
                enable_comp <= '1';
        	elsif B3 = '1' then
        		sec(22) <= '1';
                enable_comp <= '1';
        	elsif B4 = '1' then
        		sec(23) <= '1';
                enable_comp <= '1';
        	elsif B5 = '1' then
        		sec(24) <= '1';
                enable_comp <= '1';
        	end if;
        end if;
     end if;

     end if;
    end process;
    
    secuencia <= std_logic_vector(sec);
    
end architecture;