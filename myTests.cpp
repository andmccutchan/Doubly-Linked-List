// myTests.cpp
// Andrew McCutchan, Jin Seok Youn, Beck Robins
// 09/13/2024
// Contains extensive testing of our doubly-linked list
//=========================================================
#include <iostream>
#include "DoublyLinkedList.cpp"

int main(void){
    
    cout << "Create empty double linked list" << endl;
    DoublyLinkedList<int> list1;
    cout << "list1: " << list1 << endl;
    cout << "Is list1 empty: " << list1.empty() << endl;
    cout << "Appending 0~5 in list1" << endl;
    for(int i = 0; i <= 5; i ++){
        list1.append(i);
    }
    cout << "Expected: 0, 1, 2, 3, 4, 5 Result: " << list1 << endl;
    cout << "Is list1 empty: " << list1.empty() << endl;
    list1.prepend(5);
    cout << "prepend 5 to list1" << endl;
    cout << "Expected: 5, 0, 1, 2, 3, 4, 5 Result: " << list1 << endl;
    
    cout << "\nTest copy constructor" << endl;
    cout << "list1: " << list1 << endl;
    DoublyLinkedList<int> list2(list1);
    cout << "Copy constructed list2 from list1" << endl;
    cout << "list2: " << list2 << endl;
    cout << "Prepend 1 to list1" << endl;
    list1.prepend(1);
    cout << "list1: " << list1 << endl;
    cout << "Append 3 to list2" << endl;
    list2.append(3);
    cout << "list2: " << list2 << endl;
    
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
    
    //insert
    cout << "\nTesting insert" << endl << endl;
    cout << "list3: " << list3 << "length: " << list3.length() << endl;
    cout << "Insert 999 to index 3 of list3" << endl;
    list3.insert(999, 3);
    cout << "list3: " << list3 << "length: " << list3.length() << endl;
    cout << "Insert 99 to index 0 of list3" << endl;
    list3.insert(99, 0);
    cout << "list3: " << list3 << "length: " << list3.length() << endl;
    cout << "Insert 100 to the end of list3" << endl;
    list3.insert(100, list3.length());
    cout << "list3: " << list3 << "length: " << list3.length() << endl;
    // cout << "Insert 33 to out of bound" << endl;
    // list3.insert(100, list3.length() + 1);
    // cout << "list3: " << list3 << "length: " << list3.length() << endl;
    
    //remove
    cout << "\nTesting remove" << endl << endl;
    cout << "Remove the end of list3" << endl;
    list3.remove(list3.length() - 1);
    cout << "list3: " << list3 << "length: " << list3.length() << endl;
    cout << "Remove the first of list3" << endl;
    list3.remove(0);
    cout << "list3: " << list3 << "length: " << list3.length() << endl;
    cout << "Remove index 3" << endl;
    list3.remove(3);
    cout << "list3: " << list3 << "length: " << list3.length() << endl;
    // cout << "Remove out of bound" << endl;
    // list3.remove(list3.length());
    // cout << "list3: " << list3 << endl;
    
    //search
    list1.append(6);
    cout << "\nTesting search" << endl << endl;
    cout << "list1: " << list1 << endl;
    cout << "Search for 1 in list1" << endl;
    cout << list1.search(1) << endl;
    cout << "Search for 0 in list1" << endl;
    cout << list1.search(0) << endl;
    cout << "Search for 6 in list1" << endl;
    cout << list1.search(6) << endl;
    cout << "Search for non-existing number in list1" << endl;
    cout << list1.search(999) << endl;
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