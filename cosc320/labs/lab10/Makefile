lab10Driver: graph.o main.o
	g++ -o lab10Driver graph.o main.o

graph.o: graph.h graph.cpp
	g++ -c graph.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o lab10Driver