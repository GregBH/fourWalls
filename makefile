CC = gcc
STD = -std=c99
LIB = -lSDL2 -lSDL2_image
OBJ = main

all: 
	$(CC) $(STD) *.h *.c $(LIB) -o $(OBJ)

clean:
	rm *.o
	