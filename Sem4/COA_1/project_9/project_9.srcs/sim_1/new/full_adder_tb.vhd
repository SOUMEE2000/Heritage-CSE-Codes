library IEEE;  
use IEEE.STD_LOGIC_1164.ALL;  
entity full_adder_tb is  
-- Port ( );  
end full_adder_tb;  
architecture Behavioral of full_adder_tb is  
component full_adder1 is  
Port ( X : in STD_LOGIC;  
Y : in STD_LOGIC;  
Z : in STD_LOGIC;  
Sum : out STD_LOGIC;  
Carry: out STD_LOGIC);  
end component;  
signal X1 : STD_LOGIC := '0';  
signal Y1 : STD_LOGIC := '0';  
signal Z1 : STD_LOGIC := '0';  
signal Sum1 : STD_LOGIC;  
signal Carry1 : STD_LOGIC;  
begin  
uut: full_adder1 PORT MAP(X=>X1,Y=>Y1,Z=>Z1,Sum=>Sum1,Carry=>Carry1);  
stim_proc: process  
begin 

wait for 100 ns;  
X1<='0';  
Y1<='0';  
Z1<='1';  
wait for 100 ns;  
X1<='0';  
Y1<='1';  
Z1<='0';  
wait for 100 ns;  
X1<='0';  
Y1<='1';  
Z1<='1';  
wait for 100 ns;  
X1<='1';  
Y1<='0';  
Z1<='0';  
wait for 100 ns;  
X1<='1';  
Y1<='0';  
Z1<='1';  
wait for 100 ns;  
X1<='1';  
Y1<='1';  
Z1<='0';  
wait for 100 ns;  
X1<='1';  
Y1<='1';  
Z1<='1';  
wait;  
end process;  
end Behavioral;
