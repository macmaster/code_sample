#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(){
	
	// print the data values
	std::vector<int> values = {9, 3, 6, 3, 2};
	int count = 0;
	for(int value : values){
		std::cout << "value #" << count << " ";
		std::cout << value << std::endl;
		count += 1;
	}
	std::cout << "next phase ...\n";
	
	// print the numbers in one line
	count = 0;
	std::string output = "";
	for(int value : values){
		output += std::to_string(value) + ", ";
	}
	std::cout << output << std::endl;

	// parse some user input
	std::cout << "\n\n";
	std::cout << "Please type a message to continue...\n";
	std::getline(std::cin, output);

	// reverse the message
	std::reverse(output.begin(), output.end()); 
	std::cout << "Your message: " << output << std::endl;

}
