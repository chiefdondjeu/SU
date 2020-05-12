lab2Driver: main.o
	g++ -o lab2Driver main.o

main.o:	main.cpp
	g++ -c main.cpp

all: lab2Driver run

run:
	./lab2Driver

.PHONY: all run

memcheck:
	valgrind --leak-check=yes ./lab2Driver

clean:
	rm *.o lab2Driver