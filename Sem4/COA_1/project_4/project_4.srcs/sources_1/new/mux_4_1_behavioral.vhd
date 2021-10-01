-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;

entity mux_2_1_behavioral is
Port ( IP : in STD_LOGIC_VECTOR (1 downto 0);
       S : in STD_LOGIC ;
       Y : out STD_LOGIC);
end mux_2_1_behavioral;

architecture Behavioral of mux_2_1_behavioral is

begin
process(IP,S)
begin
case S is
when '0' =>
Y<=IP(0);
when '1' =>
Y<=IP(1);

when others=>NULL;
end case;
end process;
end Behavioral;