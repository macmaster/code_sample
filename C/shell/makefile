CC = gcc
CFLAGS = -g -Wall
SRC = shell.c
OBJ = $(SRC:.c=.o)
MAIN = rshell

all: $(MAIN)
	@echo compiled ronny shell...

$(MAIN): $(OBJ)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJ)

clean:
	$(RM) $(MAIN) *.o



