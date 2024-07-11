// g++ -std=c++20 *.cpp -o myProgram && ./myProgram
#include <iostream>
#include "HashSet.h"

struct Person
{
    std::string birthDay;
    int height;
};

// TODO
/**
 * Add unque intergers
 */

int main(int argc, char *argv[])
{
    /*
    HashSet<int> hashSet = HashSet<int>(10);
    const int recordA = 0;
    const int recordB = 0;
    const int recordC = 1;

    hashSet.add(recordC);
    hashSet.add(recordA);
    hashSet.add(recordB);
    */

    /*HashSet<char> hashSetChars = HashSet<char>(10);
     const char recordA = 'a';
     const char recordB = 'b';
     const char recordC = 'a';

     hashSetChars.add(recordA);
     hashSetChars.add(recordB);
     hashSetChars.add(recordC);*/
    //HashSet<int> hashSet = HashSet<int>(10);
    //HashSet<char> hashSetChars = HashSet<char>(10);
    HashSet<std::string> hashSetStrings = HashSet<std::string>(5);
    std::vector<std::string> records = {"David", "David", "Juan", "Jose", "Arturo", "Camilo", "Camila"};

    for (size_t i = 0; i < records.size(); i++)
    {
        hashSetStrings.add(records[i]);
    }
    std::cout << "Test presence of: " << records[0] << " -> " << hashSetStrings.contains(records[0]) << '\n';
    std::cout << "Test presence of: " << records[6] << " -> " << hashSetStrings.contains(records[6]) << '\n';
    std::cout << "Test presence of: " << records[2] << " -> " << hashSetStrings.contains(records[2]) << '\n';
    std::cout << "Test presence of: " << "Pedro" << " -> " << hashSetStrings.contains("Pedro") << '\n';
    // std::cout << "Remove test status: " << hashSetStrings.remove("David") << '\n';
    // std::cout << "Test presence of: " << records[0] << " -> " << hashSetStrings.contains(records[0]) << '\n';

    // HashSet<Person> personHashSet = HashSet<Person>(10);
    // const Person p1 {"1995-03-23", 173};
    // personHashSet.add(p1);

    return 0;
}

/*
//
    size_t INITIAL_SIZE = 5;
    int *arrayList = new int[INITIAL_SIZE];
    int array[5] = {0,0,0,0,0};

    std::cout << "Stack Array \n";
    for (size_t i = 0; i < INITIAL_SIZE; i++)
    {
        //arrayList[i] = (int)i;
        std::cout << array[i] << "\n";
    }

    std::cout << "Heap Array \n";
    for (size_t i = 0; i < INITIAL_SIZE; i++)
    {
        arrayList[i] = (int)i;
        std::cout << arrayList[i] << "\n";
    }

    arrayList[INITIAL_SIZE] = 9;
    std::cout << "\n" << arrayList[INITIAL_SIZE] << " new element \n";
    INITIAL_SIZE++;
     for (size_t i = 0; i < INITIAL_SIZE; i++)
    {
        std::cout << arrayList[i] << "\n";
    }


    delete[] arrayList;
*/