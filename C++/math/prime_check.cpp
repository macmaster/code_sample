/*****prime.cpp****/
/* Author: Ronny Macmaster 
 * Short script to check if an input number is prime
 * Efficiency : O(nlogn)				*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int n, val;
	cout << "Enter your number to test: "; cin >> val;
	n = sqrt(val); 
	
	for(int i = n; i >= 0; i--){
		for(int j = 0; j < val; j++){
			if(i*j == val){
				cout << i << " and " << j << " are factors!" << endl;
				return 0;
			}		
		}
	}

	cout << "no factors found..." << endl;
}