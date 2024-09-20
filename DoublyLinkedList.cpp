// DoublyLinkedList.cpp
// Andrew McCutchan, Jin Seok Youn, Beck Robins
// 09/20/2024
// Contains the main DoublyLinkedList class method implementations.
//=========================================================

#include <iostream>
#include "DoublyLinkedList.hpp"
using namespace std;

//==============================================================
//createNewNode
//Helper function to create new node with data
//PARAMETERS: 
//- data : a new data of type T for new node.
//RETURN VALUE:
//- newnode: Node*, pointer to the newnode that had been made.
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
		tail = newnode;
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
	if(head == nullptr){  //prepend to an empty list
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
	if(head == nullptr){  //appends to an empty list
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

//=========================================================
//insert
//This method allows to you add an item at the location specified by index
//PARAMETERS:
//- data: new data of type T that is inserted
//- index, int: the index where the data is inserted
//RETURN VALUE:
//- none, list is changed by inserting a new variable
//=========================================================
template <class T>
		void DoublyLinkedList<T>::insert ( const T &data, int index )
{
    if (index < 0 || index > length()) {
        throw out_of_range("Index out of range");
    }
    
    if (index == 0) {
        prepend(data);
        return;
    }

    if (index == length()) {
        append(data);
        return;
    }

    Node *ptr = head;
    for (int i = 0; i < index - 1; i++) {
        ptr = ptr->next;
    }

    Node *newnode = createNewNode(data);

    newnode->next = ptr->next;  //adjusts the pointers of newNode to match to the next and previous pounter
    newnode->prev = ptr;
    ptr->next->prev = newnode;  //adjusts the nodes before and after the new node to make their pointers point to the new node
    ptr->next = newnode;
	size++;
	
}

//=========================================================
//remove
//This method removes the item at the position specified by index
//PARAMETERS:
//- index, int: index of data to be removed
//RETURN VALUE:
//- none: DoublyLinkedList has variable removed
//=========================================================
template <class T>
		void DoublyLinkedList<T>::remove ( int index )
{
    if (index < 0 || index >= length()) {
        throw out_of_range("Index out of range");
    }
    Node *ptr;
    if (index == 0) { //check if given index is the first index of the list
		ptr = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
    }
	else if (index == length() - 1) { //check if index is the last index of the list
		ptr = tail;
		tail = tail->prev;
		if (tail != nullptr) {
			tail->next = nullptr;
		} else {
			head = nullptr;
		}
	}
	else {
		ptr = head;  
		for (int i = 0; i < index; i++) {  // every other instance
			ptr = ptr->next;
		}
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
	}
    delete ptr;
	size--;
}

//=========================================================
//search
//This method finds the index of the first instance of data in the DoublyLinkedList
//PARAMETERS:
//- data: the data of type T to search for in the DoublyLinkedList
//RETURN VALUE:
//- integer of index containing node, -1 if not found
//=========================================================
template <class T>
		int DoublyLinkedList<T>::search ( const T &data ) const
{
    Node *ptr = head;
    int index = 0;

    while (ptr != nullptr) {
        if (ptr->data == data) {  //linearlly searches the list for the first instance of the given data
            return index;
        }
        ptr = ptr->next;
        index++;
    }

    return -1;
}

//=========================================================
//operator[]
//This methods returns a reference to the data at the position specified by index
//PARAMETERS:
//index, int: index of the node
//RETURN VALUE:
//- reference to the data at the specified index
//=========================================================
template <class T>
		T & DoublyLinkedList<T>::operator[] ( int index )
{
    if (index < 0 || index >= length()) {
        throw out_of_range("Index out of range");
    }

    Node *ptr = head;
	int traverse_index = 0;
    while (ptr != nullptr && traverse_index < index) { 
        ptr = ptr->next;
        traverse_index++;
    }
	
    return ptr->data;
}

//=========================================================
//length
//This method returns the number of elements in the DoublyLinkedList.
//PARAMETERS:
//none
//RETURN VALUE:
//- integer value of number of nodes in the DoublyLinkedList
//=========================================================
template <class T>
		int DoublyLinkedList<T>::length ( void ) const
{
    return size;
}


//=========================================================
//empty
//This method returns true if the DoublyLinkedList is empty and returns 
//false otherwise
//PARAMETERS:
//none
//RETURN VALUE:
//- returns true if the DoublyLinkedList is empty, false otherwise (bool)
//=========================================================
template <class T>
		bool DoublyLinkedList<T>::empty ( void ) const
{
	return head == nullptr;
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
	Node *ptr = head;			//destructor 
    Node *deleting_node;
    while(ptr != nullptr){
        deleting_node = ptr;
        ptr = ptr -> next;
        delete deleting_node;
    }
	size = 0;
	head = nullptr;					//copy constructor
	ptr = list.head;
	//create the head
	if(ptr != nullptr){
		//create newnode and copy data
		Node *newnode = createNewNode(ptr -> data);
		head = newnode;
		tail = newnode;
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
	
	return *this;		//return the object
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
	DoublyLinkedList<T> newlist(*this);  //creates new list 
	Node *ptr = list.head;
	while(ptr != nullptr){
		newlist.append(ptr -> data);
		ptr = ptr -> next;
	}
	return newlist;
}