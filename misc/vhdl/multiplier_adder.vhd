----------multiplier_adder.vhd---------------------------------
-- Lab 7
-- Ronny Macmaster
-- 
-- Computes the value of the equation:
-- W  = X * Y + Z
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
	signal state, nextstate : std_logic_vector(0 to 2);
	signal state_output: std_logic_vector(0 to 2);
	
	signal State, Nextstate: integer range 0 to 9;
	signal ACC: std_logic_vector(8 downto 0); -- accumulator
	alias M: std_logic is ACC(0); -- M is bit 0 of ACC
	signal addout: std_logic_vector(4 downto 0); -- adder output including carry
	signal Load, Ad, Sh: std_logic;
	
begin
	-- update the state outputs
	state_output <= state;
	Q3 <= state_output(2);
	Q2 <= state_output(1);
	Q1 <= state_output(0);
	
	process(state, x)
	begin
		case state is
		--state 0
		when "000" =>
			if(x = '0') then
				Z <= '0';
				nextstate <= "001";
			else
				Z <= '0';
				nextstate <= "000";
			end if;

		--state 1
		when "001" =>
			if(x = '0') then
				Z <= '0';
				nextstate <= "000";
			else
				Z <= '0';
				nextstate <= "010";
			end if;
		
		--state 2
		when "010" =>
			if(x = '0') then
				Z <= '0';
				nextstate <= "011";
			else
				Z <= '0';
				nextstate <= "010";
			end if;

		--state 3
		when "011" =>
			if(x = '0') then
				Z <= '0';
				nextstate <= "011";
			else
				Z <= '0';
				nextstate <= "100";
			end if;
		
		--state 4
		when "100" =>
			if(x = '0') then
				Z <= '0';
				nextstate <= "101";
			else
				Z <= '0';
				nextstate <= "010";
			end if;
		
		--state 5
		when "101" =>
			if(x = '0') then
				Z <= '0';
				nextstate <= "011";
			else
				Z <= '1';
				nextstate <= "100";
			end if;
		
		-- default pass
		when others =>
			null;
		
		end case;
	end process;
	
	-- clock edge or asynch reset
	process(clk, rst)
	begin
		if (rst = '1') then
			state <= "000";
		elsif (clk'event and clk = '1') then
			state <= nextstate;
		end if;
	end process;
	
end layout;

