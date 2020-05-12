ab8Driver: binarytree.o timer.o main.o
	g++ -o lab8Driver binarytree.o timer.o  main.o

binarytree.o: binarytree.h binarytree.cpp
	g++ -c binarytree.cpp

timer.o: timer.h timer.cpp
	g++ -c timer.cpp

main.o: main.cpp
	g++ -c main.cpp

memcheck:
	valgrind --leak-check=full ./lab8Driver

clean:
	rm *.o lab8Driver
