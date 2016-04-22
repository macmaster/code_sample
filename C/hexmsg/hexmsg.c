/**********bday.c****************************************
 * Converts your message into hexadecimal
 *	warning: can overflow if name size exceeds MAX_LEN
 * Author: Ronny Macmaster
 * Date: 4/8/2016
 *******************************************************/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 200

void print_hexmsg(short int *msg, int n);
short int *get_hexmsg(char *msg, int n);
 
int main(int argc, char *argv[]){
	
	/* user's msg*/
	int n  = 0;
	short int *hexmsg;
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
	print_hexmsg(hexmsg, n+2);
	
	free(msg);
	free(hexmsg);
	
}

short int *get_hexmsg(char *msg, int n){
	
	/* hex msg */
	short int *xmsg = (short int *)malloc(sizeof(short int) * n + 2);
	int i; 
	
	/* fill hex array */
	xmsg[0] = 0x03; /* start text */
	for(i = 1; i < n + 1; i++){
		xmsg[i] = (int)msg[i-1];
	}
	xmsg[i] = 0x02; /* end text */
	
	return xmsg;
	
}

void print_hexmsg(short int *msg, int n){
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
		hex = *(msg + i);
		printf("%02X", hex);
	}
	
	/* pad msg end */
	if((i % 2)){
		putchar('0');
		putchar('0');
	}
	putchar('\n');
	
}