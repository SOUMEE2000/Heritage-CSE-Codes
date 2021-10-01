library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Half_Adder_bv_tb is
--  Port ( );
end Half_Adder_bv_tb;

architecture Behavioral of Half_Adder_bv_tb is


component Half_Adder_bv is
Port ( A : in STD_LOGIC;
       B : in STD_LOGIC;
       C : out STD_LOGIC;
       S : out STD_LOGIC);
end component;
signal X1 : STD_LOGIC := '0';
signal Y1 : STD_LOGIC := '0';
signal Z1 : STD_LOGIC;
signal W1 : STD_LOGIC;

begin
uut: Half_Adder_bv port map (A=>X1, B=>Y1, C=>Z1, S=>W1);  
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
--W1 <= '0'; 
--Z1 <= '0';
wait; 
end process;

end Behavioral;
