prog: main.o TestBigFive.o BigFive.o 
	g++ main.o TestBigFive.o BigFive.o -o big5

main.o: main.cpp TestBigFive.h BigFive.h
	g++ -c -g -std=c++11 -Wall main.cpp

TestBigFive.o: TestBigFive.cpp TestBigFive.h
	g++ -c -g -std=c++11 -Wall TestBigFive.cpp

BigFive.o: BigFive.cpp BigFive.h
	g++ -c -g -std=c++11 -Wall BigFive.cpp 

clean:
	-rm *.o

debug: 
	gdb lvalue 

run:
	@./big5 