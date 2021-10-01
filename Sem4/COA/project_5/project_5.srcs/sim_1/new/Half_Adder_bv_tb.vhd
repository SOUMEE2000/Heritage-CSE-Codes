----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 09/08/2021 03:45:32 PM
-- Design Name: 
-- Module Name: Half_Adder_bv_tb - Behavioral
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

entity Half_Adder_bv_tb is
--  Port ( );
end Half_Adder_bv_tb;

architecture Behavioral of Half_Adder_bv_tb is


component Half_Adder_bv is
Port ( A : in STD_LOGIC;
       B : in STD_LOGIC;
       C : out STD_LOGIC;
       S : out STD_LOGIC);
 --  Port ( X : in STD_LOGIC;
 --         Y : in STD_LOGIC;
 --         Z : in STD_LOGIC;
 --         carry : out STD_LOGIC;
 --         sum : out STD_LOGIC);
end component;
signal X1 : STD_LOGIC := '0';
signal Y1 : STD_LOGIC := '0';
signal Z1 : STD_LOGIC := '0';
--signal Z1 : STD_LOGIC;
signal W1 : STD_LOGIC;
--signal C1 : STD_LOGIC;

begin
uut: Half_Adder_bv port map (A=>X1, B=>Y1, C=>Z1, S=>W1);  
--uut: testand1 port map (X=>X1, Z=>Z1); 
--uut: Half_Adder_bv port map (X=>X1, Y=>Y1, Z=>Z1, sum=>W1, carry=>C1);
stim_proc: process 
begin 
wait for 100ns;
X1 <= '0'; 
Y1 <= '0'; 
--W1 <= '0'; 
--Z1 <= '0';
wait for 100ns; 
X1 <= '0'; 
Y1 <= '1'; 
--W1 <= '0'; 
--Z1 <= '0';
wait for 100ns; 
X1 <= '1'; 
Y1 <= '0'; 
--W1 <= '0'; 
--Z1 <= '1';
wait for 100ns;
X1 <= '1'; 
Y1 <= '1'; 
--W1 <= '0'; 
--Z1 <= '0';
wait; 
end process;

end Behavioral;
