# DynamicArray Project

## Task 1

- Create a C++ template class called DynamicArray to represent a dynamic array of elements.

1. Main Template Class:
    - Create a C++ template class called DynamicArray to represent a dynamic array of elements.
    - Allow the user to specify the type of elements the array will hold.
2. Constructor and Destructor:
    - How can you design the constructor to initialize the dynamic array with a given size?
    - How can you ensure that the destructor properly cleans up the dynamic memory allocated by the class?
3. Copy Constructor:
    - Implement a copy constructor that allows creating a copy of an existing DynamicArray object.
4. Resize Function:
    - How can you create a function resize that allows changing the size of the dynamic array while preserving existing elements?
    - What steps are needed to allocate new memory and copy data when resizing?
5. Get Size Function:
    - Implement a function getSize that returns the current size of the array.
6. Testing and Demonstration:
    - Create a main function to test the DynamicArray template class.
    - Create an instance of DynamicArray for a specific data type (int) and demonstrate its usage.

## Task 2

1. Assignment Operator:
   - Implement an assignment operator *(operator=)* to assign the contents of one DynamicArray to another.
2. Element Access Operator:
   - How can you implement the *operator[]* to access elements of the array by index?
   - How can you handle index out of range errors?
3. Insert Functions:
   - Implement functions for inserting elements at both the end and the beginning of the array.
   - For inserting at the end, create a function named *insertEnd*.
   - For inserting at the beginning, create a function named *insertFront*.
4. Remove Functions
   - Implement functions for removing elements from both the end and the beginning of the array.
   - For removing from the end, create a function named *removeEnd*.
   - For removing from the beginning, create a function named *removeFront*.
5. Testing and Demonstration:
   - Create a DynamicArray and insert elements at the end and the beginning.
   - Verify that elements are inserted correctly.
   - Remove elements from both the end and the beginning.
   - Ensure that elements are removed in the correct order.

## Task 3

1. Resize Function:
   - Update the *resize* function to automatically double the size if needed when inserting new elements, and shrink the size if needed when removing elements.
   - You may choose a resizing strategy, such as doubling or halving the size, when the array reaches its capacity..
2. Startup Capacity
   - Start the array with an initial capacity of *2*.
3. Add Function:
   - Implement a function named *add* that allows inserting an element at any specified location within the array.
   - Resize if needed.
   - Ensure you handle index out of range errors for this function as well.
4. Remove Functions
   - Implement a function named remove to remove an element from any specified location within the array.
   - Shrink if needed.
   - Handle index out of range errors for this function.
5. Testing and Demonstration:
   - Create a DynamicArray and insert elements at the end, the beginning, and any specified location.
   - Verify that elements are inserted correctly and that resizing works as expected.
   - Remove elements from the end, the beginning, and any specified location.
   - Ensure that elements are removed in the correct order and that resizing works as expected when elements are removed.