cc = gcc -Wall
OBJ = main.o datetime.o tools.o menu.o calendar.o

main: $(OBJ)
	$(cc) -o $@ $^ -lm

main.o: main.c datetime.h datastructure.h tools.h menu.h calendar.h
	$(cc) -c $<

datetime.o: datetime.c datetime.h datastructure.h tools.h menu.h calendar.h
	$(cc) -c $<

tools.o: tools.c tools.h datetime.h datastructure.h menu.h calendar.h
	$(cc) -c $<

menu.o: menu.c tools.h tools.h datetime.h datastructure.h  calendar.h
	$(cc) -c $<

calendar.o: calendar.c tools.h tools.h datetime.h datastructure.h menu.h
	$(cc) -c $<

clean:
	rm -f main.o main datetime.o tools.o menu.o calendar.o

run:
	./main

all: clean main run
