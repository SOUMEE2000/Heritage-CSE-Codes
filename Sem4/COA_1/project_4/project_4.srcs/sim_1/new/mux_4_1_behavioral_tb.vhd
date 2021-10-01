-- Code your testbench here
library IEEE;
use IEEE.std_logic_1164.all;

entity mux_2_1_behavioral_tb is
-- Port ( );
end mux_2_1_behavioral_tb;

architecture Behavioral of mux_2_1_behavioral_tb is

component mux_2_1_behavioral is
Port ( IP : in STD_LOGIC_VECTOR (1 downto 0);
S : in STD_LOGIC;
Y : out STD_LOGIC);
end component;

signal iP1 : STD_LOGIC_VECTOR (1 downto 0) := "01";
signal s1 : STD_LOGIC := '0';
signal y1 : STD_LOGIC;
begin
uut: mux_2_1_behavioral port map (ip=>ip1, s=>s1, y=>y1);
stim_proc: process
begin
wait for 100ns;
s1 <= '0';
wait for 100ns;
s1 <= '1';
wait;

end process;
end Behavioral;