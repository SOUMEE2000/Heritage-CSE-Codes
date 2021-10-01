library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity mux_2_1_behavioral is
    Port ( A : in STD_LOGIC;
           Sel : in STD_LOGIC;
           Y : out STD_LOGIC;
           B : in STD_LOGIC);
end mux_2_1_behavioral;

architecture Behavioral of mux_2_1_behavioral is

begin

Y<=A when Sel='0' else B;
end Behavioral;
