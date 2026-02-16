# CPP Module 07

## Overview
This module introduces C++ templates, one of the most powerful features of the language. Learn generic programming through function templates and class templates.

## Exercises

### Ex00: Start with a few functions
Basic function templates for common operations.

**Key Concepts:**
- Function template syntax
- Template parameter deduction
- Type-independent algorithms
- Generic programming basics

**Template Functions:**
```cpp
template<typename T>
void swap(T& a, T& b);

template<typename T>
T min(T const& a, T const& b);

template<typename T>
T max(T const& a, T const& b);
```

**Features:**
- Works with any comparable type
- Type deduction from arguments
- No explicit type specification needed

**Compilation:**
```bash
make
```

**Usage:**
```cpp
int a = 2, b = 3;
swap(a, b);              // a = 3, b = 2
std::cout << min(a, b);  // 2
std::cout << max(a, b);  // 3

std::string c = "chaine1", d = "chaine2";
swap(c, d);
std::cout << min(c, d);  // chaine1
std::cout << max(c, d);  // chaine2
```

---

### Ex01: Iter
A template function that applies a function to array elements.

**Key Concepts:**
- Template functions with function pointers
- Array iteration with templates
- Applying functions to containers
- Generic algorithms

**Template Function:**
```cpp
template<typename T, typename F>
void iter(T* array, size_t length, F function);
```

**Features:**
- Works with any array type
- Accepts function pointers
- Applies function to each element
- Type-safe iteration

**Compilation:**
```bash
make
```

**Usage:**
```cpp
int arr[] = {1, 2, 3, 4, 5};
iter(arr, 5, printElement);  // Prints each element

std::string strs[] = {"one", "two", "three"};
iter(strs, 3, printElement);  // Prints each string
```

---

### Ex02: Array
A template class implementing a dynamic array with safety features.

**Key Concepts:**
- Class templates
- Template member functions
- Dynamic memory management in templates
- Exception handling in templates
- Operator overloading in templates
- Copy semantics with templates

**Template Class:**
```cpp
template<typename T>
class Array {
public:
    Array();                           // Default constructor
    Array(unsigned int n);             // Constructor with size
    Array(Array const& src);           // Copy constructor
    ~Array();                          // Destructor
    Array& operator=(Array const& rhs); // Assignment operator
    T& operator[](unsigned int i);      // Subscript operator
    unsigned int size() const;          // Get size
};
```

**Features:**
- Dynamic allocation of elements
- Bounds checking with exception throwing
- Deep copy on copy construction
- Deep copy on assignment
- size() member function

**Exceptions:**
- Throws exception on out-of-bounds access

**Compilation:**
```bash
make
```

**Usage:**
```cpp
Array<int> numbers(10);
numbers[0] = 42;
std::cout << numbers[0];  // 42

try {
    numbers[100] = 1;  // Throws exception
} catch (std::exception& e) {
    std::cout << e.what();
}

Array<std::string> strings(5);
strings[0] = "Hello";
```

## Template Syntax Summary

**Function Template:**
```cpp
template<typename T>
T functionName(T param) {
    // Implementation
}
```

**Class Template:**
```cpp
template<typename T>
class ClassName {
    T member;
public:
    T getMember() const;
};

// Member function definition outside class
template<typename T>
T ClassName<T>::getMember() const {
    return member;
}
```

## Learning Objectives
- Master function template syntax and usage
- Understand template type deduction
- Create class templates with proper semantics
- Implement generic algorithms
- Handle exceptions in templates
- Apply RAII principles with templates
- Write type-independent code
- Understand template instantiation
- Practice const-correctness with templates
