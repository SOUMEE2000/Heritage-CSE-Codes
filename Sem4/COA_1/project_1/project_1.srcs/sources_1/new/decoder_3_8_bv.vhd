-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;

entity decoder_3_8_bv is
Port ( ip : in STD_LOGIC_VECTOR (2 downto 0);
       op : out STD_LOGIC_VECTOR (7 downto 0));
end decoder_3_8_bv;

architecture Dataflow of decoder_3_8_bv is
begin
op(0) <= '1' when ip="000" else '0';
op(1) <= '1' when ip="001" else '0';
op(2) <= '1' when ip="010" else '0';
op(3) <= '1' when ip="011" else '0';
op(4) <= '1' when ip="100" else '0';
op(5) <= '1' when ip="101" else '0';
op(6) <= '1' when ip="110" else '0';
op(7) <= '1' when ip="111" else '0';
end Dataflow;