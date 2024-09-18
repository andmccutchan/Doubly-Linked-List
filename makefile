mytests: list myTests.cpp DoublyLinkedList.hpp DoublyLinkedList.cpp
	g++ -c myTests.cpp -o myTests.o
	g++ -o myTests doublylinkedlist.o myTests.o
	./myTests

list: DoublyLinkedList.hpp DoublyLinkedList.cpp
	g++ -c DoublyLinkedList.cpp -o doublylinkedlist.o

