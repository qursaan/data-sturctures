# LinkedList Project

## Task 1

- Create a C++ template class called SinglyLinkedList to do the following:

1. Main Template Class:
    - Create a C++ template class called SinglyLinkedList to represent a singly-linked list of elements.
    - Allow the user to specify the type of elements the array will hold.
2. Constructor and Destructor:
    - Design a constructor to initialize an empty singly-linked list.
    - Ensure that the destructor properly cleans up the memory allocated by the class and deletes all nodes in the list.
3. Node Structure:
    - Create a nested structure Node inside the SinglyLinkedList class to represent a node of the list.
    - The node should contain data of the specified type and a pointer to the next node.
4. Get Size Function:
    - Implement a function getSize that returns the current size of the list.
5. Insertion Functions:
    - Implement a pushBack function to insert an element at the end of the list.
6. Traversal Function:
    - Create a function print that traverses the list and prints its elements.
7. Testing and Demonstration:
    - Create a main function to test the SinglyLinkedList template class.
    - Create an instance of SinglyLinkedList for a specific data type (int) and demonstrate its usage.


## Task 2

1. Structure
    - Create tail to LinkedList structure
2. Update Function
    - Modify Constructor and Destructor
    - Modify the pushBack function to take a new element and insert it at the end of the list. Make sure to handle this addition correctly, considering the changes introduced in the previous functions.
3. Reverse Function
    - Implement a function reverse that reverses the order of elements in the singly-linked list.
4. Delete at Function
    - Implement a function deleteAt that takes an index as a parameter and deletes the element at that index. Make sure to handle cases where the index is out of bounds.
5. Pop Back Function
    - Implement a function popBack that removes the last element from the list. Ensure that the list is updated correctly after the removal.
6. Find Function
    - Implement a function find that takes an element as a parameter and returns the index of the first occurrence of that element in the list. If the element is not found, return -1.
7. Testing and Demonstration
    - Create an instance of SinglyLinkedList for a specific data type (int) and demonstrate its usage of the new functionalities, including reversing the list, deleting elements at various positions, popping elements from the end, and updating the pushBack function to add elements to the end of the list.
