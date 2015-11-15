/*
* This file is provided for you to run and test the program.
* You may add your own tests here to debug and verify your program,
* but this file will NOT be considered by the grader
*/

#include <iostream>
#include "poly.h"
using namespace std;

// very simple test
void test1() {
	Poly p1("3x^2 + 2x + 1");
	Poly p2("1x + 2");
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

int main() {
	test1();
	//runProgram();
}
