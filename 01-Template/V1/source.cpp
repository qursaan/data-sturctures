#include <iostream>
#include <stdexcept>

using namespace std;

// Template class for a fixed-size array
template <typename T, size_t N>
class ArrayZilla {
private:
    T arr[N]; // Fixed-size array of type T

public:
    // Constructor: Initialize array with default values
    ArrayZilla() {
        for (size_t i = 0; i < N; ++i) {
            arr[i] = T(); // Initialize each element with the default value of type T
        }
    }

    // Copy Constructor: Copy from another ArrayZilla
    ArrayZilla(const ArrayZilla<T, N>& other) {
        for (size_t i = 0; i < N; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // Function to access an element at a given index
    T& at(size_t index) {
        if (index >= N) {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }

    // Function to get the size of the array
    size_t getSize() const {
        return N;
    }

    // Function to print the contents of the array
    void print() const {
        for (size_t i = 0; i < N; ++i) {
            cout << arr[i] << " ";
        }
        cout << std::endl;
    }
};

// Main test the ArrayZilla class
int main() {
    // Create an ArrayZilla of integers with size 5
    ArrayZilla<int, 5> intArray;

    // Access/modify the elements
    for (size_t i = 0; i < intArray.getSize(); ++i) {
        intArray.at(i) = i * 10; // Assign values 
    }

    // Print the contents of the array 
    cout << "Integer ArrayZilla: ";
    intArray.print();

    // A copy of the array
    ArrayZilla<int, 5> copiedArray = intArray;

    // Print the copied array 
    cout << "Copied ArrayZilla: ";
    copiedArray.print();


    // Create an ArrayZilla of doubles with size 3
    ArrayZilla<double, 3> doubleArray;

    // Access/modify the elements
    for (size_t i = 0; i < doubleArray.getSize(); ++i) {
        doubleArray.at(i) = i * 1.1; // Assign values
    }

    // Print the contents of the array
    cout << "Double ArrayZilla: ";
    doubleArray.print();

    return 0;
}
