CC = g++
CFLAGS = -g -Wall -std=c++11
SRC = main.cpp
BACKUP = $(SRC:.cpp=.cpp~)
OBJ = $(SRC:.cpp=.o)
MAIN = main
#TEST = asm/simpleTests.asm obj/output.obj
TEST = 

all: $(MAIN)
	@echo compiled the program...

$(MAIN): $(OBJ)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJ)

test: $(MAIN)
	./$(MAIN) $(TEST) 

format: 
	indent $(SRC) -nbad -bap -nbc -bbo -hnl -br -brs -brf -c33 -cd33 -ncdb -ce -ci4 \
	-cli1 -d0 -di1 -nfc1 -i8 -ip0 -l120 -lp -npcs -nprs -npsl -sai \
	-saf -saw -ncs -nsc -sob -nfca -cp33 -ss -ts8 -il1
	$(RM) $(BACKUP)

clean:
	$(RM) $(MAIN) *.o



