library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity comparator_4 is
    Port ( A : in STD_LOGIC_VECTOR (3 downto 0);
           B : in STD_LOGIC_VECTOR (3 downto 0);
           eq : out STD_LOGIC;
           gt : out STD_LOGIC;
           lt : out STD_LOGIC);
end comparator_4;

architecture Behavioral of comparator_4 is

begin
eq<='1' when A=B else '0';
gt<='1' when A>B else '0';
lt<='1' when A<B else '0';
end Behavioral;
