#endgoal: dependencies
#	action
#
prog.exe: bar.o foo.o prog.o
	g++ -o prog.exe bar.o foo.o prog.o

bar.o: bar.cpp bar.h
	g++ -c bar.cpp

foo.o: foo.cpp foo.h
	g++ -c foo.cpp

prog.o: prog.cpp
	g++ -c prog.cpp

clean:
	rm *.o