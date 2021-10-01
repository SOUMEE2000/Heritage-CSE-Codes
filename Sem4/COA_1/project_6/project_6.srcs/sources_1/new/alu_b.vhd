library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity alu_b is
    Port ( A : in STD_LOGIC_VECTOR (3 downto 0);
           B : in STD_LOGIC_VECTOR (3 downto 0);
           CH : in STD_LOGIC_VECTOR (2 downto 0);
           RES : out STD_LOGIC_VECTOR (3 downto 0));
end alu_b;

architecture Behavioral of alu_b is

begin
process(A,B,CH)
begin
case CH is
when "000"=>RES<=A+B;
when "001"=>RES<=A-B;
when "010"=>RES<=A+1;
when "011"=>RES<=A-1;
when "100"=>RES<=A AND B;
when "101"=>RES<=A OR B;
when "110"=>RES<=NOT A;
when "111"=>RES<=A XOR B;
when others=>NULL;
end case;
end process;

end Behavioral;
