#include "poly.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>


// Main function of your program - called by main

/*
Enter the file that you would like to work with: ptest1.txt
The polynomials available for operation are:
1. 4.0x^5 + -2.0x^3 + 2.0x + 3.0
2. 8.0x^4 + 4.0x^3 + -3.0x + 9.0
What operation would you like to perform?
1. ADD polynomials
2. MULTIPLY polynomials
3. EVALUATE polynomial

Enter choice #: 1
Enter the two polynomials that you would like to work with: 1,2
The symbolic sum of the 2 polynomials is:
4.0x^5 + 8.0x^4 + 2.0x^3 + -1.0x + 12.0
Do you want to perform additional operations on the existing file (Y/N)? Y
What operation would you like to perform?
1. ADD polynomials
2. MULTIPLY polynomials
3. EVALUATE polynomial

Do you want to perform additional operations on the existing file (Y/N)? N
Do you want to work with another file (Y/N)? Y

*/
	
void runProgram() {
	using namespace std;
	char user_input[100];
	
	
	//prompt file
	cout << "Enter the file that you would like to work with: ";
	cin >> user_input;
	cout << user_input;



	// repeatedly prompt the user and process the selected

	// operation until the user selects the quit option. 

}

Poly::Poly(char* str) {

	char *temp_buffer = (char *)malloc(sizeof(char) * strlen(str));
	char *poly_buffer = (char *)malloc(sizeof(char) * strlen(str));
	bool found_degree = false;

	//removing whitespace / set poly degree
	poly_degree = 0;
	for (int i = 0; !str; str++) {
		if (*str != ' ') {
			poly_buffer[i++] = *str;
		}
		if ((*str == 'x') && (!found_degree)) {
			if (*(str + 1) == '^') {
				for (int j = 2; ((*(str + j) != '-') && (*(str + j) != '+')); j++) {
					poly_degree *= 10;
					poly_degree += (*(str + j)-'0'); // not atoi(). 1 char @ a time.
					
				}
			}
		}
			else {
				poly_degree = 1;
				found_degree = true;
			}
	}

	double *coeff_buffer = (double *)malloc(sizeof(int) * (poly_degree + 1));
	int *pow_buffer = (int *)malloc(sizeof(int) * (poly_degree + 1));
	char *cp;
	int count = 0;

	//Parsing for Cofficient.
	cp = poly_buffer;
	while (*cp != '\0') {
		int temp_index = 0;
		while ((*cp != '\0') && (*cp != 'x')) {
			temp_buffer[temp_index++] = *cp++;
		}
		coeff_buffer[count++] = strtod(temp_buffer, NULL);
		while ((*cp != '\0') && (*cp != '+') && (*cp != '-'))
			cp++;
	}

	//Parsing for Power.
	cp = poly_buffer; count = 0;
	while (*cp != '\0') {
		int temp_index = 0;
		while ((*cp != '\0') && (*cp != 'x'))
			cp++;
		if (*cp == '\0')
			pow_buffer[count++] = 0;
		else if ((*cp == 'x') && (*(cp + 1) != '^'))
			pow_buffer[count++] = 0;
		else {
			while ((*cp != '\0') && (*cp != '+') && (*cp != '-')) {
				temp_buffer[temp_index++] = *cp++;//dangerous??
			}
			pow_buffer[count++] = (int) strtod(temp_buffer, NULL);
		}
	}

	//make poly nodes
	Node *prev_node, *current_node, *head_node;

	head_node = poly_ptr = new Node;
	head_node->coeff = coeff_buffer[0];
	head_node->degree = pow_buffer[0];
	prev_node = head_node;
	for (int i = 1; i < count; i++) {
		current_node = new Node;
		current_node->coeff = coeff_buffer[i];
		current_node->degree = pow_buffer[i];
		prev_node->next = current_node;
	}

	//clean for zero	
	this->clean();
	//free buffers
	free(temp_buffer);
	free(poly_buffer);
	free(coeff_buffer);
	free(pow_buffer);

}

Poly::~Poly() {
	//free not only poly_ptr, free the nodes
	Node *current_node = this->poly_ptr, *temp_node;
	while (current_node) {
		temp_node = current_node;
		current_node = current_node->next;
		free(temp_node);
	}
}

