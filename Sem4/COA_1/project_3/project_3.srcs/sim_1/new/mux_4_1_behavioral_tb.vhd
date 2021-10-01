-- Code your testbench here
library IEEE;
use IEEE.std_logic_1164.all;
entity mux_4_1_behavioral_tb is
-- Port ( );
end mux_4_1_behavioral_tb;

architecture Behavioral of mux_4_1_behavioral_tb is

component mux_4_1_behavioral is
Port ( IP : in STD_LOGIC_VECTOR (7 downto 0);
       S : in STD_LOGIC_VECTOR (2 downto 0);
       Y : out STD_LOGIC);
end component;

signal ip1 : STD_LOGIC_VECTOR (7 downto 0) := "00000101";
signal s1 : STD_LOGIC_VECTOR (2 downto 0) := "000";
signal y1 : STD_LOGIC;
begin
uut: mux_4_1_behavioral port map (IP=>ip1, S=>s1, Y=>y1);
stim_proc: process
begin
wait for 100ns;
s1 <= "000";
wait for 100ns;
s1 <= "001";
wait for 100ns;
s1 <= "010";
wait for 100ns;
s1 <= "011";
wait for 100ns;
s1 <= "100";
wait for 100ns;
s1 <= "101";
wait for 100ns;
s1 <= "110";
wait for 100ns;
s1 <= "111";
wait;
end process;
end Behavioral;