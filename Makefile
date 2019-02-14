p2: Project2.o
	g++ -g -std=c++11 -Wall Project2.o -o p2

Project2.o: Project2.cpp Chessboard.hpp
	g++ -g -std=c++11 -Wall -c Project2.cpp

clean: 
	rm *.o p2