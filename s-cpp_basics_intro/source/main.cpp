#include <iostream>
#include <vector>
#include <fstream>
#pragma GCC diagnostic ignored "-Wc++11-extensions"

//using namespace std; //simplifies the writting

// On the terminal -> g++ -std=c++20 main.cpp
// g++ -std=c++20 main.cpp -o myProgram && ./myProgram

class Warrior
{
    std::string m_name  = "";
    int m_level         = 0;
    float m_damage      = 0.0f;
    bool m_isAlive      = true;

public:
    Warrior() {} //default constructor
    Warrior(std::string name, int level, float damage, bool alive)
        : m_name(name)
        , m_level(level)
        , m_damage(damage)
        , m_isAlive(alive)
    {
    }

    int getDamage() const
    {
        return m_damage;
    }

    std::string getName() const
    {
        return m_name;
    }

    bool getIsAlive() const
    {
        return m_isAlive;
    }

    void print() const //this function may change the object, so we need to declare it as const.
    {
        //m_name = "Juan"; <- this code wont work, because is trying to change the variables of the object in a const function
        std::cout << m_name << "\n";
        std::cout << " - Level: " << m_level << "\n";
        std::cout << " - Damage: " << m_damage << m_isAlive << "\n";
    }
};

class Quest
{
    std::string m_name = "Quest";
    std::vector<Warrior> m_warriors;

public:

    Quest() {}

    Quest(const std::string& name) //Always pass conts references of strigns
        : m_name(name)
    {

    }

    void addWarrior (const Warrior& w)
    {
        m_warriors.push_back(w);
    }    

    // first const means that what we return will not change
    // the "&" means that we are returning a reference
    // second const menas that the function does not mutates the class
    const std::vector<Warrior>& getWarriors() const
    {
        return m_warriors;
    }

    void loadFromFile(const std::string& filename)
    {
        std::ifstream finput(filename); //Class and constructor
        std::string temporal;
        std::string name;
        int level;
        float damage;
        bool alive;
        //tokens: strings separated by white space.
        std::cout << "loadFromFile" << "\n";
        //while (finput >> temporal)
        //{
           // std::cout << temporal << "\n";
        //}
        
        while(finput >> name)
        {
            finput >> level >> damage >> alive;
            addWarrior(Warrior(name, level,damage, alive));
        }


    }

    void print() const
    {
        std::cout << "Quest name: " << m_name << "\n";
        for (const auto& w : m_warriors)
        {
            w.print();
        }
    }
};



int main (int argc, char * argv[])
{

    Quest myQuest("Dragon treasure");
    myQuest.loadFromFile("./warriors.txt");
    myQuest.print();

    return 0;
}

/*
    Warrior w1;
    Warrior w2("David The Hunter", 100, 25.5, true);
    Warrior w4("Juan The Destroyer", 100, 25.5, true);

    //std::cout << w2.getName() << "\n";
    const Warrior w3("Leon", 200, 50.18, true);

    Quest myQuest("Dragon treasure");
    myQuest.addWarrior(w2);
    myQuest.addWarrior(w4);
    myQuest.addWarrior(Warrior("Will",80,40.3,true));

    myQuest.print();

    //w2.print();
    //w3.print();
*/