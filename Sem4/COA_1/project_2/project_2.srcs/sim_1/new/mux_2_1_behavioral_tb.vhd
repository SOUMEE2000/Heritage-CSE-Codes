library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity mux_2_1_behavioral_tb is
--Port()
end mux_2_1_behavioral_tb;


architecture Behavioral of mux_2_1_behavioral_tb is

component mux_2_1_behavioral is
 Port (  A : in STD_LOGIC;
           Sel : in STD_LOGIC;
           Y : out STD_LOGIC;
           B : in STD_LOGIC);
end component;

signal a1 : STD_LOGIC := '1';
signal b1 : STD_LOGIC := '1';
signal s1 : STD_LOGIC := '0';
signal y1 : STD_LOGIC;

begin
uut: mux_2_1_behavioral port map (A=>a1, Sel=>s1, Y=>y1, B=>b1);
stim_proc: process
begin
wait for 100ns;
s1 <= '0';
wait for 100ns;
s1 <= '1';
wait;

end process;
end Behavioral;


