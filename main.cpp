/*
* This file is provided for you to run and test the program.
* You may add your own tests here to debug and verify your program,
* but this file will NOT be considered by the grader
*/

#include <iostream>
#include "poly.h"
#include <cstdio>

#define TEST_EVAL

using namespace std;

// very simple test
#ifdef DEBUG
void test1() {
	
	Poly p1((char*)"3x^2 + 2x + 1");
	Poly p2((char*)"1x + 2");
	Poly *p3 = p1.multiply(p2);
	Poly *p4 = p1.add(p2);

	bool errors = false;
	if (p3->eval(0) != 2) {
		cout << "test1 failed multiplying\n";
		errors = true;
	}
	if (p4->eval(0) != 3) {
		cout << "test1 failed adding\n";
		errors = true;
	}

	if (!errors) {
		cout << "test1 passed\n";
	}
}
#endif
int main() {
	//test Constructor, Destructor, print, clear
	#ifdef TEST_POLY
	Poly p1((char*)"-1234567890.9x^2 - 1234567890.9x - 1234567890.9");
	p1.print();putchar('\n');
	Poly p2((char*)"-124330");
	p2.print();putchar('\n');
	Poly p3((char*)"-666600x");
	p3.print();putchar('\n');
	Poly p4((char*)"-666600x - 0000099.4");
	p4.print();putchar('\n');
	#endif
	
	#ifdef TEST_EVAL
	printf("Polynomial evaluated: ");
	int x = 3;
	Poly p1((char*)"-20x^2+1x+60");
	p1.print();putchar('\n');
	for(int i = 0; i < 10; i++)
	printf("When x = %d, f(x) = %lf\n", x, p1.eval(x));
	#endif
	//test1();
	//runProgram();
}
