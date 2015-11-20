#include "poly.h"
#include <iostream>
#include <fstream>
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
	int poly_count, poly_op;
	bool file_flag, quit_flag;


	/******************************************* File Menu ***********************************/
	quit_flag = false;
	while (!quit_flag) {
		//prompt file
		cout << "Enter the file that you would like to work with: ";
		cin >> user_input;

		//read file
		ifstream poly_file;
		poly_file.open(user_input);

		//optioinal: test poly_file.is_open();
		poly_file >> poly_count;
		poly_file.ignore(1); // ignore newline char

							 //create poly array
		Poly **poly_array = new Poly*[poly_count];
		for (int i = 0; i < poly_count; i++) {
			poly_file.getline(user_input, 100);
			//cout << "user input: " << user_input << endl;
			poly_array[i] = new Poly(user_input);
		}
		cout << "The polynomials available for operation are: " << endl;

		for (int i = 0; i < poly_count; i++) {
			cout << i + 1 << ". ";
			poly_array[i]->print();
			//cout << endl;
		}

		poly_file.close();


		/***************************** Operations Menu *****************************************/
		file_flag = true; // continue ops on same file
		while (file_flag) {
			cout << "What operation would you like to perform?" << endl;
			cout << "1. ADD polynomials" << endl;
			cout << "2. MULTIPLY polynomials" << endl;
			cout << "3. EVALUATE polynomial" << endl;

			cout << endl << "Enter choice #: ";
			cin >> poly_op;

			int input1, input2;
			Poly *temp_poly;
			//Should we check that inputs are valid?
			switch (poly_op) {
			case 1://add polys
				cout << "Enter the two polynomials that you would like to work with: ";
				cin >> input1; cin.ignore(1); cin >> input2; // ignore the comma
				if ((input1 > poly_count) || (input2 > poly_count) || (input1 < 1) || (input2 < 1)) //input check
					cerr << "Invalid polynomial choice!!" << endl;
				else {
					cout << "The symbolic sum of the 2 polynomials is: " << endl;
					temp_poly = (poly_array[--input1]->add(*poly_array[--input2]));
					temp_poly->print(); cout << endl;
					free(temp_poly);
					//cout << "poly1: "; poly_array[--input1]->print(); cout << endl;
					//cout << "poly2: "; poly_array[--input2]->print(); cout << endl;
				}
				break;
			case 2://mult polys
				cout << "Enter the two polynomials that you would like to work with: ";
				cin >> input1; cin.ignore(1); cin >> input2; // ignore the comma
				if ((input1 > poly_count) || (input2 > poly_count) || (input1 < 1) || (input2 < 1))
					cerr << "Invalid polynomial choice!!" << endl;
				else {
					cout << "The symbolic product of the 2 polynomials is: " << endl;
					temp_poly = (poly_array[--input1]->multiply(*poly_array[--input2]));
					temp_poly->print(); cout << endl;
					free(temp_poly);
					//cout << "poly1: "; poly_array[--input1]->print(); cout << endl;
					//cout << "poly2: "; poly_array[--input2]->print(); cout << endl;
				}
				break;
			case 3://eval poly
				cout << "Enter the polynomial that you would like to work with: "; cin >> input1;
				cout << "Enter the evaluation point (the value of x): "; cin >> input2;
				cout << "Value of that polynomial at " << (double)input2 << " is: " << poly_array[--input1]->eval(input2) << endl;
				break;
			default:
				cerr << "Invalid Polynomial Operation!" << endl;
			}

			//continue? check   (Ronny's Favorite Part of the program)
			char in_char;
			do {
				cout << "Do you want to perform additional operations on the existing file (Y/N)? "; cin >> in_char; cin.ignore(100, '\n');
				switch (in_char) {
				case 'n': case 'N':
					do {
						cout << "Do you want to work with another file (Y/N)? "; cin >> in_char; cin.ignore(100, '\n');
						switch (in_char) {
						case 'n': case 'N':
							quit_flag = true;
						case 'y': case 'Y':
							file_flag = false;
							break;
						default:
							cerr << "Please choose a Y or N!" << endl;
						}
					} while ((in_char != 'n') && (in_char != 'N') && (in_char != 'y') && (in_char != 'Y'));
				case 'y': case 'Y':
					break;
				default:
					cerr << "Please choose a Y or N!" << endl;
				}
			} while ((in_char != 'n') && (in_char != 'N') && (in_char != 'y') && (in_char != 'Y'));
		}
		// loop and delete memory pointed to by poly pointers before deleting array
		for (int i = 0; i < poly_count; i++) {
			delete poly_array[i];
		}
		delete[] poly_array;
	}
	cout << "Thank you for using this program!" << endl;
}

