library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_arith.all;
entity I2C_ReceiveSCL is
  Port ( 
        CLK: in std_logic;
        SCL_in : in std_logic; -- Async in CLK.
        SCL_out : out std_logic; --Sincronized SCL
        START   : out std_logic; --Detect the start event and send it to the FSM
        SdCLK : out std_logic
  );
end I2C_ReceiveSCL;

architecture Behavioral of I2C_ReceiveSCL is
COMPONENT SYNCHRNZR
 port (
 CLK : in std_logic;
 ASYNC_IN : in std_logic;
 SYNC_OUT : out std_logic
 );
END COMPONENT;
signal SdCLK_count, SCL_OFF_count : std_logic_vector(31 downto 0):=(others=>'0');
signal SCL_s: std_logic;
begin

uut: SYNCHRNZR          --Synchronize the input SCL Master CLK.
PORT MAP(
 CLK => CLK,
 ASYNC_IN =>SCL_in,
 SYNC_OUT =>SCL_s
);
Sd_clk_out : process(CLK)
variable flag: std_logic;
begin
    if rising_edge(CLK) then    
        if SCL_s='0' then
            SCL_out<='0';
            if unsigned(SdCLK_count)<=249 then
                SdCLK<='0';
                SdCLK_count<= unsigned(SdCLK_count)+1;
            else
                SdCLK<='1';
            end if;
        SCL_OFF_count<=(others=>'0');
        else
            SCL_out<='1';
            SdCLK<='0';
            SdCLK_count<=(others=>'0');
            ---Now we have to detect START event,the SDA is complicate to detect so we are going to see if SCL are inactive more than 1 cycle SCL=1 >10us  
                if unsigned(SCL_OFF_count)>1000 then -- 1000 cycles on a 100MHz clock is 10us a cycle of 100KHz Clock
                    START<='1';
                else
                    START<='0';
                    SCL_OFF_count<=unsigned(SCL_OFF_count)+1;    --SCL='1' we had 1 every CLK cycles.
                end if;    
        end if;                
    end if;

end process;

end Behavioral;
