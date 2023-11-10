#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class SinglyLinkedList {
private:
    Node<T> * head;
    Node<T> * tail;  // Add a tail pointer
    size_t size;

public:
    // Constructor and Destructor
    SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~SinglyLinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Get Size Function
    size_t getSize() const {
        return size;
    }

    // Insertion Function (Update pushBack function)
    void pushBack(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            tail = newNode;         // Update the tail to the new node
        } else {
            tail->next = newNode;   // Update the current tail's next to the new node
            tail = newNode;         // Update the tail to the new node
        }
        size++;
    }

    // Reverse Function
    void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        // Swap head and tail pointers
        Node<T>* temp = head;
        head = tail;
        tail = temp;
    }

    // Delete at Function
    void deleteAt(size_t index) {
        if (index >= size || index < 0) {
            std::cerr << "Index out of bounds." << std::endl;
            return;
        }
        if (index == 0) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node<T>* current = head;
            for (size_t i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node<T>* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        size--;
    }

    // Pop Back Function
    void popBack() {
        if (size == 0) {
            std::cerr << "List is empty." << std::endl;
            return;
        }
        deleteAt(size - 1);
    }

    // Find Function
    int find(const T& value) {
        Node<T>* current = head;
        int index = 0;
        while (current) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;  // Element not found
    }

    // Traversal Function
    void print() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data;
            if (current->next) {
                std::cout << " -> ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Testing and Demonstration
    SinglyLinkedList<int> intList;
    intList.pushBack(1);
    intList.pushBack(2);
    intList.pushBack(3);

    std::cout << "Original List: ";
    intList.print();

    intList.reverse();
    std::cout << "Reversed List: ";
    intList.print();

    intList.deleteAt(1);
    std::cout << "List after deleting element at index 1: ";
    intList.print();

    intList.popBack();
    std::cout << "List after popping the last element: ";
    intList.print();

    int index = intList.find(2);
    if (index != -1) {
        std::cout << "Element 2 found at index " << index << std::endl;
    } else {
        std::cout << "Element 2 not found in the list." << std::endl;
    }

    return 0;
}
