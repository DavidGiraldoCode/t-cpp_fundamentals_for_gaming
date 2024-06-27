# Linked Lists

The Linked List, as the ADT List, is a group of linearly ordered elements. Each element holds a pointer to the next (and sometimes, to the previous) element in the list. The list holds a reference only to the first and the last elements. These allow for interesting time and space complexities.

- _Singly Linked List:_ Each list element holds a pointer to the next element. The last (tail) points to null.
- _Doubly Linked List:_ Each list element holds a pointer to the next and previous element. The first (head) points to null.

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

## Operations and Time Complexity

### Adding and Removing Elements at the Head and Tail of a LinkedList
$$O(1)$$
- Time complexity is constant. It only needs to update one reference.
- BUT:
$$O(n)$$
- Inserting or deleting elements at any position that is **NOT** the head nor the tail has the same time complexity as the array, linear, because it needs to traverse the list from the head to the specified index and then update the references.
- Moreover, each `ListElement` is **NOT** linearly allocated in memory.

### Getting References at Head and Tail
$$O(1)$$
- Time complexity is constant. The list has a pointer to the head and tail at all times.
- Getting something at an index $$i$$ has a complexity of $$O(n)$$, because you need to traverse the list.

### Clear and Destroy the Linked List
$$O(n)$$
- In the worst case, with the list full of elements, the time complexity is linear because it needs to traverse and delete every single element.

# C++ Considerations and Code Assessment

## Templates `template <typename T>`
The Linked List needs to contain any possible type of element. Therefore, its implementation in C++ needs templates. There are some considerations:
1. The _header_ file needs to have both the declaration and the implementation of the methods. Meaning, no `.cpp` file is needed.
2. Adding elements means passing in constant references `const T &node`, NOT copies.
3. Returning elements means passing references `T&`.
4. Deleting elements and returning the removed element means returning a COPY `T`, not a reference, because the original has been deallocated.

## 1. Memory Leak in ~Destructor

_Initial Approach_

```C++
LinkedList<T>::~LinkedList()
{
    delete first;
    delete last;
}
```

_Mistakes_

- If the list is not empty, forgetting to traverse the list deallocating the ListElements leads to memory leaks.

_Implementation_

- Check if the `first` element is not `nullptr`, and traverse the list deallocating memory.
- Set `next` and `previous` to `nullptr` in the `~ListElement()`.
- This process has `O(n)` time complexity since it needs to traverse the entire list.

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
// Inside the class ListElement
~ListElement()
{
    next = nullptr;
    previous = nullptr;
    std::cout << "ListElement with element " << element << " destroyed\n";
}
```

## 2. Setting Head and Tail References When Removing

_Original Approach_

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

_Mistakes_

- These methods don't handle the case where there is only one element (`m_size = 1`) in the list correctly. In such cases, `temp` will be set to `nullptr`, having no `->next` reference, since it is not a `ListElement`, eventually leading to a `segmentation fault`.

_Implementation_

- Declare an invariance statement to check when there is only one element.
- This process has `O(1)` time complexity.

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

## 3. Clearing the List Does Not Need to Decrease the m_size

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

_Mistakes_
- Decreasing `m_size--` is unnecessary and could lead to unwanted behavior. Setting `m_size = 0` is enough.

## 4. `const` Correctness Considerations

_Original Approach_

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

_Considerations_
- All three methods are designed to return a **reference** to the `ListElement->element` at that position, so an external action can modify it, and `const` cannot prevent it. `const` can only prevent the method from internally modifying the class. Example:
```C++
T &LinkedList<T>::getFirst() const
{
    first = 0; // <------------ intent to modify member
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
- BUT, calling the `getFirst()` method and assigning it to another value is completely possible `myLinkedList.getFirst() = 5;`.