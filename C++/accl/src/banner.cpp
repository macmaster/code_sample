// main.cpp

#include <iostream>
#include <string>

int main() {
	// read username
	std::cout << "Please enter your name: ";
	std::string name;
	std::cin >> name;

	// build greeting banner
	std::string greeting = "Welcome, " + name + "!";
	std::string spaces(greeting.size(), ' ');
	std::string column = "* " + spaces + " *";
	std::string edge(column.size(), '*');

	// print banner
	std::cout << edge << std::endl;
	std::cout << column << std::endl;
	std::cout << "* " << greeting << " *" << std::endl;
	std::cout << column << std::endl;
	std::cout << edge << std::endl;

	return 0;
}
