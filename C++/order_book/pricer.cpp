/****************************Order Book Pricer**********************************/
/* Author: Ronald Macmaster
 * Date: 1/31/2016
 *
 * Compile with C++11
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
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <stdexcept>

#include <map>
#include <string>
#include "Order.h"
 
using namespace std;

void stopwatch();
void AddOrder(string&, map<string, Order>&);
void ReduceOrder(string&, map<string, Order>&);

int main(int argc, char *args[]){
	 
	int target_size = 1;
	string order_string;
	map<string, Order> order_book;
	
	// Parse int from target_size
	try{ 
		target_size = atoi(args[1]);
		if(target_size <= 0){
	 		throw invalid_argument("target size less than 1!");
	 	}
	 	clog << "Target Size: " << target_size << endl; 
	}
	catch(const invalid_argument &ia){
		cerr << "Error: Invalid Target Size " <<
			"(Enter an integer greater than 0!)" << endl;
	}
	
	// Analyze Market Log
	while(getline(cin, order_string)){

		int npos;
		string time_stamp;
		char command;
		
		try{
			
			// extract time_stamp
			npos = order_string.find(" ");
			time_stamp = order_string.substr(0, npos);
			order_string.erase(0, npos+1);
			
			
			// extract command (Add/Reduce)
			npos = order_string.find(" ");
			command = order_string[1];
			order_string.erase(0, npos+1);
			
			switch(command){
				case 'A':
					AddOrder(order_string, order_book);
					break;
				case 'R':
					ReduceOrder(order_string, order_book);
					break;
				default:
					throw invalid_argument("invalid order command!");
			}
		}
		catch(...){
			cerr << "Error: Invalid order at time: " << time_stamp << endl;
		}
	}
	 
}

/****************************AddOrder()**********************************/
/* Purpose: Add an order to the order book
 * Inputs: 
 *		1) order_string: string that has the parameters to build an Order
 *		2) order_book: Database with all the current orders listed by ID  
/************************************************************************/
void AddOrder(string &order_string, map<string, Order> &order_book){	
	
	int npos;
	const int buff_size = 50;
	char num_buff[buff_size];
	string id;
	ordertype action;
	float price;
	int quantity;
	
	// extract order id
	npos = order_string.find(" ");
	id = order_string.substr(0, npos);
	order_string.erase(0, npos+1);
	
	// extract action (Buy/Sell)
	npos = order_string.find(" ");
	switch(order_string[1]){
		case 'B':
			action = buy;
			break;
		case 'S':
			action = sell;
			break;
		default:
			throw invalid_argument("invalid order action!");
	}	
	order_string.erase(0, npos+1);
	
	// extract order price
	npos = order_string.find(" ");
	string price_str = order_string.substr(0, npos);
	price_str.copy(num_buff, buff_size); 
	num_buff[price_str.length()] = '\0';
	for(int i = 0; i < 50; i++)
		cout<< i << ": " <<  num_buff[i] << endl;
	order_string.erase(0, npos+1);
	
}

/****************************ReduceOrder()**********************************/
/* Purpose: Reduce an order already in the order book
 * Inputs: 
 *		1) order_string: string that has the parameters to perform the reduce
 *		2) order_book: Database with all the current orders listed by ID  
/**************************************************************************/
void ReduceOrder(string &order_string, map<string, Order> &order_book){	
	
	int npos;
	int quantity;
	string id;
	
	// extract order id
	npos = order_string.find(" ");
	id = order_string.substr(0, npos);
	order_string.erase(0, npos+1);
	
	cout << order_string << endl;
	
	
	
}


#ifdef DEBUG
void stopwatch(){
	static int flag = 1;
	static clock_t timer;
	if(flag){
		timer = clock();
	}
	else{
		cout << " Time delay: " <<  clock()-timer << endl;
	}
	flag ^= 1;
}
#endif
