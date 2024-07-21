CC = gcc
CFLAGS = -Wall -Wextra -g

all: game

game: main.o game.o utils.o
	$(CC) $(CFLAGS) -o game main.o game.o utils.o

main.o: main.c game.h utils.h
	$(CC) $(CFLAGS) -c main.c

game.o: game.c game.h utils.h
	$(CC) $(CFLAGS) -c game.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f *.o game