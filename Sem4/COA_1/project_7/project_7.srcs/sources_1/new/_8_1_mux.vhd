----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 09/28/2021 08:35:48 PM
-- Design Name: 
-- Module Name: _8_1_mux - Behavioral
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

entity mux_8_1 is
    Port ( IP : in STD_LOGIC_VECTOR (7 downto 0);
           S : in STD_LOGIC_VECTOR (2 downto 0);
           Y : out STD_LOGIC);
end mux_8_1;



architecture Behavioral of mux_8_1  is

component mux_4_1_behavioral is
    Port ( IP : in STD_LOGIC_VECTOR (3 downto 0);
    S : in STD_LOGIC_VECTOR (1 downto 0);
    Y : out STD_LOGIC);
    
end component;

component mux_2_1_behavioral is
Port ( A : in STD_LOGIC;
           Sel : in STD_LOGIC;
           B : in STD_LOGIC;
           Y : out STD_LOGIC);
end component;


signal y1 : STD_LOGIC; 
signal y2 : STD_LOGIC;  
begin
  
l1: mux_4_1_behavioral port map(ip(7 downto 4),s(1 downto 0),y1);  
l2: mux_4_1_behavioral port map(ip(3 downto 0),s(1 downto 0),y2);  
l3: mux_2_1_behavioral port map (y2,y1,s(2),y);  

end Behavioral;  

