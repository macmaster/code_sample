/***************************Invest.cpp*********************************
 * Author: Ronald Macmaster
 * Date : 2/25/15
 * 
 * Faster calculation of compound interest investments
 * Solve the linear system v[n] = (1+r)v[n] + d[n]
 * 
 * v[n] = value of investment after n years
 * r = rate of return each year
 * n = number of year elapsed
 * d[n] = deposit at the end of each year ( usually a constant d)
 *
 **********************************************************************/
 
 #include <iostream>
 #include <cmath>
 
 using namespace std;
 
 int main(){
	 
	int years;
	double value, rate, deposit;
	 
	 // prompt user
	clog << "Welcome to Ronny's Interest Calculator\n" << endl;
	clog << "Enter the interest rate %: "; cin >> rate;
	clog << "Years of investment: "; cin >> years;
	clog << "Enter your yearly contribution: "; cin >> deposit;
	
	// convert interest rate
	rate *= 0.01;
	
	// Magic Value System Formula
	// system : v[n] = (1+r)v[n] + d[n]
	// solution : v[n] = (d/r)[ (1+r)^(n+1) - 1]
	value = pow((1 + rate), (years + 1)) - 1;
	value = value * (deposit/rate);
	
	// print savings
	double savings = value;
	double contribution = (years * deposit) + deposit;
	cout << "\n" << endl; // buffer
	cout << "Total Investment Value : " << savings << endl;
	cout << "Total Contributed : " << contribution << endl;
	cout << "Total Interest Earnings : " << savings - contribution << endl; 
	
 }