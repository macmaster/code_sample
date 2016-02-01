/*******************************Util.cpp******************************************/
/* Author: Ronald Macmaster
 * Date: 2/1/2016
 *
 * Util driver implementation for string manipulation 				             */
 
 #include "Util.h"
 
/****************************stof()****************************************/
/* Purpose: Convert a String into a floating point number
 * Input: num_str) string that has the value to be parsed
 * Ouput: num_value) floating point value of str (throws exception on fail)
/**************************************************************************/
float stof(string num_str){
	const int buff_size = 50;
	char num_buff[buff_size];
	int n = num_str.length();
	if(n > buff_size){ n = buff_size;} // cap the buffer
	
	// copy number to buffer
	for(int i = 0; i < n; i++){ 
		num_buff[i] = num_str[2*i + 1]; // parse unicode (16-bit) characters 
	}
	return atof(num_buff);
}

/****************************stoi()****************************************/
/* Purpose: Convert a String into an integer number
 * Input: num_str) string that has the value to be parsed
 * Ouput: num_value) integer value of str (throws exception on fail)
/**************************************************************************/
int stoi(string num_str){
	const int buff_size = 50;
	char num_buff[buff_size];
	int n = num_str.length();
	if(n > buff_size){ n = buff_size;} // cap the buffer
	
	// copy number to buffer
	for(int i = 0; i < n; i++){ 
		num_buff[i] = num_str[2*i + 1]; // parse unicode (16-bit) characters 
	}
	return atoi(num_buff);
}
