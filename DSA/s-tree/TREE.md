# Tree - Abstract Data Structure

## Copy constructor!
Without a copy constructor, containers such as `std::vector<T>` will call the default constuctor.
```C++
Warrior::Warrior(const Warrior &other)
{
    m_type = other.getType();
    m_level = other.getLevel();
}
```