Poly::Poly(char* str) {
	int len = strlen(str) + 1;
	char *temp_buffer = (char *)malloc(sizeof(char) * len);
	char *poly_buffer = (char *)malloc(sizeof(char) * len);
	bool found_degree = false;

	//removing whitespace / set poly degree
	poly_degree = 0;
	int i;
	for (i = 0; *str; str++) {
		if (*str != ' ') {
			poly_buffer[i++] = *str;
		}
		if ((*str == 'x') && (!found_degree)) {
			if (*(str + 1) == '^') {
				poly_degree = atoi(str + 2);
				found_degree = true;
			}
			else {
				poly_degree = 1;
				found_degree = true;
			}
		}
	}
	poly_buffer[i] = '\0';
	double *coeff_buffer = (double *)malloc(sizeof(double) * (poly_degree + 1));
	int *pow_buffer = (int *)malloc(sizeof(int) * (poly_degree + 1));
	char *cp;
	int count = 0;
	int temp_index;
	//Parsing for Cofficient.
	cp = poly_buffer;
	while (*cp != NULL) {
		temp_index = 0;
		while ((*cp != NULL) && (*cp != 'x')) {
			temp_buffer[temp_index++] = *(cp);
			cp++;
		}
		temp_buffer[temp_index] = '\0';
		coeff_buffer[count++] = strtod(temp_buffer, NULL);
		while ((*cp != NULL) && (*cp != '+') && (*cp != '-'))
			cp++;
	}

	//Parsing for Power.
	cp = poly_buffer; 
	count = 0;
	while (*cp != NULL) {
		temp_index = 0;
		while ((*cp != NULL) && (*cp != 'x')) {
			cp++;
		}
		if (*cp == NULL) {
			pow_buffer[count++] = 0;
		}
		else if ((*cp == 'x') && (*(cp + 1) != '^')) {
			pow_buffer[count++] = 1;
			cp++;
		}
		else if ((*cp == 'x') && (*(cp + 1) == '^')) {
			cp = cp + 2;
			while ((*cp != NULL) && (*cp != '+') && (*cp != '-')) {
				temp_buffer[temp_index++] = *cp++;//dangerous??
			}
			temp_buffer[temp_index] = '\0';
			pow_buffer[count++] = (int) strtod(temp_buffer, NULL);
		}
	}

	//make poly nodes
	Node *prev_node, *current_node, *head_node;

	current_node = new Node;
	head_node = current_node;
	head_node->coeff = coeff_buffer[0];
	head_node->degree = pow_buffer[0];
	this->poly_ptr = head_node;
	this->poly_degree = head_node->degree;
	current_node = head_node;
	for (int i = 1; i < count; i++) {
		prev_node = current_node;
		current_node = new Node;
		current_node->coeff = coeff_buffer[i];
		current_node->degree = pow_buffer[i];
		prev_node->next = current_node;
	}

	current_node->next = NULL;
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
	new_poly = (Poly*) malloc(sizeof(Poly));
	current_node = head_node = new_poly->poly_ptr = new Node;
	new_poly->poly_degree = this->poly_degree > otherPoly.poly_degree ? this->poly_degree : otherPoly.poly_degree;
	head_node->degree = new_poly->poly_degree;
	head_node->coeff = 0;

	for (int i = new_poly->poly_degree - 1; i >= 0; i--) {
		prev_node = current_node;
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
			for (int i = total_degree - current_degree; i > 0; i--) {
				current_node = current_node->next;
			}
			current_node->coeff = current_node->coeff + prod_coeff;
			func2_node = func2_node->next;
		}
		func1_node = func1_node->next;
		func2_node = otherPoly.poly_ptr;
	}
	
	new_poly->clean();
	return new_poly;
}
double Poly::eval(double x) {

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
	printf("\n");
}

bool Poly::equals(Poly& otherPoly) {
	Node *poly1, *poly2;

	poly1 = this->poly_ptr;
	poly2 = otherPoly.poly_ptr;

	while ((poly1) && (poly2)) {//poly 1& 2 not yet empty
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

	Node *head_node, *current_node, *prev_node;
	head_node = this->poly_ptr;
	current_node = head_node;
	while ((current_node) && (current_node->coeff == 0)) {
		prev_node = current_node;
		current_node = current_node->next;
		free(prev_node);
		(this->poly_degree)--;
	}
	this->poly_ptr = current_node;
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