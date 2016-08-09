#include <stdio.h>

void fn(int arg1, int arg2);

int main(){
	int a, b;
	a = 1; b = 2;
	fn(a, b);
}

void fn(int arg1, int arg2){
	int x, y;
	x = 3; y = 4;
	printf("we're in fn\n");
}


