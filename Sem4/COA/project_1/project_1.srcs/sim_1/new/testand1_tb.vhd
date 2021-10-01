----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 09/01/2021 03:01:45 PM
-- Design Name: 
-- Module Name: testand1_tb - Behavioral
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

entity testand1_tb is
--  Port ( );
end testand1_tb;

architecture Behavioral of testand1_tb is
component testand1 is
Port ( X : in STD_LOGIC;
      -- Y : in STD_LOGIC;
       Z : out STD_LOGIC);
end component;
signal X1 : STD_LOGIC := '0';
--signal Y1 : STD_LOGIC := '0';
signal Z1 : STD_LOGIC;

begin
--uut: testand1 port map (X=>X1, Y=>Y1, Z=>Z1);  
uut: testand1 port map (X=>X1, Z=>Z1); 
stim_proc: process 
begin 
wait for 100ns;
X1 <= '0'; 
--Y1 <= '0'; 
wait for 100ns; 
X1 <= '0'; 
--Y1 <= '1'; 
wait for 100ns; 
X1 <= '1'; 
--Y1 <= '0'; 
wait for 100ns;
X1 <= '1'; 
--Y1 <= '1'; 
wait; 
end process;
end Behavioral;

