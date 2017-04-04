all: main

fib.o: fib.s
	gcc -g -o fib.o -c fib.s

main: main.c fib.o
	gcc -g -o main main.s fib.o

main.s: main.c
	gcc -g -S main.c
