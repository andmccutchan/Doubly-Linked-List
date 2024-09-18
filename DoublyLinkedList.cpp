// DoublyLinkedList.cpp
// Andrew McCutchan, Jin Seok, Beck Robins
// 09/13/2024
// Contains the main class method implementations.
//=========================================================


//Default constructor
//=========================================================
template <class T>
        DoublyLinkedList<T>::DoublyLinkedList (void)
{
        head = NULL;
		tail = NULL;
}

//Copy constructor
//=========================================================
template <class T>
        DoublyLinkedList<T>::DoublyLinkedList (const DoublyLinkedList<T> &list)
{
        head = NULL:
        
}

//Destructor
//=========================================================
template <class T >
        DoublyLinkedList<T>::~DoublyLinkedList (void)
{

}

//prepend
//=========================================================
template <class T>
void DoublyLinkedList<T>::prepend ( const T &item )
{

}

//append
//=========================================================
template <class T>
void DoublyLinkedList<T>::append ( const T &item )
{

}

//insert
//=========================================================
template <class T>
void DoublyLinkedList<T>::insert ( const T &item, int index )
{
	if (index < 0 || index >= size)
	{
		throw out_of_range("Index out of range.");
	}

	if (index == 0)
	{
		Node nodeX = new Node;
		nodeX->data = item;
		nodeX->next = head;
		nodeX->prev = NULL;
		head = nodeX;
	}

	else {
		Node* ptr = head;
		while (index > 1) {
			ptr = ptr->next;
		}

		Node* nodeX = new Node;
		nodeX->data = item;
		nodeX->next = ptr->next;
		nodeX->prev = ptr->prev;
		ptr->next = nodeX;
	}
}

//
//=========================================================
template <class T>
void DoublyLinkedList<T>::remove ( int index )
{
	if (index < 0 || index >= size)
	{
		throw out_of_range("Index out of range.");
	}

	if (index == 0)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	else if (index == size-1)
	{
		Node* temp = tail;

	}
	else {
		Node* ptr = head;
		while (index > 1) 
		{
			ptr = ptr->next;
			index--;
		}
		Node* temp =
		temp = ptr->prev;
		temp->next = ptr->next;
		ptr->next->prev = temp;
		delete ptr;
		ptr = NULL;
		size--;
	}

	
}

//
//=========================================================
template <class T>
int DoublyLinkedList<T>::search ( const T &item ) const
{
    
}

//
//=========================================================
template <class T>
T & DoublyLinkedList<T>::operation[] ( int index )
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