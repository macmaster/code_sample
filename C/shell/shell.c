#include <sys/types.h>
#include <stdio.h>

void parse(char *line, char **argv);
void execute(char **argv);

int main(){
    char line[1024], *argv[64];
    while(1){ // shell prompt
        printf("# ");
        gets(line);
        printf("\n");
        parse(line, argv);
        if(strcmp(argv[0], "exit") == 0){
            exit(0);
        }
        execute(argv);
    }
}

void parse(char *line, char **argv){
}

void execute(char **argv){
}
