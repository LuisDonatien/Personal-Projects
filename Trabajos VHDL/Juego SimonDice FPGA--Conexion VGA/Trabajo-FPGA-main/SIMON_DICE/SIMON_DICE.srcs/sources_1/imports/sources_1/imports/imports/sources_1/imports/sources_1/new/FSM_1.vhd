-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity FSM is     
	port(
	RESET	        : in std_logic;
    BUTTON	        : in std_logic;
    TICKUP          : in std_logic;
    COMP_IN         : in std_logic_vector(1 downto 0);
    ENABLE_CLK      : out std_logic;
    ENABLE          : out std_logic;
    NIVEL_OUT_FSM   : out std_logic_vector(3 downto 0);
    ESTADO_OUT      : out std_logic_vector(3 downto 0);
    CLK	            : in std_logic;
    NIVEL_OUT       : out std_logic_vector(3 downto 0);-----
    SQUARE	        : out std_logic_vector(0 to 4);
    RED             : OUT std_logic_vector(3 downto 0); 
    BLUE            : OUT std_logic_vector(3 downto 0); 
    GREEN           : OUT std_logic_vector(3 downto 0)
     );
end entity;

architecture behavioral of FSM is 
	type estate_t is (S0_INICIO,S1_NIVEL,S2_DIBUJA,S3_PULSA,S4_WAIT,S5_FINAL);
    signal  estate , nxt_estate : estate_t;
    signal remaining_ticks, nxt_remaining_ticks : unsigned(31 downto 0);
    signal nxt_nivel,nivel ,nxt_contador, contador : unsigned(3 downto 0);
    signal TICKUP_C,reg  : std_logic;
    signal BUTTON_C : std_logic;
    signal COMP_IN_C : std_logic_vector(1 downto 0);
begin

