library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity testor is
    Port ( A : in STD_LOGIC;
           B : in STD_LOGIC;
           C : out STD_LOGIC);
end testor;

architecture Behavioral  of testor is

begin
   --process(a,b)
   --begin
    -- if(a='0')and(b='0')then
     --  c<='0';
     --else
      -- c<='1';
     --end if;
   --end process;
   c <= a or b;
end Behavioral;
