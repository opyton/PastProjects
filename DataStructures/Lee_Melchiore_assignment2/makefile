-Wall -std=c++14 -g -O0 -pedantic-errors

main: SortedLinkedList.h ItemType.h ListNode.h main.o ItemType.o SortedLinkedList.o
	g++ -g -o main main.o ItemType.o SortedLinkedList.o
ItemType.o: ItemType.h ItemType.cpp
	g++ -c ItemType.cpp
SortedLinkedList.o: SortedLinkedList.h ItemType.h ListNode.h ItemType.o SortedLinkedList.cpp
	g++ -c SortedLinkedList.cpp
main.o: SortedLinkedList.h ItemType.h main.cpp
	g++ -c main.cpp
clean:
	/bin/rm *.o main
