/** Knapsack.cpp
 * dynamic programming driver
 * solves the knapsack problem,
 * input v[], w[]
 */

#include <iostream>
#include <vector>
#include <string>

void inputInteger(std::string msg, int &value);
int main(){
	int n = 0, capacity = 0;
	std::vector<int> value, weight;
	inputInteger("enter the item count, N: ", n);
	inputInteger("enter the capacity, W: ", capacity);
	
	// DEBUG: print cap params
	//std::cout << "(N, W) = ";
	//std::cout << "(" << n << ", " << capacity << ")" << std::endl;
	for(int i = 0; i < n; i++){
		int v = 0, w = 0;
		std::string valueMsg, weightMsg;
		valueMsg = "Enter item " + std::to_string(i) + "'s value: ";
		weightMsg = "Enter item " + std::to_string(i) + "'s weight: ";
		inputInteger(valueMsg, v);
		inputInteger(weightMsg, w);
		value.push_back(v);
		weight.push_back(w);
	}

	// print vectors
	std::cout << "{";
	std::cout << "(" << value[0] << ", " << weight[0] << ")";
	for(int i = 1; i < n; i++){
		std::cout << ", ";
		std::cout << "(" << value[i] << ", " << weight[i] << ")";
	}
	std::cout << "}" << std::endl;
}

void inputInteger(std::string msg, int &value){
	while(true){
		std::cout << msg;
		std::cin >> value;
		if(std::cin.fail()){
			std::cout << "error: your input could not be read. please try again...";
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		} else{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			return; // parsing successful.
		}
	}
}
