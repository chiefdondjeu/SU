spellcheck: dictionary.o timer.o main.o 
	g++ -o spellcheck dictionary.o timer.o main.o

dictionary.o: dictionary.h dictionary.cpp list.h
	g++ -c dictionary.cpp

timer.o: timer.h timer.cpp
	g++ -c timer.cpp

main.o: main.cpp
	g++ -c main.cpp

memcheck:
	valgrind ./spellcheck

clean:
	rm *.o spellcheck

# because I am lazy :)
vim:
	vim dictionary.h dictionary.cpp main.cpp 