Poly* Poly::add(Poly& otherPoly) {

	Poly *new_poly;
	Node *poly1, *poly2, *poly3;
	Node *head_node, *current_node, *prev_node;

	//init new poly
	new_poly = (Poly*)malloc(sizeof(Poly));
	head_node = new_poly->poly_ptr = new Node;
	new_poly->poly_degree = this->poly_degree > otherPoly.poly_degree ? this->poly_degree : otherPoly.poly_degree;
	head_node->degree = new_poly->poly_degree;
	head_node->coeff = 0;
	prev_node = head_node;

	for (int i = new_poly->poly_degree - 1; i >= 0; i--) {
		current_node = new Node;
		current_node->coeff = 0;
		current_node->degree = i;
		prev_node->next = current_node;
	}
	current_node->next = NULL;

	poly1 = this->poly_ptr;
	poly2 = otherPoly.poly_ptr;
	poly3 = head_node;

	while (poly3) {
		if ((poly1 != NULL) && (poly1->degree == poly3->degree)) {
			poly3->coeff += poly1->coeff;
			poly1 = poly1->next;
		}
		if ((poly2 != NULL) && (poly2->degree == poly3->degree)) {
			poly3->coeff += poly2->coeff;
			poly2 = poly2->next;
		}
		poly3 = poly3->next;
	}
	//clean the polynomials.
	new_poly->clean();
	return new_poly;
}

Poly* Poly::multiply(Poly& otherPoly) {

	int total_degree = this->poly_degree + otherPoly.poly_degree;
	int current_degree;
	double prod_coeff;
	Node *current_node, *prev_node, *func1_node, *func2_node, *head_node;
	Poly* new_poly = (Poly *)malloc(sizeof(Poly));

	current_node = (Node*)malloc(sizeof(Node));
	head_node = current_node;
	current_node->coeff = 0;
	current_node->degree = total_degree;
	new_poly->poly_ptr = head_node;
	new_poly->poly_degree = total_degree;

	for (int i = total_degree - 1; i >= 0; i--) {
		prev_node = current_node;
		current_node = (Node*)malloc(sizeof(Node));
		current_node->coeff = 0;
		current_node->degree = i;
		prev_node->next = current_node;
	}

	current_node->next = NULL; //marks end of linked list
	func1_node = this->poly_ptr;
	func2_node = otherPoly.poly_ptr;
	while (func1_node) {
		while (func2_node) {
			current_node = head_node; //current_node = new_poly.poly_ptr;
			current_degree = func1_node->degree + func2_node->degree;
			prod_coeff = (func1_node->coeff)*(func2_node->coeff);
			for (int i = total_degree - current_degree; i > 0; i++) {
				current_node = current_node->next;
			}
			current_node->coeff = current_node->coeff + prod_coeff;
		}
		func1_node = func1_node->next;
		func2_node = otherPoly.poly_ptr;
	}
	new_poly->clean();
	return new_poly;
}
double Poly::eval(int x) {

	Node *poly = this->poly_ptr;
	double sum = 0;

	while (poly) {
		sum += poly->coeff * pow(x, poly->degree);
		poly = poly->next;
	}
	return sum;
}

void Poly::print() {
	Node *current_node = this->poly_ptr;
	if (!current_node) {
		printf("0\n"); // 0 polynomial
		return;
	}
	//initial print
	if (current_node->degree == 0) {
		printf("%.1lf", current_node->coeff);
	}
	else if (current_node->degree == 1) {
		printf("%.1lfx", current_node->coeff);
	}
	else {
		printf("%.1lfx^%d", current_node->coeff, current_node->degree);
	}
	current_node = current_node->next;
	while (current_node) {
		printf(" + ");
		if (current_node->degree == 0) {
			printf("%.1lf", current_node->coeff);
		}
		else if (current_node->degree == 1) {
			printf("%.1lfx", current_node->coeff);
		}
		else {
			printf("%.1lfx^%d", current_node->coeff, current_node->degree);
		}
		current_node = current_node->next;
	}
}

bool Poly::equals(Poly& otherPoly) {
	Node *poly1, *poly2;

	poly1 = this->poly_ptr;
	poly2 = otherPoly.poly_ptr;

	while (poly1&&poly2) {//poly 1& 2 note  yet empty
		if ((poly1->coeff == poly2->coeff) && (poly1->degree == poly2->degree)) {
			poly1 = poly1->next;
			poly2 = poly2->next;
		}
		else
			return false;
	}
	if ((!poly1) && (!poly2))
		return true;
	else
		return false;
}

void Poly::clean() {
	Node *head_node, *current_node, *prev_node, *next_node;
	head_node = this->poly_ptr;
	current_node = head_node;
	while ((current_node) && (current_node->coeff == 0)) {
		prev_node = current_node;
		current_node = current_node->next;
		free(prev_node);
	}
	this->poly_ptr = current_node;
	this->poly_degree = current_node->degree;
	prev_node = this->poly_ptr;
	if (prev_node) {
		current_node = prev_node->next;
	}
	while ((prev_node) && (current_node)) {
		if (current_node->coeff == 0) {
			prev_node->next = current_node->next;
			free(current_node);
			current_node = prev_node->next;
		}
		else {
			prev_node = current_node;
			current_node = current_node->next;
		}
	}
}