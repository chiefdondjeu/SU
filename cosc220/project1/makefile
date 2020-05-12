proj1Driver: Center.o Shape.o Circle.o Rectangle.o Square.o main.o
	g++ -o proj1Driver Center.o Shape.o Circle.o Rectangle.o Square.o main.o

Center.o: Center.cpp Center.h
	g++ -c Center.cpp

Shape.o: Shape.cpp Shape.h Center.h
	g++ -c Shape.cpp

Circle.o: Circle.cpp Circle.h Shape.h
	g++ -c Circle.cpp

Rectangle.o: Rectangle.cpp Rectangle.h Shape.h
	g++ -c Rectangle.cpp

Square.o: Square.cpp Square.h Rectangle.h
	g++ -c Square.cpp

main.o: main.cpp Center.h Shape.h
	g++ -c main.cpp

run:
	./proj1Driver

clean:
	rm *.o proj1Driver