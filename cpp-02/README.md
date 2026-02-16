# CPP Module 02

## Overview
This module introduces ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Form in C++. The focus is on fixed-point number representation and manipulation.

## Exercises

### Ex00: My First Class in Orthodox Canonical Form
Introduction to the Orthodox Canonical Form using a Fixed-point number class.

**Key Concepts:**
- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor
- Orthodox Canonical Form (OCF)
- Fixed-point arithmetic basics

**Class:**
- `Fixed` - Represents a fixed-point number with 8 fractional bits

**Compilation:**
```bash
make
```

---

### Ex01: Towards a more useful fixed-point number class
Extending the Fixed class with constructors, conversions, and output.

**Key Concepts:**
- Converting constructors (int and float)
- Type conversion member functions
- Overloading the insertion operator (`<<`)
- toInt() and toFloat() member functions
- Understanding fixed-point representation

**Enhancements:**
- Constructor from int
- Constructor from float
- Conversion to int
- Conversion to float
- Stream output operator

**Compilation:**
```bash
make
```

**Usage:**
```cpp
Fixed a;
Fixed const b(10);
Fixed const c(42.42f);
Fixed const d(b);

std::cout << a << std::endl;  // 0
std::cout << b << std::endl;  // 10
std::cout << c << std::endl;  // 42.4219
std::cout << d << std::endl;  // 10
```

---

### Ex02: Now we're talking
Complete Fixed class with comparison and arithmetic operators.

**Key Concepts:**
- Comparison operators: `>`, `<`, `>=`, `<=`, `==`, `!=`
- Arithmetic operators: `+`, `-`, `*`, `/`
- Increment/decrement operators: `++`, `--` (pre and post)
- Static member functions: `min()`, `max()`
- Operator overloading best practices

**Operators Implemented:**
- **Comparison:** `>`, `<`, `>=`, `<=`, `==`, `!=`
- **Arithmetic:** `+`, `-`, `*`, `/`
- **Increment/Decrement:** `++a`, `a++`, `--a`, `a--`

**Static Functions:**
- `Fixed::min(Fixed &a, Fixed &b)` - Returns the smaller value
- `Fixed::max(Fixed &a, Fixed &b)` - Returns the larger value
- Const overloads for both

**Compilation:**
```bash
make
```

**Usage:**
```cpp
Fixed a;
Fixed const b(Fixed(5.05f) * Fixed(2));

std::cout << a << std::endl;          // 0
std::cout << ++a << std::endl;        // 0.00390625
std::cout << a << std::endl;          // 0.00390625
std::cout << a++ << std::endl;        // 0.00390625
std::cout << a << std::endl;          // 0.0078125

std::cout << b << std::endl;          // 10.1016

std::cout << Fixed::max(a, b) << std::endl;  // 10.1016
```

## Learning Objectives
- Understand and implement Orthodox Canonical Form
- Master operator overloading in C++
- Learn fixed-point number representation
- Implement type conversion operators
- Practice const-correctness
- Understand ad-hoc polymorphism through operator overloading
