library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity testor_tb is
--  Port ( );
end testor_tb;

architecture Behavioral of testor_tb is
component testor is
Port ( A : in STD_LOGIC;
       B : in STD_LOGIC;
       C : out STD_LOGIC);
end component;
signal X1 : STD_LOGIC := '0';
signal Y1 : STD_LOGIC := '0';
signal Z1 : STD_LOGIC;

begin
uut: testor port map (A=>X1, B=>Y1, C=>Z1);  
stim_proc: process 
begin 
wait for 100ns;
X1 <= '0'; 
Y1 <= '0'; 
wait for 100ns; 
X1 <= '0'; 
Y1 <= '1'; 
wait for 100ns; 
X1 <= '1'; 
Y1 <= '0'; 
wait for 100ns;
X1 <= '1'; 
Y1 <= '1'; 
wait; 
end process;
end Behavioral;
