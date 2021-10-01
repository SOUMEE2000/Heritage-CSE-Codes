----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 09/08/2021 03:43:41 PM
-- Design Name: 
-- Module Name: Half_Adder_bv - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Half_Adder_bv is
Port ( A : in STD_LOGIC;
       B : in STD_LOGIC;
       C : out STD_LOGIC;
       S : out STD_LOGIC);
--   Port ( X : in STD_LOGIC;
--          Y : in STD_LOGIC;
--          Z : in STD_LOGIC;
--          carry : out STD_LOGIC;
--          sum : out STD_LOGIC);
end Half_Adder_bv;

architecture Behavioral of Half_Adder_bv is

begin
process(a,b)
begin
if(a=b)then
s<='0';
else
s<='1';
end if;
if(a='1')and(b='1')then
c<='1';
else
c<='0';
end if;

--sum <= x xor y xor z;
--carry <= (x and y)or(y and z)or (z and x);
--s <= a xor b;
--c <= a and b;
--process(x,y,z)
--begin
--if(x='0')then
--if(y=z) then
--sum<='0';

--else

--sum<='1';

--end if;
--if(y='1' and z='1')then
--carry<='1';

--else

--carry<='0';

--end if; 
--end if;
--if(x='1')then
--if(y=z)then
--sum<='1';
--else
--sum<='0';
--end if;
--if(y='0' and z='0')then
--carry<='0';
--else
--carry<='1';
--end if;
--end if;
end process;

end Behavioral;
