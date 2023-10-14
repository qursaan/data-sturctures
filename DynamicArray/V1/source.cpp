#include <iostream>
#include <stdexcept>

template < typename T >
  class DynamicArray {
    private: T * data; 
    size_t size;

    public:
      // Constructor
      DynamicArray(size_t initialSize = 0): size(initialSize) {
        data = new T[size];
      }

      // Destructor 
      ~DynamicArray() {
        delete[] data;
      }

    // Copy constructor
    DynamicArray(const DynamicArray & other): size(other.size) {
      data = new T[size];
      for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
      }
    }

    // resize the dynamic array
    void resize(size_t newSize) {
      T * newData = new T[newSize];

      // Copy elements from the old array to the new one
      for (size_t i = 0; i < std::min(size, newSize); ++i) {
        newData[i] = data[i];
      }

      // Deallocate the old memory and update the pointer and size
      delete[] data;
      data = newData;
      size = newSize;
    }

    // Function to access elements of the array by index 
    T& getElementAt(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Function to get the current size of the array
    size_t getSize() const {
      return size;
    }
  };

int main() {
  // Create a DynamicArray of integers
  DynamicArray < int > intArray(5);

  // Fill array
  for (size_t i = 0; i < intArray.getSize(); ++i) {
      intArray.getElementAt(i) = i * 10;
  }

  // Resize the array and print its contents
  intArray.resize(10);
  for (size_t i = 0; i < intArray.getSize(); ++i) {
    std::cout << intArray.getElementAt(i) << " ";
  }
  std::cout << std::endl;

  return 0;
}

