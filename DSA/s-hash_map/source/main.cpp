// g++ -std=c++20 *.cpp -o myProgram && ./myProgram
#include <iostream>
#include "HashSet.h"

struct Person
{
    std::string birthDay;
    int height;
};

void testingForString()
{
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
    std::cout << "Test presence of: " << records[5] << " -> " << hashSetStrings.contains(records[5]) << '\n';
}
void testingForChars()
{
    HashSet<char> hashSetChars = HashSet<char>(5);
    std::vector<char> records = {'d', 'd', 'J', 'j', 'a', 'c', 'C', 'a', 'A'};

    for (size_t i = 0; i < records.size(); i++)
    {
        hashSetChars.add(records[i]);
    }
    std::cout << "Test presence of: " << records[0] << " -> " << hashSetChars.contains(records[0]) << '\n';
    std::cout << "Test presence of: " << records[6] << " -> " << hashSetChars.contains(records[6]) << '\n';
    std::cout << "Test presence of: " << records[2] << " -> " << hashSetChars.contains(records[2]) << '\n';
    std::cout << "Test presence of: " << 'P' << " -> " << hashSetChars.contains('P') << '\n';
    std::cout << "Test presence of: " << records[5] << " -> " << hashSetChars.contains(records[5]) << '\n';
}

int main(int argc, char *argv[])
{
    // HashSet<Person> personHashSet = HashSet<Person>(10);
    // const Person p1 {"1995-03-23", 173};
    // personHashSet.add(p1);
    testingForChars();
    testingForString();
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