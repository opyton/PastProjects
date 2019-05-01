compile = g++ -Wall -std=c++14 -g -O0 -pedantic-errors

all: firstline output input

clean: 
	rm -f firstline

firstline: firstline.cpp
	$(compile) -o firstline firstline.cpp
output: output.cpp
	$(compile) -o output output.cpp
input: input.cpp
	$(compile) -o input input.cpp
