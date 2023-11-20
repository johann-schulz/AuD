cc = gcc -Wall
OBJ = main.o datetime.o tools.o menu.o calendar.o database.o

main: $(OBJ)
	$(cc) -o $@ $^ -lm

main.o: main.c datetime.h datastructure.h tools.h menu.h calendar.h database.h
	$(cc) -c $<

datetime.o: datetime.c datetime.h datastructure.h tools.h menu.h calendar.h database.h
	$(cc) -c $<

tools.o: tools.c tools.h datetime.h datastructure.h menu.h calendar.h database.h
	$(cc) -c $<

menu.o: menu.c tools.h tools.h datetime.h datastructure.h  calendar.h database.h
	$(cc) -c $<

calendar.o: calendar.c tools.h tools.h datetime.h datastructure.h menu.h database.h
	$(cc) -c $<

database.o: database.c tools.h tools.h datetime.h datastructure.h menu.h calendar.h
	$(cc) -c $<

clean:
	rm -f main.o main datetime.o tools.o menu.o calendar.o database.o

run:
	./main

all: clean main run
