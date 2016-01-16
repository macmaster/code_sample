/******************************* Base Conversion ********************************/
/* Author: Ronald MacMaster
 * Date: 1/15/2016
 * Description: Simple script which converts input number to another base       */
 
 #include <iostream>
 #include <unordered_map>
 
 using namespace std;
 
 typedef int number;
 int main()
 {
	 
	 char flag = 'n';
	 string input, output;
	 unordered_map < char, int> base_map, value_map; 
	 
	 
	 while((flag != 'y') || (flag != 'n'))
	 {
		 //welcome prompt
		 cout << "Welcome to Base Converter" << endl;
		 cout << "Enter your number: "; cin >> input_num;
		 
		 //quit prompt
		 cout << "Would you like to quit? (y/n)";
		 
	 }
	 
 
 }