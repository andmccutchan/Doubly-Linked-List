// DoublyLinkedList.hpp
// Andrew McCutchan, Jin Seok, Beck Robins
// 09/13/2024
// Contains the header file contents
//=========================================================

#include <iostream>
#include <string>
using namespace std;

#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

template <class T>
class DoublyLinkedList
{
    private:
        struct Node
        {
            T data;
            Node* next;
            Node* prev;
        }

        Node* head;
        Node* tail;
        int size;

    public:
        void prepend ( const T &item );
        void append ( const T &item );
        void insert ( const T &item, int index );
        void remove ( int index );
        int search ( const T &item ) const;
        T & operation[] ( int index );
        int length ( void ) const;
        bool empty ( void ) const;
        DoublyLinkedList<T> concat (const DoublyLinkedList<T> &list ) const;


        //friend function to overload the << operator to display our list 
        friend ostream & operator<< (ostream &os, DoublyLinkedList<T> &list)
        {
           
        }
};

#endif