#include <iostream>
#include <stdexcept>

template <typename T>
class DynamicArray {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    // Constructor
    DynamicArray(size_t initialCapacity = 2): size(0), capacity(initialCapacity) {
        data = new T[capacity];
    }

    // Destructor
    ~DynamicArray() {
        delete[] data;
    }

    // Copy constructor
    DynamicArray(const DynamicArray& other): size(other.size), capacity(other.capacity) {
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Resize the dynamic array
    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        size_t newSize = std::min(size, newCapacity);
        for (size_t i = 0; i < newSize; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
        size = newSize;  // Be cautious with how this affects existing data!
    }

    // Function to get the current size of the array
    size_t getSize() const {
        return size;
    }

    // Function to get the current capacity of the array
    size_t getCapacity() const {
        return capacity;
    }

    // Function to set the value at a specific index
    void setElementAt(size_t index, T value) {
        if (index >= capacity) {
            throw std::out_of_range("Index out of range");
        }
        if (index >= size) {
            size = index + 1; // Update size to reflect the highest index + 1
        }
        data[index] = value;
    }

    // Function to access elements of the array by index
    T& getElementAt(size_t index) const {
        if (index >= capacity) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};

int main() {
    DynamicArray<int> intArray(20); // Create a DynamicArray of integers

    // Fill array
    for (size_t i = 0; i < intArray.getCapacity(); ++i) {
        intArray.setElementAt(i, i * 10);
    }
    for (size_t i = 0; i < intArray.getSize(); ++i) {
        std::cout << intArray.getElementAt(i) << " ";
    }
    std::cout << std::endl;

    // Print its contents
    intArray.resize(10);
    for (size_t i = 0; i < intArray.getSize(); ++i) {
        std::cout << intArray.getElementAt(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
