/****************************Order Book Pricer**********************************/
/* Author: Ronald Macmaster
 * Date: 1/31/2016
 * Last Modified: 2/1/2016
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
 *																				*/
 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

#include <map>
#include "Order.h"
 
using namespace std;

void stopwatch();
int stoi(string num_str);
float stof(string num_str);

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
			command = order_string.at(1);
			order_string.erase(0, npos+1);
			
			switch(command){
				case 'A':
					Order::AddOrder(order_string, order_book);
					break;
				case 'R':
					Order::ReduceOrder(order_string, order_book);
					break;
				default:
					throw invalid_argument("invalid order command!");
			}
		}
		catch(const invalid_argument &ia){
			cerr << ia.what() << endl;
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
	price = stof(order_string.substr(0, npos)); 
	order_string.erase(0, npos+1);
	
	cout << "id: " << id <<  " price: " << price << " action: " << action <<  endl;
	
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
/****************************stopwatch()****************************************/
/* Purpose: Toggle a stopwatch
 * 1) call it to start the stopwatch
 * 2) call it to stop the stopwatch and print the results
/******************************************************************************/
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


