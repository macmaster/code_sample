/** overflow.c **
 * illustrate buffer overflow
 * 
 * By: Ronny Macmaster
 * Date: 7/25/16
 **********************************/

 #include <stdio.h>
 #include <string.h>

 void fn(char *str);

 int main(int argc, char *argv[]) {
	fn(argv[1]);
	printf("overflow finished.\n");
 }

 void fn(char *str){
	char buff[10];
	strcpy(buff, str);
	printf("%s was copied!\n", str);
 }
