proj3Driver: studentClass.o proj3Driver.o 
	g++ -o proj3Driver studentClass.o proj3Driver.o

studentClass.o: studentClass.cpp studentClass.h
	g++ -c studentClass.cpp

proj3Driver.o: proj3Driver.cpp d_dnode.h d_dnodeBase.h
	g++ -c proj3Driver.cpp

all: proj3Driver run

run:
	./proj3Driver

.PHONY: all run

clean:
	rm *.o proj3Driver