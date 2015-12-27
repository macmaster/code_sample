#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

double PrintSavings(int years, double lump_sum, double interest_rate, double total = 0);
int CriticalYear(double interest_rate, double gain = 1, double cvalue = 0);

int main (){
	double lump_sum;
	double savings;
	double interest_rate;
	int years;

	// prompt user
	clog << "Welcome to Ronny's Interest Calculator" << endl << endl;
	clog << "Enter the interest rate %: "; cin >> interest_rate;
	clog << "Enter your yearly contribution: "; cin >> lump_sum;
	clog << "Years of investment: "; cin >> years;
	
	//convert interest rate
	interest_rate *= 0.01;
	interest_rate += 1;
	//calc savings
	savings = PrintSavings(years, lump_sum, interest_rate);

	cout << "\n\n" << "Total Savings : " << savings << endl;
	cout << "Total Contributed : " << (years+1) * lump_sum << endl;
	cout << "Total Interest Earnings : " << savings - (years+1) * lump_sum << endl;
	
	// calc critical year
	cout << "Special Critical Year at " << (interest_rate-1)*100 << "% interest: " << CriticalYear(interest_rate, log(interest_rate)) << endl;
	getchar(); getchar();
}

double PrintSavings(int years, double lump_sum, double interest_rate, double total){
	static int year_count = 0;
	
	total *= interest_rate;
	total += lump_sum;
	cout << "By Year : " << year_count++ << ", Totals Savings : " << total << endl;
	
	if(years == 0)
		return total;
	else{
		return PrintSavings(years - 1, lump_sum, interest_rate, total);
	}
}

// CriticalYear is the year in which:
// the dS/dt overtakes the yearly contribution
int CriticalYear(double interest_rate, double gain, double cvalue){
	static int year_count = 0;
	
	cvalue *= interest_rate;
	cvalue += gain;
	if(cvalue >= 1)
		return year_count;
	else{
		year_count++;
		return CriticalYear(interest_rate, gain, cvalue);
	}
}
	