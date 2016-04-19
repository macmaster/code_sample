------------------------------------------------------------
-- Ronny Macmaster
-- 4 to 1 mux module
--
-- W, X, Y, Z are Component inputs
-- A and B are control signals
-- 
-- Lab 5 pt1
------------------------------------------------------------

library ieee;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;

entity mux4to1 is 
	port(W, X, Y, Z : in std_logic;
		  AB : in std_logic_vector(1 downto 0);
		  O : out std_logic);
end mux4to1;

architecture layout of mux4to1 is
	signal var: std_logic;
begin

process(O, W, X, Y, Z)
begin

-- mux control logic 
if(AB = "00") 
then var <= W;

elsif(AB = "01") 
then var <= X;

elsif(AB = "10") 
then var <= Y;

else var <= Z;
end if;                            

-- set mux output
O <= var;

end process;
end layout; 