estate_register : process(CLK,RESET)
    begin    	
    if RESET = '1' then 
    estate <= S0_INICIO;  
    elsif falling_edge(CLK) then
    	estate<= nxt_estate; ------------Actualizacion sincrona valores	
   		nivel<=nxt_nivel;
   		contador<=nxt_contador;
   		----------------------------------------------------------------
   		if TICKUP = '1' then -----------Actualizacion sincrona de valores entrada
   		   TICKUP_C <= '1';
   	    else
   	        TICKUP_C <= '0'; 
   	    end if; 	
   	    
   		if BUTTON = '1' then
   		   BUTTON_C <= '1';
   	    else 
   	        BUTTON_C <= '0';
   		end if;
   		COMP_IN_C <= COMP_IN; 
   		-------------------------------------------------------------------
   	end if;
   end process;
   nxtstate_decod : process(COMP_IN_C,BUTTON_C,TICKUP_C,estate,contador,nivel)--Ctoo combinac todo las entradas deben estar
   begin
   	nxt_estate <= estate; -- Nos asegura seguir en combinacional. Evitando latch
    nxt_nivel <= nivel +1;  -------Suma nivel 
    reg <='0'; 
    nxt_contador <=contador+1; -- Suma contador     
    
   	
        case estate is	
            when S0_INICIO =>
        	   nxt_nivel <= TO_UNSIGNED(0,4);
        	   nxt_contador <=TO_UNSIGNED(0,4);
        	   if BUTTON_C = '1' then 
                    nxt_estate <= S1_NIVEL;
                end if;
            
            when S1_NIVEL =>
                nxt_contador <=TO_UNSIGNED(0,4);    --Contador a 0
				if nxt_nivel <= 5 then  --En el nivel no mantengo la variable señal lo que hace que se sume 1
            		nxt_estate <= S2_DIBUJA;
            	else
            	   nxt_estate <= S5_FINAL;
                end if;
                
            when S2_DIBUJA =>           
           ----------------------------------------------------------------------------------------------   
                            -------------------
            	if nivel = 1  then ---------NIVEL 1
            	nxt_nivel <= TO_UNSIGNED(1,4);
                    if contador >= nivel then   --si contador >= nivel se ha realizado la secuencia
                        nxt_estate <= S3_PULSA;
                        nxt_contador<= TO_UNSIGNED(8,4);    ---Valor dispar a contador para que no coincida con ningun nivel
                    end if;    
                                                            
                elsif nivel = 2  then ---------NIVEL 2
            	nxt_nivel <= TO_UNSIGNED(2,4);
                    if contador = nivel then
                        nxt_estate <= S3_PULSA;
                        nxt_contador<= TO_UNSIGNED(8,4);
                    end if;       
                                     
                elsif nivel = 3  then ---------NIVEL 3
            	nxt_nivel <= TO_UNSIGNED(3,4);
                    if contador >= nivel then
                        nxt_estate <= S3_PULSA;
                        nxt_contador<= TO_UNSIGNED(8,4);
                    end if;       
                                                     
                elsif nivel = 4  then ---------NIVEL 4
            	nxt_nivel <= TO_UNSIGNED(4,4);
                    if contador >= nivel then
                        nxt_estate <= S3_PULSA;
                        nxt_contador<= TO_UNSIGNED(8,4);
                    end if;  
                                                                
                elsif nivel = 5  then ---------NIVEL 5
            	nxt_nivel <= TO_UNSIGNED(5,4);
                    if contador >= nivel then
                        nxt_estate <= S3_PULSA;
                        nxt_contador<= TO_UNSIGNED(8,4);
                    end if;                   
                end if;
                                                           
            if TICKUP_C = '1'  then 
            ----Aqui no actualizo contador y cuando CLK_FSM avisa de tiempo pasado sumo 1 a contador             
                else
                    if contador = 0 then --Reactualizacion valor contador para evitar suma indeseada
                        nxt_contador <= TO_UNSIGNED(0,4);
                    elsif contador = 1 then 
                        nxt_contador <= TO_UNSIGNED(1,4);
                    elsif contador = 2 then 
                        nxt_contador <= TO_UNSIGNED(2,4);
                    elsif contador = 3 then
                        nxt_contador <= TO_UNSIGNED(3,4);
                    elsif contador = 4 then
                        nxt_contador <= TO_UNSIGNED(4,4);
                    elsif contador = 5 then
                        nxt_contador <= TO_UNSIGNED(5,4);
                    end if;
            end if;
            ------------------------------------------------------------------------------------------
            when S3_PULSA =>
            -------En pulsa se evita la suma ya que sirve para manejar informacion en el process de salida
                    if contador = 0 then --Reactualizacion valor contador para la sentencia inicial de evitar latch
                        nxt_contador <= TO_UNSIGNED(0,4);
                    elsif contador = 1 then 
                        nxt_contador <= TO_UNSIGNED(1,4);
                    elsif contador = 2 then 
                        nxt_contador <= TO_UNSIGNED(2,4);
                    elsif contador = 3 then
                        nxt_contador <= TO_UNSIGNED(3,4);
                    elsif contador = 4 then
                        nxt_contador <= TO_UNSIGNED(4,4);
                    elsif contador = 5 then
                        nxt_contador <= TO_UNSIGNED(5,4);
                    elsif contador = 10 then 
                        nxt_contador <= TO_UNSIGNED(10,4);
                    elsif contador = 11 then 
                        nxt_contador <= TO_UNSIGNED(11,4);
                    end if;
           
                                
            --Al igual que contador no se desea que varie la variable nivel 
            if nivel = 1 then
            nxt_nivel <= TO_UNSIGNED(1,4);
            elsif nivel = 2 then
            nxt_nivel <= TO_UNSIGNED(2,4);
            elsif nivel = 3 then
            nxt_nivel <= TO_UNSIGNED(3,4);
            elsif nivel = 4 then
            nxt_nivel <= TO_UNSIGNED(4,4);
            elsif nivel = 5 then
            nxt_nivel <= TO_UNSIGNED(5,4);
            end if;
            
               
            if COMP_IN_C = "10" then   
                 	nxt_contador <= TO_UNSIGNED(10,4);
                if nivel = 5 then
                    nxt_estate <= S5_FINAL;
                else
                    nxt_estate <= S4_WAIT;
                end if;
          elsif COMP_IN_C = "01" then
              nxt_estate <= S5_FINAL;
              nxt_contador <= TO_UNSIGNED(11,4);
            end if;
            
            ------------------------------------------------------------------------------
            when S4_WAIT =>                               
            --No desea que varie la variable nivel 
            if nivel = 1 then
            nxt_nivel <= TO_UNSIGNED(1,4);
            elsif nivel = 2 then
            nxt_nivel <= TO_UNSIGNED(2,4);
            elsif nivel = 3 then
            nxt_nivel <= TO_UNSIGNED(3,4);
            elsif nivel = 4 then
            nxt_nivel <= TO_UNSIGNED(4,4);
            elsif nivel = 5 then
            nxt_nivel <= TO_UNSIGNED(5,4);
            end if;
            
                if TICKUP_C = '1'  then 
                        nxt_estate <= S1_NIVEL;
                end if;
                                
            when S5_FINAL =>
                    if contador = 0 then --Reactualizacion valor contador para la sentencia inicial de evitar latch
                        nxt_contador <= TO_UNSIGNED(0,4);
                    elsif contador = 1 then 
                        nxt_contador <= TO_UNSIGNED(1,4);
                    elsif contador = 2 then 
                        nxt_contador <= TO_UNSIGNED(2,4);
                    elsif contador = 3 then
                        nxt_contador <= TO_UNSIGNED(3,4);
                    elsif contador = 4 then
                        nxt_contador <= TO_UNSIGNED(4,4);
                    elsif contador = 5 then
                        nxt_contador <= TO_UNSIGNED(5,4);
                    elsif contador = 10 then 
                        nxt_contador <= TO_UNSIGNED(10,4);
                    elsif contador = 11 then 
                        nxt_contador <= TO_UNSIGNED(11,4);
                    end if;
                    
            if nivel = 1 then
            nxt_nivel <= TO_UNSIGNED(1,4);
            elsif nivel = 2 then
            nxt_nivel <= TO_UNSIGNED(2,4);
            elsif nivel = 3 then
            nxt_nivel <= TO_UNSIGNED(3,4);
            elsif nivel = 4 then
            nxt_nivel <= TO_UNSIGNED(4,4);
            elsif nivel = 5 then
            nxt_nivel <= TO_UNSIGNED(5,4);
            end if;
                    
                if BUTTON_C = '1' then
                    nxt_estate <= S0_INICIO;
                end if;
            when others => --Esta caso es critico ha ocurrido algo raro
                nxt_estate <= S5_FINAL;   		
      	end case;
   end process;
   
   output_decod   : process(estate,contador,nivel) --Maquina de Moore salida depende de estado
   begin
   SQUARE<= (others => '0');-------------------------Salidas por defecto para evitar latch
   NIVEL_OUT <= (others => '0');-------Nivel para FSM_CLK
   ENABLE_CLK <= '0'; --Habilitacion reloj
   RED <= (others=>'0');
   GREEN <= (others=>'0');
   BLUE <= (others=>'0');
   NIVEL_OUT_FSM <= std_logic_vector(nivel); ---Nivel fuera de top FSM (Usado por display)
   ESTADO_OUT <= "0000";
   ENABLE <= '0';                   ----Inhabilitar Recoger secuencia botones
   ------------------------------------------------------
   		case estate is
        	when S0_INICIO =>
        	ESTADO_OUT <= "0000"; 
					SQUARE <= (others => '1');
				RED <= (others=>'0');   --Azul Claro
                GREEN <= (others=>'1');
                BLUE <= (others=>'1'); 
            when S1_NIVEL =>
					SQUARE(3) <= '1';
            when S2_DIBUJA =>
                ESTADO_OUT <= "0001";
                ENABLE_CLK <= '1';
                ----------------------------------------
                RED <= (others=>'1');   --Amarillo
                GREEN <= (others=>'1');
                BLUE <= (others=>'0'); 
                ----------------------------------------
                NIVEL_OUT <= std_logic_vector(nivel); ---- Selecciono en FSM_CLK para el tiempo segun el nivel.
                    if nivel = TO_UNSIGNED(0,4) then
                            SQUARE(2) <= '1' ;
                            SQUARE(4) <= '1' ;   
                    end if;                        
					if nivel = TO_UNSIGNED(1,4) then
                    	if contador = 0 then
                            SQUARE(0) <= '1' ;
                        end if;
                         
                    elsif nivel = TO_UNSIGNED(2,4) then
                        if contador = 0 then 
                            SQUARE(1) <= '1' ;
                        elsif contador = 1 then  
                            SQUARE(2) <= '1' ; 
                        end if;    
                        
                    elsif nivel =TO_UNSIGNED(3,4) then
                        if contador = 0 then 
                            SQUARE(2) <= '1' ;
                        elsif contador = 1 then
                            SQUARE(3) <= '1' ;
                        elsif contador = 2 then
                            SQUARE(4) <= '1' ; 
                        end if;    
 
                     elsif nivel =TO_UNSIGNED(4,4) then
                        if contador = 0 then 
                            SQUARE(3) <= '1' ;
                        elsif contador = 1 then
                            SQUARE(2) <= '1' ;
                        elsif contador = 2 then
                            SQUARE(1) <= '1' ;
                        elsif contador = 3 then
                            SQUARE(0) <= '1' ;                              
                        end if; 
 
                     elsif nivel =TO_UNSIGNED(5,4) then
                        if contador = 0 then 
                            SQUARE(4) <= '1' ;
                        elsif contador = 1 then
                            SQUARE(3) <= '1' ;
                        elsif contador = 2 then
                            SQUARE(2) <= '1' ;
                        elsif contador = 3 then
                            SQUARE(1) <= '1' ;  
                        elsif contador = 4 then
                            SQUARE(0) <= '1';
                        end if;                                      	   	
                    end if;
            
            when S3_PULSA =>
            ESTADO_OUT<= "1111";
                RED <= (others=>'1');   --Blanco
                GREEN <= (others=>'1');
                BLUE <= (others=>'1'); 
            ENABLE <= '1';  --Habilita pulsacion botones
            
            when S4_WAIT =>
            ESTADO_OUT <= "0010";
                RED <= (others=>'1');   --Morado
                GREEN <= (others=>'0');
                BLUE <= (others=>'1');
                            SQUARE(3) <= '1';
                            SQUARE(2) <= '1';
                            SQUARE(1) <= '1';
                            SQUARE(0) <= '1';
                            SQUARE(4) <= '0';
                            ENABLE_CLK <= '1'; --Habilito reloj
                            NIVEL_OUT <= std_logic_vector(TO_UNSIGNED(10,4));  --Seleccion tiempos reloj                 
           
            when S5_FINAL =>
            if contador = 10 then
            ESTADO_OUT <= "0100";
                RED <= (others=>'0');   --Verde Claro
                GREEN <= (others=>'1');
                BLUE <= (others=>'0');
            elsif contador = 11 then                 
            ESTADO_OUT <= "1000";
                RED <= (others=>'1');   --Rojo Claro
                GREEN <= (others=>'0');
                BLUE <= (others=>'0');
            end if;
                    SQUARE(0)<= '1';
                    SQUARE(1)<= '1'; 
                    SQUARE(2)<= '1';
                    SQUARE(3)<= '1';           	
            when others => --Este caso es critico ha ocurrido algo raro
                    SQUARE(4) <= '1';
                    SQUARE(3) <= '1';
                    SQUARE(2) <= '1';
      	end case;
   end process;
end architecture;
