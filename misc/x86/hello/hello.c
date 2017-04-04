#include <stdio.h>

int readInteger(const char * msg);

int main(){
	int x = readInteger("Enter a number: ");
	int y = readInteger("Multiply by: ");

	int c = 0;
	int a = x, b = y;
	while(b != 0){
		c = c + a;
		b = b - 1;
	}
	printf("The product is: %d\n", c);
}

int readInteger(const char * msg){
	int value = 0;
	printf("%s", msg);
	while(scanf("%d", &value) != 1){
		printf("Error, could not read input number!\n");
		printf("%s", msg);
		while(getchar() != '\n');
	};
	return value;
}
