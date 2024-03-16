// g++ -std=c++20 main.cpp -o myProgram && ./myProgram
#include <iostream>

void printPointer(const int & ref)
{
    std::cout << &ref << " value: " << ref << " bytes: "<< sizeof(ref)<<"\n";
}

int main( int argc, char * argv[])
{

    int a = 1;
    int b = 5;
    int * pa = &a; //An address that stores another address
    int * pb = &b; //An address that stores another address

    std::cout << "Ready \n";
    printPointer(a);
    printPointer(b);
    //printPointer(*pa);
    //printPointer(*pb);

    std::cout << "\n Modifity using * and & \n";
    *pa = 2; // Reads as: The value "at" pa assign 2;
    printPointer(*pa);

    *(&a) = 3; // Read as: The value "at" the "address-of" a assign 3;
    printPointer(*(&a));

    //
    std::cout << " \n Problems of using pointers wrong \n";
    printPointer(b);
    std::cout << "pa before pb-1: " << pa << " size: " << sizeof(pa) << "\n";
    *(pb-1) = 7; 
    /*
     Substracting -1 to the int, now points to the previous
     pointer pa, causing problems
    */
    printPointer(a); //Still accesible
    std::cout << "Address: " << pa << " size: " << sizeof(pa) <<"\n";
    printPointer(*pa); //The value "at" pa pointer is not accesible
    
    /*
    << OUTPUT
        0x16ee9ae88 value: 5 bytes: 4
        pa before pb-1: 0x16ee9ae8c size: 8
        0x16ee9ae8c value: 3 bytes: 4
        Address: 0x76ee9ae8c size: 8
        zsh: segmentation fault  ./myProgram
    */
    
    return 0;
}