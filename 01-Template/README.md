# Template Class Project

## Task 1

- Create a template class to do the following:

1. Main Template Class:
   - Create a C++ template class called ``ArrayZilla`` that accepts two template parameters:
     - ``T``: The type of elements the array will hold.
     - ``N``: The size of the array.
2. Constructor:
   - Design the constructor to initialize the array elements.
3. Copy Constructor:
   - Implement a copy constructor that allows creating a copy of an existing ``ArrayZilla`` object.
4. Access Function:
   - Create a function to access elements of the array by index.
5. Get Size Function:
   - Implement a function getSize that returns the current size of the array.
6. Print Function:
   - Implement a print function that displays all the elements of the array in a single line.
7. Testing and Demonstration:
   - Create a main function to test the ``ArrayZilla`` template class.
   - Create an instance of ``ArrayZilla`` for a specific data type and demonstrate its usage.

## Task 2

- Create an implementation to do the following:

1. Template Interface:
   - Create an abstract template class ``Storage<T>``, where ``T`` represents the type of items stored in the container.
   - The interface should include the following functions:
     - ``void addItem(const T& item)``
     - ``T getItem(size_t index)``
     - ``size_t getSize() const``
2. Derived Classes:
   - Implement at least two derived classes:
     - ``Bag<T>``: Represents a container where items are stored in integer
     - ``Box<T>``: Represents a container where items are stored in ``ArrayZilla``.
   - Each derived class must override the virtual functions from the interface.
3. Testing and Demonstration:
   - In the main function, create instances of ``Box<int>`` and ``Bag<int>``.
   - Add a few integers to each container using the ``addItem`` function.
   - Display the contents of each container using the ``getItem`` function.
