#include <iostream>
#include <stdexcept>

template <typename T>
class DynamicArray {
private:
    T* data; // Pointer to dynamically allocated array
    size_t size; // Current number of elements in the array
    size_t capacity; // Full array Capacity

public:
    // Constructor to initialize the dynamic array with a given size
    DynamicArray() {
        size = 0;
        capacity = 2;
        data = new T[capacity];
    }

    // Destructor to clean up dynamic memory
    ~DynamicArray() {
        delete[] data;
    }

    // Copy constructor 
    DynamicArray(const DynamicArray<T>& other) : size(other.size), capacity(other.capacity) {
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Assignment operator 
    DynamicArray& operator=(const DynamicArray<T>& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Function to resize the dynamic array
    void resize() {
        size_t new_capacity = std::max(2 * (int)size, 2);
        T* brr = new T[new_capacity];
        for (int i = 0; i < size; i++)
            brr[i] = data[i];
        delete[] data;
        data = brr;
        capacity = new_capacity;
    }

    // Function to access elements of the array by index
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Function to get the current size of the array
    size_t getSize() const {
        return size;
    }

    // Insert an element at the end
    void insertEnd(const T& value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    // Insert an element at the beginning
    void insertFront(const T& value) {
        if (size == capacity) {
            resize();
        }
        // Shift elements to the right
        for (size_t i = size; i > 0; --i) {
            data[i] = data[i - 1];
        }
        data[0] = value;
        size++;
    }

    // Remove an element from the end
    void removeEnd() {
        if (size > 0) {
            size--;
            if (size < 3 * capacity) {
                resize();
            }
        }
    }

    // Remove an element from the beginning
    void removeFront() {
        if (size > 0) {
            // Shift elements to the left
            for (size_t i = 0; i < size - 1; i++) {
                data[i] = data[i + 1];
            }
            size--;
            if (size < 3 * capacity) {
                resize();
            }
        }
    }

    // Add an element at a specified location
    void add(size_t index, const T& value) {
        if (index > size || index < 0) {
            throw std::out_of_range("Index out of range");
        }

        if (size == capacity) {
            resize();
        }

        // Shift elements to the right to make space for the new element
        for (size_t i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    // Remove an element from a specified location
    void remove(size_t index) {
        if (index >= size || index < 0) {
            throw std::out_of_range("Index out of range");
        }

        // Shift elements to the left to fill the gap left by the removed element
        for (size_t i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        if (size < 3 * capacity) {
            resize();
        }
    }
};

int main() {
    DynamicArray<int> myArray;

    myArray.insertEnd(1);
    myArray.insertEnd(2);
    myArray.insertEnd(3);

    std::cout << "Size of array: " << myArray.getSize() << std::endl;
    std::cout << "Array contents: ";
    for (size_t i = 0; i < myArray.getSize(); i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    myArray.insertFront(0);
    myArray.removeEnd();
    myArray.removeFront();
    myArray.add(1, 4); // Add 4 at index 1
    myArray.remove(2); // Remove element at index 2

    std::cout << "Updated size of array: " << myArray.getSize() << std::endl;
    std::cout << "Updated array contents: ";
    for (size_t i = 0; i < myArray.getSize(); i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
