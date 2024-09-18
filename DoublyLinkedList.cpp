// DoublyLinkedList.cpp
// Andrew McCutchan, Jin Seok Youn, Beck Robins
// 09/13/2024
// Contains the main class method implementations.
//=========================================================

#include <iostream>
#include "DoublyLinkedList.hpp"
using namespace std;


//==============================================================
//createNewNode
//Helper function to create new node with data
//PARAMETERS: 
//- data : a new data of type T to prepend
//RETURN VALUE:
//- newnode, pointer to the newnode that had been made.
//==============================================================
template <class T>
        typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::createNewNode(const T &data)
{
	Node* newnode = new Node;
	newnode -> next = nullptr;
	newnode -> prev = nullptr;
	newnode -> data = data;
	return newnode;
}
//==============================================================
//default constructor
//Creates a new empty DoublyLinkedList object
//PARAMETERS: 
//- none
//RETURN VALUE: 
//- none
//==============================================================
template <class T>
        DoublyLinkedList<T>::DoublyLinkedList (void)
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

//==============================================================
//Copy constructor
//Creates a new DoublyLinkedList object by deep copying the data in 
//DoublyLinkedList that is given by the parameter.
//PARAMETERS: 
//- DoublyLinkedList object
//RETURN VALUE: 
//- none
//==============================================================
template <class T>
        DoublyLinkedList<T>::DoublyLinkedList (const DoublyLinkedList<T> &list)
{
	head = nullptr;
	tail = nullptr;
	size = 0;
	Node *ptr = list.head;
	//create the head
	if(ptr != nullptr){
		//create newnode and copy data
		Node *newnode = createNewNode(ptr -> data);
		head = newnode;
		ptr = ptr -> next;
		size++;
	}
	//Creating other nodes
	Node *track = head;
	while (ptr != nullptr){
		Node *newnode = createNewNode(ptr -> data);
		track -> next = newnode; //link the newnode
		ptr = ptr -> next;
		track = track -> next;
		tail = newnode; //update new tail
		size++;
	}
	
}

//==============================================================
//destructor
//PARAMETERS:
//- void
//RETURN VALUE:
//- none, free the memories of the DoublyLinkedList nodes.
//==============================================================
template <class T >
        DoublyLinkedList<T>::~DoublyLinkedList (void)
{
    Node *ptr = head;
    Node *deleting_node;
    while(ptr != nullptr){
        deleting_node = ptr;
        ptr = ptr -> next;
        delete deleting_node;
    }
}

//==============================================================
//prepend
//This method allows to add an data to the front of the list.
//PARAMETERS:
//- data : a new data of type T to prepend
//RETURN VALUE:
//- none, changes the list by adding a new data on the front.
//=========================================================
template <class T>
void DoublyLinkedList<T>::prepend ( const T &data )
{
	Node *newnode = createNewNode(data);
	//If the head is NULL
	if(head == nullptr){
		head = newnode;
		tail = newnode;
		size++;
	}else{
		Node *ptr = head; //get head
		//add newnode to the front
		ptr -> prev = newnode; 
		newnode -> next = ptr;
		head = newnode; //update head
		size++;
	}
}

//==============================================================
//append
//This method allows you to add an data to the end of the list.
//PARAMETERS:
//- data : a new data of type T to append
//RETURN VALUE:
//- none, changes the list by adding a new data on the end.
//==============================================================
template <class T>
void DoublyLinkedList<T>::append ( const T &data )
{
	Node *newnode = createNewNode(data);
	//If the head is NULL
	if(head == nullptr){
		head = newnode;
		tail = newnode;
		size++;
	}else{
		Node *ptr = tail; //get tail
		//add newnode to the end
		ptr -> next = newnode;
		newnode -> prev = ptr;
		tail = newnode; //update tail
		size++;
	}
}

//insert
//=========================================================
template <class T>
void DoublyLinkedList<T>::insert ( const T &data, int index )
{
    	if (index < 0 || index > size)
	{
		cout << "Index out of range" << endl;
        exit(0);
	}

	Node* newNode = createNewNode(data);
	if (index == 0)
	{
		newNode->next = head;
		head = newNode;
	}
	

	else {
		Node* ptr = head;
		for (int i = 0; i < index - 1; i++) {
			ptr = ptr->next;
		}
		
		newNode->next = ptr->next;
		newNode->prev = ptr->prev;
		ptr->next = newNode;
		size++;
	}
}

//
//=========================================================
template <class T>
void DoublyLinkedList<T>::remove ( int index )
{
    if (index < 0 || index >= size)
	{
		cout << "Index out of range" << endl;
        exit(0);
	}

	if (index == 0)
	{
		Node* temp = head;
		head = head->next;
		if (head != nullptr) {
			head->prev = nullptr;
		}
		delete temp;
	}
	
	else {
		Node* ptr = head;
		for (int i = 0; i < index - 1; i++) {
			ptr = ptr->next;
		}

		Node* temp = ptr->next;
		ptr->next = temp->next;

		// check to see if it is the last node
		if (temp->next != nullptr){ 
			temp->next->prev = ptr;
		}
		delete temp;
	}
}

//
//=========================================================
template <class T>
int DoublyLinkedList<T>::search ( const T &data ) const
{
    
}

//
//=========================================================
template <class T>
T & DoublyLinkedList<T>::operator[] ( int index )
{

}

//
//=========================================================
template <class T>
int DoublyLinkedList<T>::length ( void ) const
{

}

//
//=========================================================
template <class T>
bool DoublyLinkedList<T>::empty ( void ) const
{

}

//==============================================================
// operator=
// Assignment operator
// PARAMETERS:
// DoublyLinkedList object
// RETURN VALUE:
// new deep copied DoublyLinkedList object
// *this is returned
//==============================================================
template <class T>
DoublyLinkedList<T> DoublyLinkedList<T>::operator= (const DoublyLinkedList<T> &list){
	//free memory the existing nodes
	Node *ptr = head;
    Node *deleting_node;
    while(ptr != nullptr){
        deleting_node = ptr;
        ptr = ptr -> next;
        delete deleting_node;
    }
	size = 0;
	head = nullptr;
	ptr = list.head;
	//create the head
	if(ptr != nullptr){
		//create newnode and copy data
		Node *newnode = createNewNode(ptr -> data);
		head = newnode;
		ptr = ptr -> next;
		size++;
	}
	//Creating other nodes
	Node *track = head;
	while (ptr != nullptr){
		Node *newnode = createNewNode(ptr -> data);
		track -> next = newnode; //link the newnode
		ptr = ptr -> next;
		track = track -> next;
		tail = newnode; //update new tail
		size++;
	}
	
	return *this;
}
//=========================================================
//concat
//This method concatenates two existing lists to return a newly created list. 
//Neither the calling list nor the parameter list get modified.
//PARAMETERS:
//- DoublyLinkedList object
//RETURN VALUE:
//- new deep copied and concantenated DoublyLinkedList object.
//=========================================================
template <class T>
DoublyLinkedList<T> DoublyLinkedList<T>::concat  (const DoublyLinkedList<T> &list ) const
{
	DoublyLinkedList<T> newlist(*this);
	Node *ptr = list.head;
	while(ptr != nullptr){
		newlist.append(ptr -> data);
		ptr = ptr -> next;
	}
	return newlist;
}