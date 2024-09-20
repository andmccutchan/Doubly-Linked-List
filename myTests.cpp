// myTests.cpp
// Andrew McCutchan, Jin Seok Youn, Beck Robins
// 09/20/2024
// Contains extensive testing of our doubly-linked list
//=========================================================

#include <iostream>
#include "DoublyLinkedList.cpp"

void testDefaultConstructor (void);
void testCopyConstructor (void);
void testPrepend (void);
void testAppend (void);
void testInsert (void);
void testRemove (void);
void testSearch (void);
void testIndexingOperator (void);
void testLength(void);
void testEmpty(void);
void testConcat(void);


int main(void){
    testDefaultConstructor ();
    testCopyConstructor ();
    testPrepend ();
    testAppend ();
    testInsert ();
    testRemove ();
    testSearch ();
    testIndexingOperator ();
    testLength ();
    testEmpty ();
    testConcat ();
}


//=============================================
// Testing Default Constructor
// This function creates a new empty doubly-linked- 
// list of type int.
// PARAMETERS: 
// - none
// RETURN VALUE: 
// - none
//=============================================
void testDefaultConstructor (void){
    cout << "\nTesting default constructor" << endl << endl;
    cout << "Create empty double linked list" << endl;
    DoublyLinkedList<int> list1;                //creates an empty doubly-linked-list called list1
    cout << "list1: " << list1 << endl;
    cout << "Is list1 empty: " << list1.empty() << endl;
}

//=============================================
// Testing copy constrcutor
// This function populates list1 with numbers 0-5.
// Then it creates a new list called list3 using the copy
// constructor to make it the same as the elements
// in list1
// PARAMETERS: 
// - none
// RETURN VALUE: 
// - none
//=============================================
void testCopyConstructor (void){
    DoublyLinkedList<int> list1;
    for(int i = 0; i <= 5; i ++){       //populates a list with 0-5
        list1.append(i);
    }
    cout << "\nTest copy constructor" << endl;
    cout << "list1: " << list1 << endl;
    DoublyLinkedList<int> list2(list1);         //creates a new list called list2 with the elements of list1
    cout << "Copy constructed list2 from list1" << endl;
    cout << "list2: " << list2 << endl;
    cout << "\nTest deep copy" << endl << endl;
    cout << "Prepend 1 to list1" << endl;       //adds 1 to the beginning of list1
    list1.prepend(1);
    cout << "list1: " << list1 << endl;
    cout << "Append 3 to list2" << endl;        //adds 3 to the end of list2
    list2.append(3);
    cout << "list2: " << list2 << endl;
}

//=============================================
// Testing prepend
// This test creates a new list1, then adds 
// 5 to the beginning of list1
// PARAMETERS: 
// - none
// RETURN VALUE: 
// - none
//=============================================
void testPrepend (void){
    cout << "\nTesting prepend" << endl << endl;
    DoublyLinkedList<int> list1;
    for(int i = 0; i <= 5; i ++){
        list1.append(i);
    }
    cout << "list1: " << list1 << endl;
    list1.prepend(5);
    cout << "prepend 5 to list1" << endl;
    cout << "list1: " << list1 << endl;
}

//=============================================
// Testing append
// this tests append by making and empty list,
// then using a for loop, it populates that list
// by using the append method
// PARAMETERS: 
// - none
// RETURN VALUE: 
// - none
//=============================================
void testAppend (void){
    cout << "\nTesting append" << endl << endl;
    DoublyLinkedList<int> list1;                //creates list1
    cout << "list1: " << list1 << endl;
    for(int i = 0; i <= 5; i ++){
        cout << "Appending " << i << " to list1" << endl;       //appends i for each index of the for loop
        list1.append(i);
    }
    cout << "list1: " << list1 << endl;
}

//=============================================
// Testing insert
// This creates a new list3, then tests inserting
// integers at various indexes of list3
// PARAMETERS: 
// - none
// RETURN VALUE: 
// - none
//=============================================
void testInsert (void){
    DoublyLinkedList<int> list3;
    for(int i = 0; i <= 5; i ++){
        list3.append(i);
    }
    //insert
    cout << "\nTesting insert" << endl << endl;
    cout << "list3: " << list3 << " length: " << list3.length() << endl;
    cout << "Insert 999 to index 3 of list3" << endl;                       //testing insertion at random index within the list
    list3.insert(999, 3);
    cout << "list3: " << list3 << " length: " << list3.length() << endl;
    cout << "Insert 99 to index 0 of list3" << endl;                        //testing insertion at beginning of list
    list3.insert(99, 0);
    cout << "list3: " << list3 << " length: " << list3.length() << endl;
    cout << "Insert 100 to the end of list3" << endl;                       //testing insertion at end of list
    list3.insert(100, list3.length());
    cout << "list3: " << list3 << " length: " << list3.length() << endl;
    // cout << "Insert 33 to out of bound" << endl;                         //testing error at out of bounds insertion (commented out so program continues)
    // list3.insert(100, list3.length() + 1);
    // cout << "list3: " << list3 << " length: " << list3.length() << endl;
}

