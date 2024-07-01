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

int postfixCompute(const std::string &expression)
{
    /**
     * 1. Parse the expression symbol by symbol from left to right.
     * 2. As soon as you see an operand,
     *  2.1 check if the i+1 position is empty
     *  2.2 (cast to int) push it to the stack.
     * 3. As soon as you see an operator, pop two operands from the stack,
     *  3.1 apply the operator to them, and push the result of the operation to the stack.
     *
     */
    StackList<int> operands = LinkedList<int>();
    std::string operand = "";
    int sign = 1;
    for (size_t i = 0; i < expression.size(); i++)
    {
        switch (expression[i])
        {
        case '/':
        case '*':
        case '+':
        case '-':
            // Check if the operator IS the sign of a number, eg. '-' -> "-4"
            if ((i + 1) < expression.size())
                sign = expression[i + 1] != ' ' ? -1 : 1;

            // Check if the operator is NOT the sign of a number, eg. '-' -> "-4"
            if ((i + 1) == expression.size() || expression[i + 1] == ' ')
            {
                int operandB = operands.pop();
                //std::cout << operandB << " poped \n";
                int operandA = operands.pop();
                //std::cout << operandA << " poped \n";
                int result = 0;

                if (expression[i] == '-')
                    result = operandA - operandB;
                else if (expression[i] == '+')
                    result = operandA + operandB;
                else if (expression[i] == '/')
                    result = operandA / operandB;
                else
                    result = operandA * operandB;

                operands.push(result);
                //std::cout << operands.top() << " pushed \n";
            }

        case ' ':
            break;
        default:
            operand += expression[i];
            // Check if the digit is the last of the full number e.g '2' in '102'
            if ((i + 1) < expression.size() && expression[i + 1] == ' ')
            {
                int castedOperand = std::stoi(operand) * sign;
                sign = sign == -1 ? 1 : 1;
                operands.push(castedOperand);
                //std::cout << operands.top() << " pushed \n";
                operand = "";
            }
            break;
        }
    }
    return operands.top();
}
void postfixTest()
{
    std::string expressionA = "1 2 3 4 -0 + * - +";
    int expectedA = -9;

    std::string expressionB = "1 23 + -432 +";
    int expectedB = 1 + 23 + -432;

    std::string expressionC = "342 5 /";
    int expectedC = 342 / 5;

    std::string expressionD = "12 34 - 56 -78 + *";
    int expectedD = (12 - 34) * (56 + -78);

    std::string expressionE = "32 5 + 2 / 3 -";
    int expectedE = (32 + 5) / 2 - 3;

    std::string expressionF = "-3 2 + 3 * 4 - 5 /";
    int expectedF = (((-3 + 2) * 3) - 4) / 5;

    std::vector<std::string> expressions = {expressionA, expressionB, expressionC, expressionD, expressionE, expressionF};
    std::vector<int> expectations = {expectedA, expectedB, expectedC, expectedD, expectedE, expectedF};

    for (size_t i = 0; i < expressions.size(); i++)
    {
        std::cout << "For Expression: " << expressions[i] << " return: " << postfixCompute(expressions[i]) << " Expected: " << expectations[i] << ", Valid?: " << (postfixCompute(expressions[i]) == expectations[i]) << "\n";
    }
}

int main(int argc, char *agrv[])
{
    // std::vector<std::string> test_cases = {"(]", "()[]{}", "()", "[])", "((", "["};
    // for (size_t i = 0; i < test_cases.size(); i++)
    // {
    //     std::cout << "Test case " << i << ": \n"
    //               << isValid(test_cases[i]) << "\n";
    // }
    //std::string expressionB = "-3 2 + 3 * 4 - 5 /";
    //std::cout << "Compute: \n" << postfixCompute(expressionB) << "\n";
    postfixTest();

    return 0;
}