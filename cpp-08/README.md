# CPP Module 08

## Overview
This module focuses on templated containers, iterators, and algorithms from the Standard Template Library (STL). Learn to work with standard containers and create your own templated containers.

## Exercises

### Ex00: Easy find
A template function to search for elements in containers.

**Key Concepts:**
- STL algorithms (std::find)
- Container iterators
- Template function with container types
- Exception throwing on failure
- Iterator usage

**Template Function:**
```cpp
template<typename T>
typename T::iterator easyfind(T& container, int value);
```

**Features:**
- Works with any container type (vector, list, deque, etc.)
- Uses std::find algorithm
- Throws exception if element not found
- Returns iterator to found element

**Compilation:**
```bash
make
```

**Usage:**
```cpp
std::vector<int> vec;
vec.push_back(1);
vec.push_back(2);
vec.push_back(3);

try {
    std::vector<int>::iterator it = easyfind(vec, 2);
    std::cout << "Found: " << *it;
} catch (std::exception& e) {
    std::cout << "Not found";
}
```

---

### Ex01: Span
A class that stores integers and calculates span statistics.

**Key Concepts:**
- Container management
- Range insertion
- Exception handling
- Algorithm usage (min_element, max_element)
- Vector operations

**Class:**
```cpp
class Span {
public:
    Span(unsigned int n);             // Constructor with max size
    void addNumber(int number);       // Add single number
    int shortestSpan();               // Find shortest span
    int longestSpan();                // Find longest span
    
    // Range insertion (bonus)
    template<typename Iterator>
    void addRange(Iterator begin, Iterator end);
};
```

**Exceptions:**
- Throws when trying to add beyond capacity
- Throws when span calculation impossible (< 2 elements)

**Features:**
- Store up to N integers
- Find shortest distance between any two numbers
- Find longest distance between any two numbers
- Efficient range-based insertion

**Compilation:**
```bash
make
```

**Usage:**
```cpp
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);

std::cout << sp.shortestSpan();  // 2 (between 9 and 11)
std::cout << sp.longestSpan();   // 14 (between 3 and 17)

// Range insertion
std::vector<int> vec(10000, 42);
sp.addRange(vec.begin(), vec.end());
```

---

### Ex02: Mutated abomination
A stack with iterator support by inheriting from std::stack.

**Key Concepts:**
- Adapter pattern
- Inheriting from STL containers
- Adding iterator support to stack
- Template inheritance
- Exposing underlying container

**Template Class:**
```cpp
template<typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    
    iterator begin();
    iterator end();
    // Const versions too
};
```

**Features:**
- All std::stack operations (push, pop, top, etc.)
- Iterator support (begin, end)
- Can be used with range-based for loops
- Maintains stack LIFO behavior

**Compilation:**
```bash
make
```

**Usage:**
```cpp
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
mstack.push(3);

// Iterate through stack
for (MutantStack<int>::iterator it = mstack.begin(); 
     it != mstack.end(); ++it) {
    std::cout << *it << std::endl;
}

// Range-based for loop (C++11)
for (int value : mstack) {
    std::cout << value << std::endl;
}
```

## STL Containers Used

| Container | Usage | Characteristics |
|-----------|-------|-----------------|
| std::vector | Ex00, Ex01 | Dynamic array, random access |
| std::list | Ex00 | Doubly-linked list |
| std::deque | Ex00 | Double-ended queue |
| std::stack | Ex02 | LIFO adapter |

## Common STL Algorithms

- `std::find` - Search for element
- `std::min_element` - Find minimum
- `std::max_element` - Find maximum
- `std::distance` - Calculate iterator distance

## Learning Objectives
- Master STL container usage
- Understand iterators and their categories
- Use STL algorithms effectively
- Create custom templated containers
- Practice exception safety with containers
- Implement adapter pattern
- Work with container inheritance
- Optimize container operations
- Use range-based operations efficiently
