# CPP Module 00

## Overview
Introduction to C++ basics, focusing on namespaces, classes, member functions, standard I/O streams, initialization lists, static, const, and basic object-oriented programming concepts.

## Exercises

### Ex00: Megaphone
A simple command-line program that converts all input arguments to uppercase.

**Key Concepts:**
- Command-line argument handling (`argc`, `argv`)
- Character manipulation with `toupper()`
- Basic C++ output with `std::cout`

**Compilation:**
```bash
make
```

**Usage:**
```bash
./megaphone "shhhhh... I think the students are asleep..."
./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
./megaphone
```

---

### Ex01: PhoneBook
An interactive phonebook application managing up to 8 contacts with ADD, SEARCH, and EXIT commands.

**Key Concepts:**
- Object-Oriented Programming (classes and encapsulation)
- Class design with `Contact` and `PhoneBook` classes
- User input handling and validation
- Data management with circular buffer behavior

**Features:**
- Store up to 8 contacts
- Each contact has: first name, last name, nickname, phone number, darkest secret
- Search functionality with formatted display
- Replaces oldest contact when full

**Compilation:**
```bash
make
```

**Usage:**
```bash
./phonebook
# Then use: ADD, SEARCH, EXIT commands
```

---

### Ex02: Account
A banking account system demonstrating static class members and object lifecycle tracking.

**Key Concepts:**
- Static member variables and methods
- Constructors and destructors
- Class-level data tracking across all instances
- Timestamp logging
- Deposit/withdrawal operations

**Features:**
- Track total number of accounts
- Track total deposits and withdrawals across all accounts
- Display account information with timestamps
- Automatic index assignment

**Compilation:**
```bash
make
```

**Usage:**
```bash
./account
# Runs predefined test suite
```

## Learning Objectives
- Understand C++ class structure and member functions
- Learn the difference between stack and heap allocation
- Master basic I/O operations in C++
- Implement encapsulation and data hiding
- Use static members for class-level functionality
