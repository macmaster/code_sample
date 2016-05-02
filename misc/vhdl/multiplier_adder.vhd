----------multiplier_adder.vhd------------------------------
-- Lab 7
-- Ronny Macmaster
-- 
-- Computes the value of the equation:
-- W  = X * Y + Z
-- 
-- W is 5 bits
-- X is 3 bits
-- Y is 5 bits
-- Z is 5 bits
------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164. all;
use IEEE.STD_LOGIC_ARITH. all;
use IEEE.STD_LOGIC_UNSIGNED. all;

entity multiplier_adder is
	port (Clock, Start, Reset: in std_logic;
			X: in std_logic_vector(2 downto 0);
			Y, Z: in std_logic_vector(4 downto 0);
			Result: out std_logic_vector(7 downto 0);
			Done: out std_logic);
end multiplier_adder;

architecture control_signals of multiplier_adder is
	-- state machine
	signal state, nextstate: integer range 0 to 13;
	
	-- register signals
	signal ACC, W: std_logic_vector(8 downto 0); 
	alias M: std_logic is ACC(0); -- M is bit 0 of ACC
	signal LdW, LdX, LdY, LdZ, Ad, Sh: std_logic;
	
	-- arithmetic values
	signal xval: std_logic_vector(2 downto 0);
	signal zval: std_logic_vector(4 downto 0);
	signal addout: std_logic_vector(3 downto 0); 
	
begin
	-- update the arithmetic outputs
	Result <= ACC(7 downto 0);
	addout <= ('0' & ACC(7 downto 5)) + ('0' & X(2 downto 0));
	
	-- clock the registers
	process(Clock, Reset) 
	begin 
		-- asynchronous reset
		if Reset = '1' then
			state <= 0;
			ACC(8 downto 0) <= "000000000";
		end if;
		
		-- rising edge trigger
		if Clock'event and Clock = '1' then 
		
			if LdW = '1' then -- load ACC result
				ACC(8 downto 0) <= W(8 downto 0);
			end if;
			
			if LdX = '1' then -- load multiplicand
				xval(2 downto 0) <= X(2 downto 0);
			end if;
			
			if LdY = '1' then -- load multiplier / rst acc
				ACC(8 downto 5) <= "0000";
				ACC(4 downto 0) <= Y(4 downto 0); 
			end if;
			
			if LdZ = '1' then -- load addend
				zval(4 downto 0) <= Z(4 downto 0);
			end if;
			
			if Ad = '1' then -- load ACC with mult sum
				ACC(8 downto 5) <= addout; 
			end if;
			
			if Sh = '1' then -- shift the ACC
				ACC(8 downto 0) <= '0' & ACC(8 downto 1); 
			end if;
			
			state <= nextstate;
		end if;
	end process;
	
	-- state machine
	process(state, Start, M)
	begin
		-- reinit control variables
		Done <= '0';
		LdW <= '0'; LdX <= '0';	
		LdY <= '0'; LdZ <= '0';
		Ad <= '0'; Sh <= '0'; 
		
		-- state control
		case state is
		when 0 => -- Load X
			if(St = '1') then
				LdX <= '1';
				nextstate <= 1;
			else
				nextstate <= 0;
			end if;
			
		when 1 => -- Load Y
			LdY <= '1';
			nextstate <= 2;
			
		when 2 => -- Load Z
			LdZ <= '1';
			nextstate <= 3;

		when 3 => -- M Check 1
			if(M = '1') then
				Ad <= '1';
				nexstate <= 4;
			else
				Sh <= '1';
				nextstate <= 5;
			end if;
			
		when 4 => -- M Add 1
			Sh <= '1';
			nextstate <= 5;

		when 5 => -- M Check 2
			if(M = '1') then
				Ad <= '1';
				nexstate <= 6;
			else
				Sh <= '1';
				nextstate <= 7;
			end if;
			
		when 6 => -- M Add 2
			Sh <= '1';
			nextstate <= 7;

		when 7 => -- M Check 3
			if(M = '1') then
				Ad <= '1';
				nexstate <= 8;
			else
				Sh <= '1';
				nextstate <= 9;
			end if;
			
		when 8 => -- M Add 3
			Sh <= '1';
			nextstate <= 9;

		when 9 => -- M Check 4
			if(M = '1') then
				Ad <= '1';
				nexstate <= 10;
			else
				Sh <= '1';
				nextstate <= 11;
			end if;
			
		when 10 => -- M Add 4
			Sh <= '1';
			nextstate <= 11;

		when 11 => -- M Check 5
			if(M = '1') then
				Ad <= '1';
				nexstate <= 12;
			else
				Sh <= '1';
				nextstate <= 13;
			end if;
			
		when 12 => -- M Add 5
			Sh <= '1';
			nextstate <= 13;

		
		-- default pass
		when others =>
			null;
			
		end case;
	end process;
	
end control_signals;
