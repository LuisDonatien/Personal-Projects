library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity top is

	port(
    	B1        : in std_logic; --Botón 1
    	B2        : in std_logic; --Botón 2
    	B3        : in std_logic; --Botón 3
    	B4        : in std_logic; --Botón 4
    	B5        : in std_logic; --Botón 5
    	enable    : in std_logic; --Enable
        nivel     : in std_logic_vector(3 downto 0); --Nivel en el que nos encontramos
        clk       : in std_logic; --Reloj
        salida    : out std_logic_vector(1 downto 0)
        --secuencia : out std_logic_vector(9 downto 0); --Secuencia completa que pasa al comparador
        --enable_comp : out std_logic
    );
    
end entity;

architecture behavioral of top is

signal btn_edge_1, btn_edge_2, btn_edge_3, btn_edge_4, btn_edge_5: std_logic;
signal secuencia_i: std_logic_vector(24 downto 0);
signal enable_comp: std_logic;

COMPONENT TOP_DEBOUNCER
PORT(
  CLK : in std_logic;
  ASYNC_IN : in std_logic;
  EDGE_OUT : out std_logic
);
END COMPONENT;

component gestor_secuencia
port (
        B1        : in std_logic; --Botón 1
    	B2        : in std_logic; --Botón 2
    	B3        : in std_logic; --Botón 3
    	B4        : in std_logic; --Botón 4
    	B5        : in std_logic; --Botón 5
    	enable    : in std_logic; --Enable
        nivel     : in std_logic_vector(3 downto 0); --Nivel en el que nos encontramos
        clk       : in std_logic;
        secuencia : out std_logic_vector(24 downto 0); --Secuencia completa que pasa al comparador
        enable_comp : out std_logic
);
end component;

component bloque_comparador
port (
	   Secuencia      : in std_logic_vector(24 downto 0);
       CLK            : in std_logic;	 
       Nivel          : in std_logic_vector(3 downto 0);
       Enable         : in std_logic;
       Salida         : out std_logic_vector(1 downto 0)    
);
end component;

begin

deb1 : TOP_DEBOUNCER PORT MAP(
  CLK => CLK,
  ASYNC_IN => B1,
  EDGE_OUT => btn_edge_1
);

deb2 : TOP_DEBOUNCER PORT MAP(
  CLK => CLK,
  ASYNC_IN => B2,
  EDGE_OUT => btn_edge_2
);

deb3 : TOP_DEBOUNCER PORT MAP(
  CLK => CLK,
  ASYNC_IN => B3,
  EDGE_OUT => btn_edge_3
);

deb4 : TOP_DEBOUNCER PORT MAP(
  CLK => CLK,
  ASYNC_IN => B4,
  EDGE_OUT => btn_edge_4
);

deb5 : TOP_DEBOUNCER PORT MAP(
  CLK => CLK,
  ASYNC_IN => B5,
  EDGE_OUT => btn_edge_5
);


Inst_gstr: gestor_secuencia Port map (
    B1 => btn_edge_1,
    B2 => btn_edge_2,
    B3 => btn_edge_3,
    B4 => btn_edge_4,
    B5 => btn_edge_5,
    enable => enable,
    nivel => nivel,
    clk => clk,
    secuencia => secuencia_i,
    enable_comp => enable_comp
);

Inst_comp: bloque_comparador Port map (
	   Secuencia => secuencia_i,
       CLK => clk,
       Nivel => nivel,
       Enable => enable_comp,
       Salida => salida
);
end architecture;