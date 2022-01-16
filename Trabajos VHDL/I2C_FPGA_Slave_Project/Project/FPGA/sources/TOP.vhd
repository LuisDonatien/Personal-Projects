
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity TOP is
  Port ( 
        CLK: in std_logic;
        SCL : in std_logic; -- Async in CLK.
        RESET : in std_logic;
        Led: out std_logic_vector(7 downto 0);
        sw: in std_logic_vector(7 downto 0);
        SDA: inout std_logic
  );
end TOP;

architecture Behavioral of TOP is
COMPONENT I2C_ReceiveSCL
  Port ( 
        CLK: in std_logic;
        SCL_in : in std_logic; -- Async in CLK.
        SCL_out : out std_logic; --Sincronized SCL
        START   : out std_logic; --Detect the start event and send it to the FSM
        SdCLK : out std_logic
  );
END COMPONENT;
COMPONENT I2CFsm_Slave
  Port (
  SCL : in std_LOGIC;
  CLK_DATA : in std_logic; --CLK for changing data.
  RESET : in std_logic;
  START : in std_logic;
  SDA: inout std_logic;
  DATAREAD : out std_logic_vector(7 downto 0);   --Data received from the Master I2C
  DATAWRITE: in std_logic_vector(7 downto 0)     --Data sent to the Master I2C
   );
END COMPONENT;


COMPONENT PWM_Generator 
  Port ( 
  CLK: in std_logic;
  RESET: in std_logic;
  ANGULAR : in std_logic_vector(7 downto 0);
  PWM : out std_logic
  );
END COMPONENT;
signal SCL_s,SdCLK_s,START_s : std_logic;
begin
uutCLK: I2C_ReceiveSCL
PORT MAP(
        CLK=>CLK,
        SCL_in =>SCL,
        SCL_out => SCL_s,
        START => START_s,
        SdCLK => SdCLK_s
);

uutFSM: I2CFsm_Slave
PORT MAP(
  SCL =>SCL_s,
  CLK_DATA =>SdCLK_s,
  RESET =>RESET,
  START => START_s,
  SDA =>SDA,
  DATAREAD =>Led,
  DATAWRITE => sw
);


end Behavioral;
