prog: main.o state.o
	g++ main.o state.o -o umap

main.o: main.cpp state.h
	g++ -c -g main.cpp 

state.o: state.cpp state.h
	g++ -c -g state.cpp 

clean:
	-rm *.o

debug: 
	gdb umap 

run:
	@./umap 