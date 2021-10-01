-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;
entity mux_4_1_behavioral is
Port ( IP : in STD_LOGIC_VECTOR (7 downto 0);
S : in STD_LOGIC_VECTOR (2 downto 0);
Y : out STD_LOGIC);
end mux_4_1_behavioral;
architecture Behavioral of mux_4_1_behavioral is
begin
--y<=ip(0) when s="000" else
--ip(1) when s="001" else
--ip(2) when s="010" else
--ip(3) when s="011" else
--ip(4) when s="100" else
--ip(5) when s="101" else
--ip(6) when s="110" else
--ip(7);

y<= ((not s(0))and(not s(1))and(not s(2))and ip(0)) or 
((not s(0))and(not s(1))and s(2) and ip(1)) or 
((not s(0))and s(1) and (not s(2))and ip(2)) or 
((not s(0))and s(1) and s(2) and ip(3)) or 
(s(0)and(not s(1))and(not s(2))and ip(4)) or
(s(0)and s(1)and(not s(2))and ip(5)) or 
(s(0)and s(1) and (not s(2))and ip(6)) or
(s(0)and s(1)and s(2)and ip(7));
end Behavioral;