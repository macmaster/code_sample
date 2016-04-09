/**********bday.c****************************************
 * Converts your message into hexadecimal
 *	warning: can overflow if name size exceeds MAX_LEN
 * Author: Ronny Macmaster
 * Date: 4/8/2016
 *******************************************************/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

void print_hexmsg(short int *msg, int n);
short int *get_hexmsg(char *msg, int n);
 
int main(int argc, char *argv[]){
	
	/* user's msg*/
	int n  = 0;
	int *hexmsg;
	char *msg = (char *)malloc(sizeof(char) * MAX_LEN); 
	
	
	/* parse msg */
	if(argc < 2){
		printf("enter your msg: ");
		scanf("%s", msg);
	}
	else{
		strcpy(msg, argv[1]);
	}
	
	/* print msg */
	n = strlen(msg);
	printf("your message: %s\n", msg);
	hexmsg = get_hexmsg(msg, n);
	print_hexmsg(hexmsg, n);
	
	free(msg);
	free(hexmsg);
	
}

short int *get_hexname(char *name, int n){
	
	/* hex name */
	short int *xname = (short int *)malloc(sizeof(short int) * n);
	int i; 
	
	/* fill hex array */
	for(i = 0; i < n; i++){
		xname[i] = (int)name[i];
	}
	
	return xname;
	
}

void print_hexname(short int *name, int n){
	/* stream vars */
	int i = 0, hex;
	
	/* stream hex characters */
	for(i = 0; i < n; i++){
		/* hex seperator */
		if((i % 2) == 0){
			putchar('\n');
			putchar('x');
		}
		
		/* print hex value*/
		hex = *(name + i);
		printf("%x", hex);
	}
	putchar('\n');
	
}