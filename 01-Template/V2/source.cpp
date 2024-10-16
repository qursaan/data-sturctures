#include <iostream>
#include <stdexcept>

using namespace std;

// Template class for a fixed-size array
template <typename T, size_t N>
class ArrayZilla {
private:
    T arr[N];

public:
    // Constructor
    ArrayZilla() {
        for (size_t i = 0; i < N; ++i) {
            arr[i] = T();
        }
    }

    // Copy Constructor
    ArrayZilla(const ArrayZilla<T, N>& other) {
        for (size_t i = 0; i < N; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // Access an element at a given index
    T& at(size_t index) {
        if (index >= N) {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }

    // Get the size of the array
    size_t getSize() const {
        return N;
    }

    // Print the array contents
    void print() const {
        for (size_t i = 0; i < N; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Abstract template
template <typename T>
class Storage {
public:
    // Pure virtual functions
    virtual void addItem(const T& item) = 0;
    virtual T getItem(size_t index)  = 0;
    virtual size_t getSize() const = 0;

    virtual ~Storage() {}
};

// Derived class: Bag (stores integers)
class Bag : public Storage<int> {
private:
    int items[10]; // Fixed-size array of integers
    size_t count;

public:
    Bag() : count(0) {}

    void addItem(const int& item)  {
        if (count < 10) {
            items[count++] = item;
        } else {
            cout << "Bag is full!" << endl;
        }
    }

    int getItem(size_t index)   {
        if (index < count) {
            return items[index];
        } else {
            throw out_of_range("Index out of range");
        }
    }

    size_t getSize() const  {
        return count;
    }
};

// Derived class: Box (stores items using ArrayZilla)
template <typename T, size_t N>
class Box : public Storage<T> {
private:
    ArrayZilla<T, N> items;
    size_t count;

public:
    Box() : count(0) {}

    void addItem(const T& item) {
        if (count < N) {
            items.at(count++) = item;
        } else {
            cout << "Box is full!" << endl;
        }
    }

    T getItem(size_t index) {
        if (index < count) {
            return this->items.at(index);
        } else {
            throw out_of_range("Index out of range");
        }
    }

    size_t getSize() const {
        return count;
    }
};

// Polymorphism function
template <typename T>
void showStorageContents(Storage<T>& storage) {
    for (size_t i = 0; i < storage.getSize(); ++i) {
        cout << storage.getItem(i) << " ";
    }
    cout << endl;
}

int main() {
    // Create instances of Bag and Box
    Bag intBag;
    Box<int, 5> intBox;

    // Add items to the Bag
    intBag.addItem(1);
    intBag.addItem(2);
    intBag.addItem(3);

    // Add items to the Box
    intBox.addItem(10);
    intBox.addItem(20);
    intBox.addItem(30);

    // Display contents using polymorphism
    cout << "Bag contents: ";
    showStorageContents(intBag);

    cout << "Box contents: ";
    showStorageContents(intBox);

    return 0;
}
