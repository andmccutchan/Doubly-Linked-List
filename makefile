mytests: list mytests.cpp DoublyLinkedList.hpp DoublyLinkedList.cpp
	g++ -c mytests.cpp -o mytests.o
	g++ -o mytests doublylinkedlist.o mytests.o
	./mytests

list: DoublyLinkedList.hpp DoublyLinkedList.cpp
	g++ -c DoublyLinkedList.cpp -o doublylinkedlist.o

