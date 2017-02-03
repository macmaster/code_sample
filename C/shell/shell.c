#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void parse(char *line, char **argv);
void execute(char **argv);

int main(){
	int nbytes = 1024; 
	char line[nbytes], *argv[64];
	while(1){
		printf("# ");
		fgets(line, nbytes, stdin);
		parse(line, argv);

		if(strcmp(argv[0], "exit") == 0){
			exit(0);
		} else{
			execute(argv);
		}
	}
}

int whitespace(char c){
	if(c == ' ' || c == '\t' || c == '\n'){
		return 1;
	} else{
		return 0;
	}
}

void parse(char *line, char **argv){
	char c = *line;
	while(c != '\0' && c != '\n'){
		// remove whitespace
		while(whitespace(c)){
			*line++ = '\0';
			c = *line;
		} *argv++ = line;

		// find token end
		while(c != '\0' && !whitespace(c)){
			line++;
			c = *line;
		} 	
		*argv = '\0';
	} *line = '\0'; 
}

void execute(char **argv){
	pid_t pid;
	int status;

	// fork a child process
	if((pid = fork()) < 0){
		printf("*** ERROR: forking child process failed!\n");
		exit(1);
	} else if(pid == 0){
		// child execute program
		if(execvp(argv[0], argv) < 0){
			printf("*** ERROR: executing %s failed!\n", argv[0]);
			exit(1);
		}
	} else{
		while(wait(&status) != pid){
			// parent shell wait for exec to finish
		}
	}
}

