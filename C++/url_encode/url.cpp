/********** url.cpp *****************************
 * 
 * url encode the input url string
 * convert each character into asci char code
 *
 * Author: Ronald Macmaster
 * Date: May 27th 2016
 *
 ***********************************************/

#include <iostream>

using namespace std;

int main(){
	
	// prompt
	string url;
	cout << "Enter your url: "; cin >> url;

	//print
	int n = url.length();
	for(int i = 0; i < n; i++){
		switch((int)url[i]){
		  
		  case '.':
			cout << ".";
		  	break;
		  
		  case '/':
			cout << "/";
			break;
		  
		  default:
			cout << "%" << hex << (int)url[i];
		}
	}

}
