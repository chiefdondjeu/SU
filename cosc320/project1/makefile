prog: driver iomodel

driver: matrix.o driver.o
	g++ -o driver matrix.o driver.o

matrix.o: matrix.h matrix.cpp
	g++ -c matrix.cpp

driver.o: driver.cpp heapQ.h heapQ.cpp
	g++ -c -std=c++11 driver.cpp

iomodel: matrix.o iomodel.o
	g++ -o iomodel matrix.o iomodel.o

iomodel.o: iomodel.cpp heapQ.h heapQ.cpp
	g++ -c iomodel.cpp

clean:
	rm *.o driver iomodel