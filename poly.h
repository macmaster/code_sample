typedef struct Node {
	double coeff;
	int degree;
	Node* next; 
} Node;

// function where the interactive menu should be implemented
void runProgram();
int max(int , int );

class Poly {
private:
	// add private members as needed
	Node* poly_ptr;
	int poly_degree;
public:
	Poly();
	Poly(char* str);
	~Poly();
	Poly* add(Poly& otherPoly);
	Poly* multiply(Poly& otherPoly);
	double eval(int x);
	void print();
	bool equals(Poly& otherPoly);
	// add public members if needed
	void clean();
};