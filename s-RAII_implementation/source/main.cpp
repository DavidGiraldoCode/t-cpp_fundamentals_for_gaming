//g++ -std=c++20 main.cpp -o myProgram && ./myProgram
#include <iostream>

template <typename T> // Generics
// I define a template T, that can be change to whatever variable type we want
class DynamicArray //RAII Object
{
    size_t m_size;
    T * m_array; //Pointer to Heap memory allocation, type T.
public:
    DynamicArray(int size) //Constructor
        :m_size(size) //member initialization
        ,m_array(new T[size]) // new also assign zero automatically, no garbage values
    {
        std::cout << "DynamicArray Constructor\n";
    }
    ~DynamicArray() //Destructor
    {
        delete [] m_array;
        std::cout << "DynamicArray Destructor\n";
    }

    void print() const //Const correctness
    {
        for(size_t i = 0; i < m_size; i++)
        {
            std::cout << m_array[i] << "\n"; 
        }
    }

    T& get(size_t index) const //Const correctness
    {
        return m_array[index];
    }

    void set(size_t index, T newValue)
    {
        m_array[index] = newValue;
    }

    // Operator overloading implementation

    //Reads as: Return a the "Addres-of" a type T using [index]
    T & operator [] (size_t index)
    {
        return m_array[index];
    }
    /*
    Notice that if we declare a const DynamicArray, it won't
    be able to use the [] operator, it will yields

    << OUTPUT
    error: no viable overloaded operator[] for type 'const DynamicArray<T>'
    
    we need a const version of the same operator
    */
   //Reads as: Return a the "Addres-of" a constant type T using [index]
   const T& operator [] (size_t index) const
   {
        return m_array[index];
   }

};

int main (int argc, char * argv[])
{
    std::cout << "Ready \n";
    //<T> template argument.
    DynamicArray<float> myArray(5);
    const DynamicArray<int> myConstArray(5);

    std::cout << "\n Non-const Array \n";
    myArray.set(1, 18);
    myArray.set(4, 239);
    myArray[3] = 9;
    myArray[2] = 69;
    myArray.print();

    std::cout << "\n" << myArray.get(2) << "\n";
    std::cout << myArray[2] << "\n";

    std::cout << "\n Const Array \n";
    myConstArray.print();
    std::cout << "\n" << myConstArray.get(2) << "\n";
    std::cout << myConstArray[2] << "\n";
    // myConstArray[2] is using the const version of the [] operator

    return 0;
}