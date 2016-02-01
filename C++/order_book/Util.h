/****************************Util.h**********************************/
/* Author: Ronald Macmaster
 * Date: 2/1/2016
 *
 * Description: Util driver for string manip
 *																	*/

 #include <string>
 #include <cstdlib>
 
 using namespace std;

/****************************stof()****************************************/
/* Purpose: Convert a String into a floating point number
 * Input: num_str) string that has the value to be parsed
 * Ouput: num_value) floating point value of str (throws exception on fail)
/**************************************************************************/
float stof(string num_str);

/****************************stoi()****************************************/
/* Purpose: Convert a String into an integer number
 * Input: num_str) string that has the value to be parsed
 * Ouput: num_value) integer value of str (throws exception on fail)
/**************************************************************************/
int stoi(string num_str);
