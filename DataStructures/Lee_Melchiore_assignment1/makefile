-Wall -std=c++14 -g -O0 -pedantic-errors

main: Student.h Instructor.h main.o Student.o Instructor.o
	g++ -g -o main main.o Student.o Instructor.o
Student.o: Student.h Student.cpp
	g++ -c Student.cpp
Instructor.o: Instructor.h Student.h Student.o Student.cpp Instructor.cpp
	g++ -c Instructor.cpp
main.o: Instructor.h Student.h main.cpp
	g++ -c main.cpp
clean:
	/bin/rm *.o *~ main
