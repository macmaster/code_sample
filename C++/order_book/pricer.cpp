/****************************Order Book Pricer**********************************/
/* Author: Ronald Macmaster
 * Date: 1/31/2016
 *
 * Purpose: Analyzes an order book log file. 
   Reads a market data log on standard input. 
   As the book is modified, 
   Pricer prints (on standard output) the total expense you would incur 
		if you bought target-size shares 
			(by taking as many asks as necessary, lowest first), 
		and the total income you would receive if you sold target-size shares 
			(by hitting as many bids as necessary, highest first). 
	Each time the income or expense changes, it prints the changed value.
 *
 * Inputs: target-size (command_line argument) 
 *																										*/
 
 #include <iostream>
 
 using namespace std;
 
 int main(){
	 
	 string input;
	 while(getline(cin, input)){
		 cout << input << endl;
	 }
	 
 }