CFLAG = g++ -Wall -std=c++14 -g -O0 -pedantic-errors

Matrix.o: Matrix.h Matrix.cpp
	$(CFLAG) -o Matrix.o -c Matrix.cpp
p1: p1.cpp Matrix.h Matrix.cpp
	$(CFLAG) -o p1 p1.cpp Matrix.cpp
