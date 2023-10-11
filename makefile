cc = gcc -Wall
OBJ = main.o datetime.o tools.o

main: $(OBJ)
	$(cc) -o $@ $^ -lm

main.o: main.c datetime.h datastructure.h tools.h
	$(cc) -c $<

datetime.o: datetime.c datetime.h datastructure.h tools.h
	$(cc) -c $<

tools.o: tools.c tools.h datetime.h datastructure.h
	$(cc) -c $<

clean:
	rm -f main.o main datetime.o tools.o

run:
	./main

all: clean main run
