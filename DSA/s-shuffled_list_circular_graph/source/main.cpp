// g++ -std=c++20 main.cpp -o myProgram && ./myProgram
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <list>
#include <string>

using std::cout;
using std::string;
using std::vector;

/// @brief Creates a list containing the of distances the player will travel, in this case 3, due to the shape of the hexagon.
/// And populates the list with negative and positive values representing left and right respectively.
/// @param visitCount how many times each distance is going to be visited
void createList(int visitCount, vector<int> &list)
{
    // cout << "create list!\n";
    int list_size = visitCount * 3 * 2; // 3 distances (small, medium, large), 2 direction (Left, Right)
    int half = int(list_size * 0.5f);

    for (size_t i = 0; i < list_size; i++)
    {
        int value = (1 + (i % 3)) * (i < half ? -1 : 1);
        list.push_back(value);
        // cout << list[i] << '\n';
    }
}

/// @brief Shuffles the vector
/// @param list
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
        record[list[i]]++;
    }
    cout << "-3 Count: " << record[-3] << "\n";
    cout << "-2 Count: " << record[-2] << "\n";
    cout << "-1 Count: " << record[-1] << "\n";
    cout << "1 Count: " << record[1] << "\n";
    cout << "2 Count: " << record[2] << "\n";
    cout << "3 Count: " << record[3] << "\n";
}

enum color
{
    red,
    blue,
    yellow,
    orange,
    green,
    purple
};

const std::unordered_map<color, std::string> colorToStringMap = {
    {red, "red"},
    {blue, "blue"},
    {yellow, "yellow"},
    {orange, "orange"},
    {green, "green"},
    {purple, "purple"}};

class CycleGraph
{
public:
    int m_vertices;
    vector<std::pair<int, int>> adjacency_list;

    CycleGraph() = default;
    CycleGraph(int vertices)
    {
        adjacency_list = vector<std::pair<int, int>>();
        m_vertices = vertices;

        for (size_t i = 0; i < m_vertices; i++)
        {
            int leftNode = ((m_vertices - 1) + i) % m_vertices;
            int rightNode = (i + 1) % m_vertices;
            std::pair<int, int> tuple = {leftNode, rightNode};

            adjacency_list.emplace_back(tuple);

            cout << "node: " << i << " left: " << adjacency_list[i].first << " right: " << adjacency_list[i].second << "\n";
        }
    };

    ~CycleGraph() = default;
};

void printColor(color c)
{
    auto col = colorToStringMap.find(c);
    if (col != colorToStringMap.end())
        cout << "Color: " << col->second << '\n';
}

void setTeleportDestination(int destination, color currentNode, CycleGraph &graph)
{
    cout << "Start at ";
    printColor(currentNode);

    int steps = abs(destination);
    int nextNode = 0;
    bool right = destination > 0; // true (1) right .second
    int j = 1;

    cout << "steps: " << steps << '\n';

    while (j <= steps)
    {
        cout << " Teleports ";

        if (!right)
        {
            cout << "left ";
            nextNode = graph.adjacency_list[currentNode].first;
        }
        else
        {
            cout << "right ";
            nextNode = graph.adjacency_list[currentNode].second;
        }

        currentNode = (color)nextNode;
        j++;

        cout << " to ";
        printColor((color)currentNode);
    }
    cout << " | ends at ------------------------- ";
    printColor((color)nextNode);
}

int main(int argc, char *argv[])
{

    vector<int> list = {};
    createList(1, list);
    shuffleList(list);
    shuffleList(list);

    CycleGraph graph = CycleGraph(6);
    color currentNode = red;

    for (size_t i = 0; i < list.size(); i++)
    {
        setTeleportDestination(list[i], currentNode, graph);
    }

    return 0;
}

/*
\

    // struct Node
    // {
    //     color nodeColor;
    //     vector<Node> adjacency_list;
    //     Node(color colorType) : nodeColor(colorType), adjacency_list(vector<Node>()) {};
    //     //Node() = default;
    //     ~Node() = default;
    // };
void populateCycleGraph(CycleGraph &graph)
{
    //graph = CycleGraph();
    //graph.addNode(red);
    //graph.addNode(blue);
    // graph.addNode(yellow);
    // graph.addNode(green);
    // graph.addNode(orange);
    // graph.addNode(purple);
}


    // const int getSize() const
    // {
    //     return m_vertices;
    // }

    // void add(int number)
    // {
    //     int left, right;

    //     int touple[] = { adjacency_list.size(), number };

    //     adjacency_list.push_back(touple);
    // }

    // void addNode(color colorName)
    // {
    //     Node node = Node(colorName);
    //     if (m_vertices == 0)
    //     {
    //         nodes.push_back(node);
    //         nodes.front().adjacency_list.push_back(nodes.front());
    //         nodes.front().adjacency_list.push_back(nodes.front());
    //         // nodes.begin()->adjacency_lits[1] = nodes.front();
    //         // cout << nodes.front().adjacency_list << '\n';
    //         //  nodes.front().adjacency_list[0]; = nodes.front(); // n' <- n
    //         // nodes.front().adjacency_lits[1] = nodes.front(); // n -> n'
    //     }
    //     else
    //     {
    //         //nodes.back().adjacency_list[1] = node;
    //         node.adjacency_list.push_back(nodes.front()); // Add the last node first so once we add the second, this stays to the left.
    //         node.adjacency_list.push_back(nodes.back()); // Add the starting node to the right

    //         nodes.push_back(node);

    //         //cout << colorToStringMap.find(nodes.back().adjacency_list[0].nodeColor)->second << '\n';

    //         Node left = nodes.back().adjacency_list[0];
    //         //left.adjacency_list[0] = nodes.back();
    //         Node right = nodes.back().adjacency_list[1];
    //         //right.adjacency_list[1] = nodes.front();

    //         nodes.front().adjacency_list[0] = nodes.back();
    //     }

    //     m_vertices = nodes.size();
    // }

    // const void printCycleGraph()
    // {
    //     cout << m_vertices << " - m_vertices \n";

    //     int iterator = 0;
    //     Node n = nodes.front();
    //     while (iterator < m_vertices)
    //     {
    //         auto c = colorToStringMap.find(n.nodeColor);
    //         auto cl = colorToStringMap.find(n.adjacency_list[0].nodeColor);
    //         auto cr = colorToStringMap.find(n.adjacency_list[1].nodeColor);

    //         if (c != colorToStringMap.end() &&
    //             cl != colorToStringMap.end() &&
    //             cr != colorToStringMap.end())
    //             cout << cl->second << " <- left - " << c->second << " - right -> " << cr->second << '\n';

    //         n = n.adjacency_list[0];
    //         iterator++;
    //     }
    // }

private:
    // int m_vertices;
    // vector<int[2]> adjacency_list;
    //std::list<Node> nodes; //= std::list<Node>();
*/