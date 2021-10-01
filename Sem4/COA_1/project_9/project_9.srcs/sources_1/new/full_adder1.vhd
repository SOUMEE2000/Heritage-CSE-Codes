library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity full_adder1 is
    Port ( X : in STD_LOGIC;
           Y : in STD_LOGIC;
           Z : in STD_LOGIC;
           Sum : out STD_LOGIC;
           Carry : out STD_LOGIC);
end full_adder1;

architecture Behavioral of full_adder1 is

component Half_Adder_bv is
    Port ( A : in STD_LOGIC;
           B : in STD_LOGIC;
           S : out STD_LOGIC;
           C : out STD_LOGIC);
end component;

component testor is
    Port ( A : in STD_LOGIC;
           B : in STD_LOGIC;
           C : out STD_LOGIC);
end component;

signal S1: STD_LOGIC;  
signal C1: STD_LOGIC;  
signal C2: STD_LOGIC;  

begin
l1:Half_Adder_bv port map(X,Y,S1,C1);  
l2:Half_Adder_bv port map(S1,Z,Sum,C2);  
l3:testor port map(C1,C2,Carry);  
end Behavioral;
