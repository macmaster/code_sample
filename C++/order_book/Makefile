# Pricer makefile
# Author : Ronny Macmaster
# Date : 2/1/2016


CFLAGS = -I inc -c 

all: pricer

pricer: bin/pricer.o bin/Order.o bin/Util.o
	g++ -o pricer $^
	
bin/pricer.o: src/pricer.cpp
	g++ $(CFLAGS) $< -o bin/pricer.o
	
bin/Order.o: src/Order.cpp
	g++ $(CFLAGS) $< -o bin/Order.o

bin/Util.o: src/Util.cpp
	g++ $(CFLAGS) $< -o bin/Util.o 
	
clean: 
	rm pricer



	

