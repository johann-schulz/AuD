cc = gcc
CFLAGS = -Wall -lm
OBJ = main.o datetime.o tools.o menu.o calendar.o database.o

main: $(OBJ)
	$(cc) -o $@ $^ $(CFLAGS)

%.o: %.c datetime.h datastructure.h tools.h menu.h calendar.h database.h
	$(cc) -c $< $(CFLAGS)

clean:
	rm -f main $(OBJ)

run: main
	./main

all: clean run
