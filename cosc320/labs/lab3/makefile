lab3Driver: main.o
	g++ -o lab3Driver main.o

#included heapsort.h & heapsort.cpp because they are templated
main.o: main.cpp heapsort.h heapsort.cpp
	g++ -c main.cpp

all: lab3Driver run

run:
	./lab3Driver

.PHONY: all run

memcheck:
	valgrind --leak-check=yes ./lab3Driver

clean:
	rm *.o lab3Driver