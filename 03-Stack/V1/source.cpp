#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;
    size_t capacity;
    int currtop;
    string name;

public:
    Stack(string stackName, size_t capacity = 10) : name(stackName), capacity(capacity), currtop(-1) {
        arr = new T[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(T element) {
        assert(!isFull() && "Error: Stack is full. Cannot push element.\n");
        arr[++currtop] = element;
    }

    T pop() {
        assert(!isEmpty() && "Error: Stack is empty. Cannot pop element.\n");
        T topElement = arr[currtop--];
        return topElement;
    }

    bool isFull() {
        return currtop == static_cast<int>(capacity) - 1;
    }

    bool isEmpty() {
        return currtop == -1;
    }

    T top() {
        assert(!isEmpty() && "Error: Stack is empty. Cannot retrieve top element.\n");
        return arr[currtop];
    }

    void print() {
        cout << name << " Stack: ";
        for (int i = 0; i <= currtop; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    string getName() const {
        return name;
    }
};

void moveDisk(Stack<int>& source, Stack<int>& destination) {
    int disk = source.pop();
    destination.push(disk);
    cout << "Move disk " << disk << " from " << source.getName() << " to " << destination.getName() << "\n";
}

void towerOfHanoi(int numDisks, Stack<int>& source, Stack<int>& auxiliary, Stack<int>& destination) {
    if (numDisks == 1) {
        moveDisk(source, destination);
        return;
    }

    towerOfHanoi(numDisks - 1, source, destination, auxiliary);
    moveDisk(source, destination);
    towerOfHanoi(numDisks - 1, auxiliary, source, destination);
}

int main() {
    Stack<int> source("Source"), auxiliary("Auxiliary"), destination("Destination");

    int numDisks = 3;

    for (int i = numDisks; i >= 1; --i) {
        source.push(i);
    }

    cout << "Initial state of the rods:\n";
    source.print();
    auxiliary.print();
    destination.print();

    towerOfHanoi(numDisks, source, auxiliary, destination);

    cout << "Final state of the rods:\n";
    source.print();
    auxiliary.print();
    destination.print();

    return 0;
}
