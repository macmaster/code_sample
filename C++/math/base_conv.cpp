/******************************* Base Conversion ********************************/
/* Author: Ronald MacMaster
 * Date: 1/15/2016
 * Description: Simple script which converts input number to another base       */
 
 #include <iostream>
 #include <map>
 
 using namespace std;
 
 void fill_maps(map<char, int>& value_map, map<char, int>& char_map);
 void check_base(int base);
 string uppercase(string old_str);
 
 int main(){
	 
	 char flag = 'n';
	 int base = 0, new_base = 0;
	 int sign = 1, total = 0;
	 string input, output;
	 map <char, int> value_map; 
	 map <int, char> char_map;
	 
	 //init base & val map
	 fill_maps(value_map, char_map);
	 
	 while((flag != 'y') && (flag != 'Y')){
		 
		 //welcome prompt
		 cout << "Welcome to Base Converter" << endl;
		 cout << "Enter your number: "; cin >> input;
		 
		 //init sign, total, and bases
		 sign = 1, total = 0;
		 cout << "Enter your base: "; cin >> base;
		 cout << "Enter your new base: "; cin >> new_base;
		 
		 // cout << "input: " << input << cout << endl; // input debug print
		 
		 try{
			
			check_base(base);
			check_base(new_base);			
			
			string::iterator itr = input.begin();
			
			// parse sign
			if(itr != input.end())
				if(*itr == '+'){
					sign = 1;
					itr++;
				else if(*itr == '-'){
					sign = -1;
					itr++;
				}
			
			while(itr != input.end()){
				total += value_map.get(*itr);
			}
		 }
		 catch(const char* exception){
			 cout << exception << endl;
		 }
		 
		 
		 //quit prompt
		 cout << "Would you like to quit (y/n)? "; cin >> flag;
		 
	 }
	 
 
 }
 
 void fill_maps(map<char, int>& value_map, map<char, int>& char_map){
	 //init base & char map
 	 for(int i = 0, char c = '0'; i < 10; i++, c++){ // nums 0-9
		 value_map.put(c, i);
		 char_map.put(i, c);
	 }
	 
	 for(int i = 10, char c = 'A'; i < 36; i++, c++){ // chars A-Z
		 value_map.put(c, i);
		 char_map.put(i, c);
	 }
 }
 
 void inline check_base(int base){
	 if(base <= 0)
		throw "Error: base too low!";
	 else if(base > 36)
		throw "Error: base too high!";
 }
 
 string uppercase(string old_str){
	 
 }