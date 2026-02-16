# CPP Module 01

## Overview
This module focuses on memory allocation, pointers, references, and the switch statement. It covers the fundamentals of memory management in C++.

## Exercises

### Ex00: BraiiiiiiinnnzzzZ
Introduction to heap vs. stack allocation using a Zombie class.

**Key Concepts:**
- Stack vs. heap allocation
- `new` and `delete` operators
- Object lifecycle and scope
- Constructor and destructor behavior

**Functions:**
- `newZombie(std::string name)` - Creates a zombie on the heap
- `randomChump(std::string name)` - Creates a zombie on the stack

**Compilation:**
```bash
make
```

---

### Ex01: Moar brainz!
Creating multiple zombies using dynamic array allocation.

**Key Concepts:**
- Array allocation with `new[]`
- Array deallocation with `delete[]`
- Initializing multiple objects
- Memory management for arrays

**Functions:**
- `zombieHorde(int N, std::string name)` - Creates N zombies with the same name

**Compilation:**
```bash
make
```

---

### Ex02: HI THIS IS BRAIN
Understanding the relationship between pointers and references.

**Key Concepts:**
- Pointers vs. references
- Memory addresses
- Dereferencing pointers
- Reference initialization

**Demonstrates:**
- Printing memory addresses of variables
- Using pointers to access string values
- Using references to access string values

**Compilation:**
```bash
make
```

---

### Ex03: Unnecessary violence
A simple combat system with `Weapon` and `HumanA`/`HumanB` classes.

**Key Concepts:**
- References as class members
- Pointers as class members
- When to use references vs. pointers
- Object composition

**Classes:**
- `Weapon` - Has a type (string)
- `HumanA` - Always has a weapon (reference)
- `HumanB` - May not always have a weapon (pointer)

**Compilation:**
```bash
make
```

---

### Ex04: Sed is for losers
A simple file content replacement program (like sed).

**Key Concepts:**
- File I/O operations (`std::ifstream`, `std::ofstream`)
- String manipulation and replacement
- Error handling for file operations
- Command-line argument parsing

**Usage:**
```bash
./replace <filename> <string_to_replace> <replacement_string>
```

**Compilation:**
```bash
make
```

---

### Ex05: Harl 2.0
A complaining system using pointers to member functions.

**Key Concepts:**
- Pointers to member functions
- Array of function pointers
- Avoiding long if/else chains
- Method dispatch

**Levels:**
- DEBUG
- INFO
- WARNING
- ERROR

**Compilation:**
```bash
make
```

---

### Ex06: Harl filter
Extension of Ex05 using switch statements to filter complaint levels.

**Key Concepts:**
- Switch statement with fall-through
- Filtering output based on severity
- Command-line argument handling

**Usage:**
```bash
./harlFilter <level>
# Displays messages from specified level and above
```

**Compilation:**
```bash
make
```

## Learning Objectives
- Master memory allocation and deallocation
- Understand the difference between pointers and references
- Learn when to use stack vs. heap allocation
- Practice file I/O operations
- Implement function pointers and member function pointers
