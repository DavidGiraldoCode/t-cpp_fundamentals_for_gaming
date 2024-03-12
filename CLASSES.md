# Classes in C++

## Overview

`m_` at the begging of a variable is a convention to indicate that a given variable is a private member of the current class. Makes stop the private variables quickly.

```cpp
class SpaceShip
{
	int m_posX = 0; //Private visibility by default
	int m_posY = 0;
public: //Everything
	SpaceShip(int x, int y);
	int getPosX();
	int getPosY();
}
```

Class constructor

```cpp
SpaceShip::SpaceShip(int x, int y)
{
	m_posX = x;
	m_posY = y;
}

// Member initializer lists gives this variables the initial value
SpaceShip::SpaceShip(int x, int y)
	: m_posX(x)
	, m_posY(y)
{
	// Construction definition
}
```

Class destructor (when my object gets our of scope)

Using members initializer might trigger a warning if you are not using C++11

```cpp
class Warrior
{
    std::string m_name  = "";

public:
    Warrior() {} //default constructor
    Warrior(std::string name)
        : m_name(name)
    {
    }
}
```

```bash
/Users/davidmacbook/Documents/kth_code_workspace/t-cpp_fundamentals_for_gaming/s-cpp_basics_intro/source/main.cpp:10:25: warning: default member initializer for non-static data member is a C++11 extension [-Wc++11-extensions]
    std::string m_name  = "";
```

To disable this warnings, add this compiler flags on top of your program.

```cpp
#pragma GCC diagnostic ignored "-Wc++11-extensions"
```