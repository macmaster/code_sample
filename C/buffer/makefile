# makefile for buffer scripts
# stack overflow just got easier

exec = shell print root overflow

shell: shell.c
	gcc -o shell shell.c

print: print.s
	as -o print.o print.s
	ld -o print print.o

root: root.s
	as -o root.o root.s
	ld -o root root.o

clean:
	rm ${exec} *.o


