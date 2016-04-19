------------------------------------------------------------
-- Ronny Macmaster
-- Lab 6 pt1
-- 8 bit accumulator for subtraction
--
-- Acc is current accumulator value
-- D is data input
-- A and B are control signals
-- 	00: Acc remains the same
--		01: Shift right zero extend
-- 	10: D loaded into Acc
-- 	11: D subtracted from Acc
------------------------------------------------------------

library ieee;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;


entity accumulator is
	port( D : in std_logic_vector(7 downto 0);
			Acc : out std_logic_vector(7 downto 0);
			AB : in std_logic_vector(1 downto 0);
			CLK : in std_logic);
end accumulator;

architecture layout of accumulator is
	-- subtracter output
	signal Sub : std_logic_vector(7 downto 0);
	signal Accval : std_logic_vector(7 downto 0);
	
begin
	-- update subratcter
	Sub <= Accval - D;
	Acc <= Accval;
	process(CLK)
	begin
		-- rising edge
		if CLK'event and CLK = '1' then
		
			-- acc remains same
			if(AB = "00") then 
				Accval <= Accval;
			
			-- shift right acc zero-extend
			elsif(AB = "01") then 
				Accval <= '0' &  Accval(7 downto 1);
			
			-- load D into acc
			elsif(AB = "10") then 
				Accval <= D;
			
			-- subtract D from acc
			else 
				Accval <= Sub;
			end if;
		end if;
		
end process;
end layout;
