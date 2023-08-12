prog: algorithms.o CLI.o command.o demo.o maze2Dgenerator.o maze2D.o mazeGame.o searchable.o main.o
	g++ algorithms.o CLI.o command.o demo.o maze2Dgenerator.o maze2D.o mazeGame.o searchable.o main.o -o prog
	./prog
algorithms.o:
	g++ -c algorithms.cpp
CLI.o:
	g++ -c CLI.cpp
command.o:
	g++ -c command.cpp
demo.o:
	g++ -c demo.cpp
maze2D.o:
	g++ -c maze2D.cpp
maze2Dgenerator.o:
	g++ -c maze2Dgenerator.cpp
mazeGame.o:
	g++ -c mazeGame.cpp
searchable.o:
	g++ -c searchable.cpp
main.o:
	g++ -c main.cpp

clean:
	del *.o;