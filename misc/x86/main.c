#include <stdio.h>

int readInteger(const char * msg);

int main(int argc, char **argv){
	
	int x = readInteger("Enter a number: ");
	int y = fib(x);
	
	printf("fib(%d): %d\n", x, y);
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
