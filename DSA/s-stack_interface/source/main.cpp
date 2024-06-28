// g++ -std=c++20 *.cpp -o myProgram && ./myProgram
#include <iostream>
#include "LinkedList.h"

// Define a type alias
template <typename T>
using StackList = LinkedList<T>;

bool isValid(std::string s)
{
    if (s.size() == 1)
        return false;

    std::unordered_map<char, char> brackets_couples{
        {'(', ')'},
        {'[', ']'},
        {'{', '}'}};
    StackList<char> open_brackets_stack = LinkedList<char>();
    
    if (brackets_couples.count(s[0]) == 0)
        return false;
    else
        open_brackets_stack.push(s[0]);

    for (size_t i = 1; i < s.size(); i++)
    {
        if (brackets_couples.count(s[i]) == 1)
        {
            open_brackets_stack.push(s[i]);
        }
        else
        {
            if (!open_brackets_stack.isEmpty())
            {
                if (brackets_couples[open_brackets_stack.top()] != s[i])
                    return false;
                else
                    open_brackets_stack.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (open_brackets_stack.isEmpty())
        return true;
    else
        return false;
}

int main(int argc, char *agrv[])
{
    std::vector<std::string> test_cases = {"(]", "()[]{}", "()", "[])", "((", "["};
    for (size_t i = 0; i < test_cases.size(); i++)
    {
        std::cout << "Test case " << i << ": \n"
                  << isValid(test_cases[i]) << "\n";
    }

    return 0;
}