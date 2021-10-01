-- Code your testbench here
library IEEE;
use IEEE.std_logic_1164.all;

entity comparator_4_tb is
-- Port ( );
end comparator_4_tb;

architecture Behavioral of comparator_4_tb is

component comparator_4 is
Port ( A : in STD_LOGIC_VECTOR (3 downto 0);
B : in STD_LOGIC_VECTOR (3 downto 0);
eq : out STD_LOGIC;
gt : out STD_LOGIC;
lt : out STD_LOGIC);
end component;

signal A1 : STD_LOGIC_VECTOR (3 downto 0) := "0000";
signal B1 : STD_LOGIC_VECTOR (3 downto 0) := "0000";
signal eq1 : STD_LOGIC;
signal gt1 : STD_LOGIC;
signal lt1 : STD_LOGIC;
begin
uut: comparator_4 port map (A=>A1, B=>B1, eq=>eq1, gt=>gt1, lt=>lt1);
stim_proc: process
begin
wait for 100ns;
A1 <= "0001";
B1 <= "0010";
wait for 100ns;
A1 <= "0101";
B1 <= "0101";
wait for 100ns;
A1 <= "0101";
B1 <= "0011";
wait;
end process;
end Behavioral;