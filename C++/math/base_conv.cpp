/******************************* Base Conversion ********************************/
/* Author: Ronald MacMaster
 * Date: 1/15/2016
 * Description: Simple script which converts input number to another base       */
 
 #include <iostream>
 #include <map>
 
 using namespace std;
 
 void fill_maps(map<char, int>& value_map, map<char, int>& char_map);
 void inline check_base(int base);
 void inline clear_input();
 string uppercase(string old_str);
 
 
 int main(){
	 
	 char flag = 'n';
	 int base = 0, new_base = 0;
	 int sign = 1, total = 0;
	 string input, output;
	 map<char, int> value_map; 
	 map<int, char> char_map;
	 
	 //init base & val map
	 fill_maps((map<char, int>&)value_map, (map<char, int>&)char_map);
	 
	 while((flag != 'y') && (flag != 'Y')){
		 
		 //welcome prompt
		 cout << "Welcome to Base Converter" << endl;
		 cout << "Enter your number: "; cin >> input; clear_input();
		 
		 
		 // init input & output
		 input = uppercase(input);
		 output = "";
		 
		 //init sign, total, and bases
		 sign = 1, total = 0;
		 cout << "Enter its base: "; 
		 if(!(cin >> base)) clear_input; //gaurd bad input
		 cout << "Enter its new base: "; 
		 if(!(cin >> new_base)) clear_input(); 
		 
		 // cout << "input: " << input << endl; // input debug print
		 
		 try{
			 
			//check for valid bases
			check_base(base);
			check_base(new_base);
			
			// parse sign
			if(!input.empty())
				if(input[0] == '+'){
					sign = 1;
					input = input.substr(1);
				}
				else if(input[0] == '-'){
					sign = -1;
					input = input.substr(1);
				}
			
			//calculate total
			int place = 0;
			for(string::reverse_iterator itr = input.rbegin(); itr != input.rend(); itr++){
				int val = value_map[*itr];
				if((*itr < 'A' || *itr > 'Z')&&(*itr < '0' || *itr > '9')){
					total = 0;
					throw "Error: Number is invalid!";
				}
				if(val >= base){
					total = 0;
					throw "Error: Number is not in base set!";
				}
				for(int i = 0; i < place; i++){
					val *= base;
				}
				total += val;
				place++;
			}
		
			//output number
			 cout << "Decimal Total: " << sign*total << endl; // output debug print
			
			//special conditions
			if(sign == -1){ 
				output.insert(output.begin(), '-'); //negative number
			}
			if(total == 0){
				output.insert(output.begin(),'0');  //zero number
			}
			
			//convert to new_base
			while(total > 0){
				char char_val = char_map[total % new_base];
				total /= new_base;
				output.insert(output.begin(), char_val);
			}
			
			
			
		 }
		 catch(const char* exception){
			 cout << exception << endl;
		 }
		 catch(...){
			 cout << "Error: (Unknown Error) :p" << endl; 
		 }
		 
		 // ouput number
		 cout << "Your new number in base " << new_base << " is: " << output << endl;
		 //quit prompt
		 cout << "Would you like to quit (y/n)? "; cin >> flag; cout << endl; clear_input();
		 
	 }
	 
 
 }
 
 void fill_maps(map<char, int>& value_map, map<char, int>& char_map){
	 //init base & char map
	 int i; char c;
 	 for(i = 0, c = '0'; i < 10; i++, c++){ // nums 0-9
		 value_map[c] = i;
		 char_map[i] =  c;
	 }
	 
	 for(i = 10, c = 'A'; i < 36; i++, c++){ // chars A-Z
		 value_map[c] = i;
		 char_map[i] =  c;
	 }
 }
 
 void inline check_base(int base){
	 if(base <= 0)
		throw "Error: base too low!";
	 else if(base > 36)
		throw "Error: base too high!";
 }
 
 void inline clear_input(){
	 cin.clear();
	 cin.ignore(1000,'\n');
 }
 
 string uppercase(string old_str){
	 string new_str = old_str;
	 for(string::iterator itr = new_str.begin(); itr != new_str.end(); itr++){
		 if(*itr >= 'a' && *itr <= 'z'){// capitalize the letter if it is lowercase
			 *itr -= 'a'-'A'; //case offset
		 }
	 }
	 return new_str;
 }