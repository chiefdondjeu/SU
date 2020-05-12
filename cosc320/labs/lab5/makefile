lab5Driver: main.o
	g++ -o lab5Driver main.o

main.o: main.cpp prioQ.h prioQ.cpp
	g++ -c main.cpp

run:
	./lab5Driver

all: lab5Driver run

.PHONY: all run

memcheck:
	valgrind --leak-check=yes ./lab5Driver

clean:
	rm *.o lab5Driver