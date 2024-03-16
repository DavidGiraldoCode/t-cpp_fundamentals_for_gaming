#include <iostream>
#include <memory>

void allocateStackVsHeapMemory() {
    // Stack memory allocation
    int stackVar = 10;
    // Heap memory allocation
    int* heapVar = new int;
    *heapVar = 20;
    std::cout << "Stack variable: " << stackVar << std::endl;
    std::cout << "Heap variable: " << *heapVar << std::endl;
    delete heapVar; // Deallocate heap memory
}

void pointersOverview() {
    int value = 42;
    int* ptr = &value; // Pointer holds address of 'value'
    *ptr = 50; // Modifies 'value' indirectly
}

void pointerExample() {
    int* ptr = new int; // Dynamic memory allocation
    *ptr = 10; // Value assignment
    delete ptr; // Memory deallocation
}

void initializationBestPractice() {
    int num = 0; // Initialize variables
    float pi = 3.14f;
}

void usingReferences() {
    int value = 100;
    int& ref = value; // Reference to 'value'
    ref = 200; // Modifies 'value' directly
}

void nullptrKeyword() {
    int* ptr = nullptr; // Use nullptr for null pointers
    if (ptr == nullptr) {
        std::cout << "Pointer is null" << std::endl;
    }
}

void sizeOfRawArrays() {
    int arr[5] = {1, 2, 3, 4, 5};
    size_t size = sizeof(arr) / sizeof(arr[0]); // Size of array
}

class MyClass {
    int* ptr = new int; // Heap memory allocation
};

void memoryLeak() {
    int* ptr = new int; // Dynamic memory allocation
    // Use ptr...
    delete ptr; // Memory deallocation
}

void smartPointers() {
    auto smartPtr = std::make_shared<int>(); // Smart pointer allocation
}

void inheritance() {
    class Base {
    public:
        int publicVar;
    protected:
        int protectedVar;
    private:
        int privateVar;
    };
    class Derived : public Base {
    // Inherits public and protected members from Base
    };
}

template <typename T>
void deepCopy(const T& source) {
    T copy = source; // Deep copy
}

int main() {
    allocateStackVsHeapMemory();
    pointersOverview();
    pointerExample();
    initializationBestPractice();
    usingReferences();
    nullptrKeyword();
    sizeOfRawArrays();
    memoryLeak();
    smartPointers();
    inheritance();
    deepCopy(10);
    return 0;
}
