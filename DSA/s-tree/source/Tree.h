#pragma once
#include <string>
/**
 * @brief Binary Tree implementation, case study
 * @author David Giraldo
 * @version 2024-07-15
 */
template <typename T>
class Tree
{
public:
    /**
     * @note [C.48:](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c48-prefer-default-member-initializers-to-member-initializers-in-constructors-for-constant-initializers) Prefer default member initializers to member initializers in constructors for constant initializers
     */
    Tree() = default;
    Tree(const Tree &other);
    ~Tree();
    /**
     * @brief Test for presence
     * @return True if element is found
     * @attention Iterative
     * @note Complexity O(n)
     */
    bool search(const T &elem) const;
    /**
     * @brief Add an element to the tree, duplicated not allowed
     * @return True if it is a new element and nsertion is succesful, otherwize false
     * @attention Iterative
     * @note Complexity O(n)
     */
    bool insert(const T &elem);
    /**
     * The number of elements in the tree. (counting the root?)
     *  @note Complexity O(n)
     */
    int size() const;
    /**
     * @brief The height of the empty tree is
       [often undefined](https://web.archive.org/web/20181013022358/https://xlinux.nist.gov/dads/HTML/height.html),
       but we decide that it is 0 (because we need it to be something). Another
       common choice is -1, to differentiate between the empty tree and the
       root-only tree.
     * @attention Recursively
     * @note Complexity O(n)
     */
    int height() const;
    /**
     * @brief the number of leaves in the tree.
     * @note O(n)
     * @attention Recursively
     */
    int leaves() const;
    /**
     * @brief a string describing the tree.
     * @attention The string should represent the tree in ascending order, like a sorted
      list. E.g, a tree with elements `1`, `54` and `-3` should be represented
      as `[-3, 1, 54]`
      @note Choose the most appropriate traversal technique out of in-, pre- and
      post-order.
     */
    std::string toString() const;

private:
    struct TreeNode
    {
        T data = nullptr;
        TreeNode *rightNode = nullptr;
        TreeNode *leftNode = nullptr;
        TreeNode(const T &dataRef) : data(dataRef) {};
        TreeNode(const TreeNode &otherTreeNode)
        {
            data = otherTreeNode.element;
            rightNode = otherTreeNode.rightNode;
            leftNode = otherTreeNode.leftNode;
        }
        ~TreeNode()
        {
            delete rightNode;
            delete leftNode;
        }
    };
    /**
     * @note This is owning pointer member, A class with an owner<T> should define its default operations. [C.33](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c33-if-a-class-has-an-owning-pointer-member-define-a-destructor)
     */
    TreeNode *m_root = nullptr;
    int m_size = -1;
};

// template <typename T>
// Tree<T>::Tree()
// {
//     std::cout << "Hello empty tree \n";
// }
template <typename T>
Tree<T>::Tree(const Tree &other)
{
}

template <typename T>
Tree<T>::~Tree()
{
    delete m_root;
    std::cout << "Bye tree \n";
}

// TODO Member functions

template <typename T>
bool Tree<T>::search(const T &elem) const
{
    return true;
}

template <typename T>
bool Tree<T>::insert(const T &elem)
{
    return true;
}

template <typename T>
int Tree<T>::height() const
{
    return m_size;
}

template <typename T>
int Tree<T>::leaves() const
{
    return m_size;
}

template <typename T>
int Tree<T>::size() const
{
    return m_size;
}

template <typename T>
std::string Tree<T>::toString() const
{
    return "Hello";
}