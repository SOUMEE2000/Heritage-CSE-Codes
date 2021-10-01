-- Code your testbench here
library IEEE;
use IEEE.std_logic_1164.all;

entity decoder_3_8_tb is
-- Port ( );
end decoder_3_8_tb;

architecture Behavioral of decoder_3_8_tb is 

component decoder_3_8_bv is
Port ( ip : in STD_LOGIC_VECTOR (2 downto 0);
       op : out STD_LOGIC_VECTOR (7 downto 0));
end component;

signal ip1 : STD_LOGIC_VECTOR (2 downto 0) := "000";
signal op1 : STD_LOGIC_VECTOR (7 downto 0);
begin
uut: decoder_3_8_bv port map (ip=>ip1, op=>op1);
stim_proc: process
begin
wait for 100ns;
ip1 <= "001";
wait for 100ns;
ip1 <= "010";
wait for 100ns;
ip1 <= "011";
wait for 100ns;
ip1 <= "100";
wait for 100ns;
ip1 <= "101";
wait for 100ns;
ip1 <= "110";
wait for 100ns;
ip1 <= "111";
wait;
end process;
end Behavioral;