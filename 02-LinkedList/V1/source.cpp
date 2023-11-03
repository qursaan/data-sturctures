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
    size_t size;

public:
    // Constructor and Destructor
    SinglyLinkedList() : head(nullptr), size(0) {}

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

    // Insertion Function
    void pushBack(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
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

    std::cout << "Size of the list: " << intList.getSize() << std::endl;
    std::cout << "List elements: ";
    intList.print();

    return 0;
}
