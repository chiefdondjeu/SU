lab12Driver: graph.o main.o
	g++ -o lab12Driver graph.o main.o -std=c++11

graph.o: graph.h graph.cpp
	g++ -c -w graph.cpp -std=c++11

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o lab12Driver