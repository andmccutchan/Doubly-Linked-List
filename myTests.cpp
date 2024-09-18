// myTests.cpp
// Andrew McCutchan, Jin Seok Youn, Beck Robins
// 09/13/2024
// Contains extensive testing of our doubly-linked list
//=========================================================
#include <iostream>
#include "DoublyLinkedList.cpp"

int main(void){
    DoublyLinkedList<int> list1;
    cout << "list1" << list1 << endl;
    
    for(int i = 0; i <= 5; i ++){
        list1.append(i);
    }
    cout << "Expected: [0, 1, 2, 3, 4, 5] Result: " << list1 << endl;
    list1.prepend(5);
    cout << "prepend 5" << endl;
    cout << "Expected: [5, 0, 1, 2, 3, 4, 5] Result: " << list1 << endl;
    
    DoublyLinkedList<int> list2(list1);
    cout << "Copy constructed list2 from list1" << endl;
    cout << "list2: " << list2 << endl;
    cout << "Prepend 1 to list1" << endl;
    list1.prepend(1);
    cout << "list1: " << list1 << endl;
    cout << "Append 3 to list2" << endl;
    list2.append(3);
    cout << "list2: " << list2 << endl;
    
    DoublyLinkedList<int> list3;
    list3 = list1.concat(list2);
    cout << list3 << endl;
    cout << list1 << endl;
    cout << list2 << endl;

}