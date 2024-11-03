// g++ -std=c++20 main.cpp -o myProgram && ./myProgram
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using std::cout;
using std::vector;

/// @brief Creates a list of the size of the visitCount * the number of distances to travel, in this case 3, due to the shape of the hexagon
/// And populates the list with negative and positive values representing left and right respectively
/// @param visitCount
void createList(int visitCount, vector<int> &list)
{
    cout << "create list!\n";
    int list_size = visitCount * 3 * 2; // 3 distances (small, medium, large), 2 direction (Left, Right)
    int half = int(list_size * 0.5f);

    for (size_t i = 0; i < list_size; i++)
    {
        int value = (1 + (i % 3)) * (i < half ? -1 : 1);
        list.push_back(value);
        cout << list[i] << '\n';
    }
}

void shuffleList(vector<int> &list)
{
    cout << "shuffle!\n";

    int random = 0;

    int n = list.size();
    for (size_t i = 0; i < n; i++)
    {
        // cout << list[i] << "before swaping \n";
        int min = i;
        int max = n - 1;
        int random = int(min + ((max - min) * (std::rand() / (RAND_MAX + 1.0f))));
        int temp = list[i];
        list[i] = list[random];
        list[random] = temp;

        cout << list[i] << '\n';
    }
}

/// @brief This checks that the list has the same count of value [-3,-2,-1,1,2,3]
void testList(vector<int> &list)
{
    cout << "test!\n";
    std::unordered_map<int, int> record = {};

    for (size_t i = 0; i < list.size(); i++)
    {
        cout << list[i] << '\n';
        record[list[i]] ++;
    }
    cout << "-3 Count: " << record[-3] << "\n";
    cout << "-2 Count: " << record[-2] << "\n";
    cout << "-1 Count: " << record[-1] << "\n";
    cout << "1 Count: " << record[1] << "\n";
    cout << "2 Count: " << record[2] << "\n";
    cout << "3 Count: " << record[3] << "\n";
}

int main(int argc, char *argv[])
{
    std::cout << "All ready!\n";

    vector<int> list = {};
    createList(10, list);
    shuffleList(list);
    testList(list);

    return 0;
}