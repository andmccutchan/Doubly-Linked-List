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
        Node *ptr = list.head;
        //create the head
        if(ptr != nullptr){
                //create newnode and copy data
                Node *newnode = createNewNode(ptr -> data);
                head = newnode;
                ptr = ptr -> next;
        }
        //Creating other nodes
        Node *track = head;
        while (ptr != nullptr){
                Node *newnode = createNewNode(ptr -> data);
                track -> next = newnode; //link the newnode
                ptr = ptr -> next;
                track = track -> next;
                tail = newnode; //update new tail
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
        }else{
                Node *ptr = head; //get head
                //add newnode to the front
                ptr -> prev = newnode; 
                newnode -> next = ptr;
                head = newnode; //update head
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
        }else{
                Node *ptr = tail; //get tail
                //add newnode to the end
                ptr -> next = newnode;
                newnode -> prev = ptr;
                tail = newnode; //update tail
        }
}

//insert
//=========================================================
template <class T>
void DoublyLinkedList<T>::insert ( const T &data, int index )
{

}

//
//=========================================================
template <class T>
void DoublyLinkedList<T>::remove ( int index )
{
    
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

//
//=========================================================
template <class T>
DoublyLinkedList<T> DoublyLinkedList<T>::concat  (const DoublyLinkedList<T> &list ) const
{

}