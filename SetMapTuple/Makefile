prog: setmap.o 
	g++ setmap.o  -o setmap

setmap.o: setmap.cpp 
	g++ -c -g -std=c++11 -Wall  setmap.cpp 


clean:
	-rm *.o

debug: 
	gdb setmap 

run:
	@./setmap 