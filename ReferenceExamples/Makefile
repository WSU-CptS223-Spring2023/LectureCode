parameters: parameterExamples.o testdata.o
	g++ parameterExamples.o testdata.o -o param

lvalues: lvalueExamples.o testdata.o
	g++ lvalueExamples.o testdata.o -o lvalue

testdata.o: testdata.cpp testdata.hpp
	g++ -c -g testdata.cpp 

clean:
	-rm *.o

debug: 
	gdb lvalue 

runlvalue:
	@./lvalue 

runparam:
	@./param 