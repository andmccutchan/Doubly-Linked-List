# Doubly-Linked-List
## Andrew McCutchan, Jin Seok Youn, Beck Robins
## Files: 
### DoublyLinkedList.cpp
 -Main file that contains all of the class methods for our Doubly Linked List class. Contains:
 1. Default Constructor
 2. Copy Constructor
 3. Destructor
 4. Assignment operator
 5. createNewNode function
 6. Prepend
 7. Append
 8. Insert Remove
 9. Search 
 10. Operator[]
 11. Length
 12. isEmpty
 13. Concat
 ### DoublyLinkedList.hpp 
 -Header file that contains the class declaration and all of the function declarations. Private method includes a node struct, a function declaration for out creatNewNode function, and pointers to the head and tail of a list as well as the size of a list. Included in the public method is a friend function to override the cout opertor and print out our lists.
### makefile
-Make file for compiling our separat files in one command.
### myTests.cpp
-An extensive list of tests for each of our functions. 

### Creative decisions
-For cleanliness sake of this project we created a function that creates a node and populates each item of the node with data. 
-We also added an assignment operator.