//=============================================
// Testing remove
// creates a new list3 and tests removing nodes at
// various indexes of list3.
// PARAMETERS: 
// - none
// RETURN VALUE: 
// - none
//=============================================
void testRemove (void){
    DoublyLinkedList<int> list3;
    for(int i = 0; i <= 5; i ++){           //create and populate new list3
        list3.append(i);
    }
    cout << "\nTesting Remove" << endl << endl; 
    //remove
    cout << "list3: " << list3 << " length: " << list3.length() << endl;
    cout << "Remove the end of list3" << endl;                              //remove index at end of list
    list3.remove(list3.length() - 1);
    cout << "list3: " << list3 << " length: " << list3.length() << endl;
    cout << "Remove the first of list3" << endl;                            //removing the first index
    list3.remove(0);
    cout << "list3: " << list3 << " length: " << list3.length() << endl;
    cout << "Remove index 2" << endl;                                       //removing index inside the list       
    list3.remove(2);
    cout << "list3: " << list3 << " length: " << list3.length() << endl;
    // cout << "Remove out of bound" << endl;
    // list3.remove(list3.length());                                        //testing out of bounds error
    // cout << "list3: " << list3 << endl;
}

//=============================================
// Testing search
// creates a new list1 and looks for various
// items in list1
// PARAMETERS: 
// - none
// RETURN VALUE: 
// - none
//=============================================
void testSearch (void){
    DoublyLinkedList<int> list1;
    for(int i = 0; i <= 6; i ++){
        list1.append(i);
    }
    //search
    cout << "\nTesting search" << endl << endl;
    cout << "list1: " << list1 << endl;
    cout << "Search for 1 in list1" << endl;
    cout << list1.search(1) << endl;                // search for index in list
    cout << "Search for 0 in list1" << endl;
    cout << list1.search(0) << endl;                // search for item at first index    
    cout << "Search for 6 in list1" << endl;
    cout << list1.search(6) << endl;                // search for item at last index
    cout << "Search for non-existing number in list1" << endl;
    cout << list1.search(999) << endl;              // search for item not in list
}

//=============================================
// Testing index operator
// creates new list1 and returns items at 
// desired index
// PARAMETERS: 
// - none
// RETURN VALUE: 
// - none
//=============================================
void testIndexingOperator (void){
    DoublyLinkedList<int> list1;
    for(int i = 0; i <= 6; i ++){
        list1.append(i);
    }
    //operator[]
    cout << "\nTesting operator[]" << endl << endl;
    cout << "list1: " << list1 << endl;
    cout << "Access index 0 in list1" << endl;
    cout << list1[0] << endl;
    cout << "Access last index in list1" << endl;
    cout << list1[list1.length() - 1] << endl;
    cout << "Access index 3 in list1" << endl;
    cout << list1[3] << endl;
    // cout << "Access out of bound in list1" << endl;
    // cout << list1[999] << endl;
}

//=============================================
//  Testing length
// creates new list1 and returns length of list1
// PARAMETERS: 
// - none
// RETURN VALUE: 
// - none
//=============================================
void testLength(void){
    DoublyLinkedList<int> list1;
    for(int i = 0; i <= 6; i ++){
        list1.append(i);
    }
    cout << "\nTesting length" << endl << endl;
    cout << "list1: " << list1 << endl;
    cout << "list1 length " << list1.length() << endl;
    
}

//=============================================
// Testing empty
// Creates empty list1 then returns if empty, 
// then adds item to list1 and checks if it is empty
// PARAMETERS: 
// - none
// RETURN VALUE: 
// - none
//=============================================
void testEmpty(void){
    DoublyLinkedList<int> list1;
    cout << "\nTesting empty" << endl << endl;
    cout << "list1: " << list1 << endl;
    cout << "Is list1 empty: " << list1.empty() << endl;
    cout << "Appending 3 to list1" << endl;
    list1.append(3);
    cout << "list1: " << list1 << endl;
    cout << "Is list1 empty: " << list1.empty() << endl;
}

//=============================================
// Testing concat
// creates new list1 and new list2.
// concatentates list2 list1 and also adds a new
// item to the list to test the deep copy
// PARAMETERS: 
// - none
// RETURN VALUE: 
// - none
//=============================================
void testConcat(void){
    DoublyLinkedList<int> list1;
    for(int i = 0; i <= 6; i ++){
        list1.append(i);
    }
    
    DoublyLinkedList<int> list2;
    for(int i = 0; i <= 13; i ++){
        i ++;
        list2.append(i);
    }
    //concat
    cout << "\nTesting concat" << endl << endl;
    cout << "Concatenating list1 and list2" << endl;
    cout << "list1: " << list1 << endl;
    cout << "list2: " << list2 << endl;
    DoublyLinkedList<int> list3;
    list3 = list1.concat(list2);
    cout << "list3: " << list3 << endl;
    cout << "Testing deep copy of concat" << endl;
    cout << "Appending 25 to list2" << endl;
    list2.append(25);
    cout << "list2: " << list2 << endl;
    cout << "list3: " << list3 << endl;
    
}