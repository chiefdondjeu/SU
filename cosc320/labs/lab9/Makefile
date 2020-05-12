lab9Driver: RBtree.o timer.o main.o
	g++ -o lab9Driver RBtree.o timer.o main.o

RBtree.o: RBtree.h RBtree.cpp
	g++ -c RBtree.cpp

timer.o: timer.h timer.cpp
	g++ -c timer.cpp

main.o: main.cpp
	g++ -c main.cpp

memcheck:
	valgrind ./lab9Driver

clean:
	rm *.o lab9Driver

vim:
	vim RBtree.h RBtree.cpp main.cpp 
