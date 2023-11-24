# Stack Project

## Task 1

### Tower of Hanoi with Stack Implementation

1. Stack Implementation:
   - Create a C++ template class called Stack to represent a stack data structure. The stack should support basic operations such as push, pop, and peek.
2. Tower of Hanoi Problem:
   - Implement a function called towerOfHanoi that solves the Tower of Hanoi problem using the stack data structure.
   - The Tower of Hanoi consists of three rods and a number of disks of different sizes, which can slide onto any rod.
   - The puzzle starts with the disks in a neat stack in ascending order of size on one rod, the smallest at the top.
3. Function Signatures
   - ```void towerOfHanoi(int numDisks, Stack<int>& source, Stack<int>& auxiliary, Stack<int>& destination)```;
       - This function should take the number of disks and three stacks representing the source, auxiliary, and destination rods.
       - It should move the disks from the source rod to the destination rod using the auxiliary rod, following the rules of the Tower of Hanoi.
4. Rules for Tower of Hanoi:
    - Only one disk can be moved at a time.
    - A disk can only be moved to the top of another rod if it is smaller than the top disk on that rod or if the destination rod is empty.
5. Print Function:
    - Implement a function that prints the current state of the rods after each move. This will help visualize the Tower of Hanoi solution.
6. Testing and Demonstration
   - Create an instance of the Stack class for a specific data type (int).
   - Test the towerOfHanoi function with a different number of disks and demonstrate the movement of disks from the source rod to the destination rod.
