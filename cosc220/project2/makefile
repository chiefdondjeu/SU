#
#makefile
#compile the files
#author Florent Dondjeu tschoufack
#created November 2, 2019
#current November 4, 2019
#
proj2Driver: timerAux.o main.o
	g++ -o proj2Driver timerAux.o main.o

timerAux.o: timerAux.cpp timerAux.h
	g++ -c timerAux.cpp

main.o: main.cpp mySorts.cpp mySorts.h
	g++ -c main.cpp

run:
	./proj2Driver

clean:
	rm *.o proj2Driver