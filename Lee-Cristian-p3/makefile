compile = g++ -Wall -std=c++14 -g -O0 -pedantic-errors

all: cat true false

clean:
	rm cat true false

cat: cat.cpp
	$(compile) -o cat cat.cpp
true: true.cpp
	$(compile) -o true true.cpp
false: false.cpp
	$(compile) -o false false.cpp
