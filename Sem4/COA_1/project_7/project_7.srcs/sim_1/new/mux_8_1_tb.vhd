library IEEE;  
use IEEE.STD_LOGIC_1164.ALL; 
 
entity mux_8_1_tb is  
-- Port ( );  
end mux_8_1_tb; 
 
architecture Behavioral of mux_8_1_tb is  
component mux_8_1 is  
port (ip : in STD_LOGIC_VECTOR (7 downto 0);  
s : in STD_LOGIC_VECTOR (2 downto 0);  
y : out STD_LOGIC);  
end component;  

signal ip1 : STD_LOGIC_VECTOR (7 downto 0) := "00000000"; 
 signal s1 : STD_LOGIC_VECTOR (2 downto 0) := "000";  
 signal y1 : STD_LOGIC; 
  
begin  
uut : mux_8_1 port map (ip=>ip1,s=>s1,y=>y1);  
stim_proc : process  
begin  
wait for 100ns;  
ip1 <="10010001";  
s1<= "010";  
wait for 100ns;  
ip1 <="10010011";  
s1<= "011";  
wait;  
end process;  
end Behavioral;  
