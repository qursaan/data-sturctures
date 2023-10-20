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
    DynamicArray(size_t initialCapacity) : size(0), capacity(initialCapacity) {
        data = new T[capacity];
    }

    // Destructor to clean up dynamic memory
    ~DynamicArray() {
        delete[] data;
    }

    // Copy constructor without std::copy
    DynamicArray(const DynamicArray<T>& other) : size(other.size), capacity(other.capacity) {
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Assignment operator without std::copy
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
    void resize(size_t newSize) {
        if (newSize <= 0) {
            throw std::invalid_argument("Invalid new size");
        }

        T* newData = new T[newSize];

        // Copy elements from the old array to the new one, up to the minimum of size and newSize
        for (size_t i = 0; i < std::min(size, newSize); ++i) {
            newData[i] = data[i];
        }

        // Deallocate the old memory and update the pointer and size
        delete[] data;
        data = newData;
        size = newSize;
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
            resize(2 * capacity); // Double the capacity if full
        }
        data[size++] = value;
    }

    // Insert an element at the beginning
    void insertFront(const T& value) {
        if (size == capacity) {
            resize(2 * capacity); // Double the capacity if full
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
        }
    }
};

int main() {
    DynamicArray<int> myArray(5);

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

    std::cout << "Updated size of array: " << myArray.getSize() << std::endl;
    std::cout << "Updated array contents: ";
    for (size_t i = 0; i < myArray.getSize(); i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
