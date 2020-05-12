lab4Driver: matrix.o main.o
	g++ -o lab4Driver matrix.o main.o

matrix.o: matrix.h matrix.cpp
	g++ -c matrix.cpp

main.o: main.cpp
	g++ -c main.cpp

memcheck:
	valgrind --leak-check=yes ./lab4Driver

run:
	./lab4Driver

all: lab4Driver run

.PHONY: all run

clean:
	rm *.o lab4Driver