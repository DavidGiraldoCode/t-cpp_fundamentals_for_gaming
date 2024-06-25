# Linked Lists

The Linked List, as the ADT List, is a group a linearly ordered elements. Eeach element holds a pointer to the next (and some times, to the previous) element on the list. The list holds a reference only to the first and to the last elements. These allow for intresting time and space complexities.

- _Singly Linked List:_ Each list element holds a pointer to the next element. The last (tail) points to null.
- _Doubly Linked List:_ Each list element holds a pointer to the next and previous element. The first (heads) point to null.

```mermaid
graph LR
    LinkedList --> A
    A[Head] --> B[Element]
    B --> C[Tail]
    C --> D[null]
    B --> A
    C --> B
    A --> D[null]
```

## Operations and time complexity

### Adding and Removing elements at the head and tail of a LinkedList
- Time complexity is $$O(1)$$, constant. Because the it only needs to update one reference.
- BUT, inserting or deleting elements at any position that is **NOT** the head nor the tail has the same time complexity as the array, $$O(n)$$, linear, because it needs to traverse the list from the head to the specified index and then, update the references.
- Moreover, each `ListElement` is **NOT** linearly allocated in memory.

### Getting references at head and tail
- Time complexity is $$O(1)$$, constant. Because the list has a pointer to the Head and Tail at all times.
- Getting something at an index $$i$$ has a complexity of $$O(n)$$, because you need to traverse the list.

### Clear and Destroy the Linked List
- In the worst case, with the List full of elements, the time complexity is linear $$O(n)$$ because it needs to traverse and delete every single element.

# C++ considerations and code assesment

## Templates `template <typename T>`
The Linked List needs to contain any possible type of element. Therefore, it implementation in C++ needs templates. And there are some considerations:
1. The _header_ file needs to have both the declaration and the implementation of the methods. Meaning, no `.cpp` file is needed.
2. Adding elements mean to pass in constant references `const T &node`, NOT copies.
3. Returning elements mean to pass refences `T&`.
4. Deleting elements and returning the removed element, mean to return a COPY `T`, not a reference, because the original has been deallocated.

## 1. Memory leak in ~Destructor

_Initial approach_

```C++
LinkedList<T>::~LinkedList()
{
    delete first;
    delete last;
}
```

_mistakes_

- If the list is not empty, forgeting to traverse the list deallocating the ListElements leads to memory leaks

_implomement_

- Check is the `fist` element is not `nullptr`, and traverse the list deallocating memory.
- Set `next` and `previous` to `nullptr` on the `~ListElement()`.
- This process is $$O(n)$$ time complexity, since it needs to traverse the entire list.

```C++
LinkedList<T>::~LinkedList()
{
    ListElement *current = first;
    while (current != nullptr)
    {
        ListElement *next = current->next;
        delete current;
        current = next;
    }
}
//Inside the class ListElement
~ListElement()
{
    next = nullptr;
    previous = nullptr;
    std::cout << "ListElement with element " << element << " destroyed\n";
}
```

## 2. Setting head and tail references when removing

_Original approach_

```C++
T LinkedList<T>::removeFirst()
{
    if (m_size == 0)
        throw std::logic_error{"The list is empty, nothing to remove"};
    ListElement *temp = first->next;
    temp->previous = nullptr;
    T removedElement = first->element;
    delete first;
    first = temp;
    m_size--;
    return removedElement;
}

T LinkedList<T>::removeLast()
{
    if (m_size == 0)
        throw std::logic_error{"The list is empty, nothing to remove"};
    ListElement *temp = last->previous;
    temp->next = nullptr;
    T removedElement = last->element;
    delete last;
    last = temp;
    m_size--;
    return removedElement;
}
```

_mistakes_

- These methods don't handle the case where there is only one `m_size = 0` element in the list correctly. In such case, `temp` will be set to `nullptr`. Having no `->next` reference, since it is not a `ListElement`. Eventually leading to a `segmentation fault`.

_implomement_

- Declare an invariance statement to check when there is only one element.
- This process is $$O(1)$$ time complexity
```C++
T LinkedList<T>::removeFirst()
{
    if (m_size == 0)
        throw std::logic_error{"The list is empty, nothing to remove"};

    T removedElement = first->element;
    if (m_size == 1)
    {
        delete first;
        first = nullptr;
        last = nullptr;
    }
    else
    {
        ListElement *temp = first->next;
        temp->previous = nullptr;
        delete first;
        first = temp;
    }

    m_size--;
    return removedElement;
}
```
## 3. Clearing the List does not need to decrease the m_size
_Original Approach_
```C++
void LinkedList<T>::clear()
{
    if (m_size == 0)
        throw std::logic_error{"The list is already empty"};
    ListElement *node = first;
    while (node != nullptr)
    {
        ListElement *temp = node->next;
        delete node;
        node = temp;
        m_size--;
    }
    first = nullptr;
    last = nullptr;
    m_size = 0;
}
```
_mistakes_
- Decreasing operation `m_size--` is unecesarry and could lead to unwanted behavior. Seeting `m_size = 0` is enogh.

## 4. `cosnt` correctness considerations
_Original approach_
```C++
T &get(const size_t target) const;
T &getFirst() const;
T &LinkedList<T>::getLast() const
{
    if (m_size == 0)
        throw std::logic_error{"The list is empty, nothing to retrieve"};
    else
        return last->element;
}
```
_considerations_
- All three method are designed to return a **reference** to the `ListElement->element` at that position, so an external action can modify it, and `const` cannot prevent it. `const` can only prevent the method to internally modify the class. Example:
```C++
T &LinkedList<T>::getFirst() const
{
    first = 0; // <------------ intent to modify memeber
    if (m_size == 0)
        throw std::logic_error{"The list is empty, nothing to retrieve"};
    else
        return first->element;
}
```
```bash
error: cannot assign to non-static data member within const member function 'getFirst'
    first = 0;
    ~~~~~ ^
```
- BUT, calling the `getFirst()` method and assing it to another value is completly possible `myLinkedList.getFirst() = 5;`.