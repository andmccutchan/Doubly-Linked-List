// DoublyLinkedList.hpp
// Andrew McCutchan, Jin Seok Youn, Beck Robins
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
        };
        Node* createNewNode(const T &data); //Helper function to create new node with data
        Node* head;
        Node* tail;
        int size;

    public:
                DoublyLinkedList    (void);
                DoublyLinkedList    (const DoublyLinkedList<T> &list);
                ~DoublyLinkedList   (void);
        void    prepend             ( const T &data );
        void    append              ( const T &data );
        void    insert              ( const T &data, int index );
        void    remove              ( int index );
        int     search              ( const T &data ) const;
                T & operator[]     ( int index );
        int     length              ( void ) const;
        bool    empty               ( void ) const;
        DoublyLinkedList<T> concat  (const DoublyLinkedList<T> &list ) const;


        //friend function to overload the << operator to display our list 
        friend ostream & operator<< (ostream &os, DoublyLinkedList<T> &list)
        {
            Node *ptr = list.head;
            os << "[";
            while (ptr != NULL)
            {
                if (ptr -> next != NULL){
                    os << ptr -> data << ", ";}
                else{
                    os << ptr -> data;}
                ptr = ptr -> next;
            }
            os << "]";
            return os;	
        }
};


#endif