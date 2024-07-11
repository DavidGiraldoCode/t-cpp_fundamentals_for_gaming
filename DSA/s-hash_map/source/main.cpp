// g++ -std=c++20 *.cpp -o myProgram && ./myProgram
#include <iostream>
#include "HashSet.h"

void testingForString()
{
    // HashSet<std::string> hashSetStrings = HashSet<std::string>(5);
    HashSet<std::hash<std::string>, std::string> hashSetStrings = HashSet<std::hash<std::string>, std::string>(5);
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
    // HashSet<char> hashSetChars = HashSet<char>(5);
    HashSet<std::hash<char>, char> hashSetChars = HashSet<std::hash<char>, char>(5);
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

struct Person
{
    int m_age;
    std::string m_name;
    Person() : m_age(0), m_name("") {};
    Person(int age, const std::string &name)
    {
        m_age = age;
        m_name = name;
    };
    Person(const Person &other)
    {
        m_age = other.m_age;
        m_name = other.m_name;
    };
    ~Person() {};
    bool operator==(const Person &other) const
    {
        return m_name == other.m_name && m_age == other.m_age;
    }
};

std::ostream &operator<<(std::ostream &s, const Person &p)
{
    s << p.m_name << " - " << p.m_age << '\n';
    return s;
}

struct HashPerson
{
    size_t operator()(const Person &person) const noexcept
    {
        return std::hash<std::string>()(person.m_name);
    }
};

void testingForUserTypes()
{
    Person p = Person(50, "David");
    Person p2 = Person(41, "Pedro");
    Person p3 = Person(90, "Juan");
    Person p4 = Person(15, "David");
    std::cout << p << '\n';
    HashSet<HashPerson, Person> hashSetPeople = HashSet<HashPerson, Person>(5);
    // std::cout << "Test presence of: " << p << " -> " << hashSetPeople.contains(p) << '\n';
    hashSetPeople.add(p);
    hashSetPeople.add(p2);
    // std::cout << "Test presence of: " << p3 << " -> " << hashSetPeople.contains(p3) << '\n';
    hashSetPeople.add(p3);
    hashSetPeople.add(p4);
    // std::cout << "Test presence of: " << p3 << " -> " << hashSetPeople.contains(p3) << '\n';
    hashSetPeople.remove(p2);
    hashSetPeople.remove(p4);
}

int main(int argc, char *argv[])
{
    // testingForString();
    // testingForChars();
    testingForUserTypes();
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