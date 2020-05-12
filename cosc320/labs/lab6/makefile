lab6Driver: main.o
	g++ -std=c++11 -o lab6Driver main.o

main.o: main.cpp heapQ.h heapQ.cpp quicksort.h quicksort.cpp mergesort.h mergesort.cpp heapsort.h heapsort.cpp
	g++ -std=c++11 -c main.cpp

run:
	./lab6Driver

all: lab6Driver run

.PHONY: all run

memcheck:
	valgrind --leak-check=yes ./lab6Driver

clean:
	rm *.o lab6Driver