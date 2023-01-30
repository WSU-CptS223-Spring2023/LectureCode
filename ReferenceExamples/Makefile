examples2: parameterExamples.o testdata.o
	g++ parameterExamples.o testdata.o -o examples2

examples1: lvalueExamples.o testdata.o
	g++ lvalueExamples.o testdata.o -o examples1

testdata.o: testdata.cpp testdata.hpp
	g++ -c -g testdata.cpp 

clean:
	-rm *.o

debug: 
	gdb lvalue 

run1:
	@./examples1 

run2:
	@./examples2 