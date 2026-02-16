# C++ Modules (CPP 00-09)

A comprehensive collection of C++ programming exercises covering fundamental to advanced concepts. These modules are designed to build proficiency in C++98, progressing from basic syntax to advanced template programming and STL usage.

## 📚 Repository Structure

This repository contains 10 modules, each focusing on specific C++ concepts:

| Module | Topic | Key Concepts |
|--------|-------|--------------|
| [cpp-00](cpp-00/) | Basics | Namespaces, classes, member functions, I/O streams, initialization |
| [cpp-01](cpp-01/) | Memory & Pointers | Memory allocation, pointers, references, file I/O |
| [cpp-02](cpp-02/) | Operator Overloading | Orthodox Canonical Form, ad-hoc polymorphism, fixed-point numbers |
| [cpp-03](cpp-03/) | Inheritance | Class hierarchies, derived classes, access specifiers |
| [cpp-04](cpp-04/) | Polymorphism | Virtual functions, abstract classes, interfaces |
| [cpp-05](cpp-05/) | Exceptions | Exception handling, custom exceptions, try-catch blocks |
| [cpp-06](cpp-06/) | Type Casting | Static, dynamic, reinterpret, and const casts |
| [cpp-07](cpp-07/) | Templates | Function and class templates, generic programming |
| [cpp-08](cpp-08/) | STL Containers | Templated containers, iterators, algorithms |
| [cpp-09](cpp-09/) | Advanced STL | Real-world applications, algorithm implementation |

## 🎯 Learning Path

### Beginner (Modules 00-01)
Start with the fundamentals of C++ syntax, classes, and memory management.
- Basic I/O operations
- Object-oriented programming basics
- Memory allocation (stack vs. heap)
- Pointers and references

### Intermediate (Modules 02-05)
Dive into object-oriented design patterns and error handling.
- Operator overloading
- Inheritance and polymorphism
- Virtual functions and abstract classes
- Exception handling

### Advanced (Modules 06-09)
Master advanced C++ features and the Standard Template Library.
- Type conversions and casts
- Generic programming with templates
- STL containers and algorithms
- Performance optimization

## 🛠️ General Build Instructions

Each exercise contains a Makefile with standard targets:

```bash
# Compile the project
make

# Clean object files
make clean

# Clean everything (objects + executable)
make fclean

# Recompile from scratch
make re
```

## 📋 Requirements

- **Compiler:** c++ (clang++ or g++)
- **Standard:** C++98
- **Flags:** `-Wall -Wextra -Werror`
- **OS:** Linux/Unix/MacOS

## 🔍 Module Highlights

### CPP-00: My First Steps in C++
Learn the basics of C++ with practical exercises including a megaphone program, a phonebook application, and an account management system.

### CPP-01: Memory Allocation
Master dynamic memory allocation with zombies, understand pointers vs. references, and work with file streams.

### CPP-02: Fixed-Point Numbers
Implement a fixed-point number class with the Orthodox Canonical Form and comprehensive operator overloading.

### CPP-03: Inheritance Hierarchy
Build a game-like class hierarchy with ClapTrap, ScavTrap, and FragTrap demonstrating inheritance principles.

### CPP-04: Polymorphism in Action
Create polymorphic animal classes with virtual functions, deep copy mechanisms, and abstract base classes.

### CPP-05: Exception Safety
Design a bureaucrat and form system with custom exceptions, demonstrating proper error handling patterns.

### CPP-06: Type Conversion Mastery
Explore all four C++ cast types through scalar conversion, serialization, and runtime type identification.

### CPP-07: Template Power
Write generic code with function and class templates, including a custom template array class.

### CPP-08: STL Fundamentals
Work with standard containers and algorithms, creating custom templated containers like MutantStack.

### CPP-09: Real-World Applications
Apply STL knowledge to practical problems: Bitcoin exchange rates, RPN calculator, and merge-insertion sort.

## 📖 Documentation

Each module contains its own README.md with:
- Detailed exercise descriptions
- Key concepts and learning objectives
- Compilation and usage instructions
- Code examples and best practices

Navigate to any module directory to find specific documentation.

## 🚀 Quick Start

1. Clone the repository:
```bash
git clone https://github.com/absalem42/CPP-Module.git
cd CPP-Module
```

2. Navigate to a module:
```bash
cd cpp-00
```

3. Choose an exercise:
```bash
cd ex00
```

4. Build and run:
```bash
make
./megaphone "hello world"
```

## 📝 Coding Standards

All code follows these standards:
- C++98 standard compliance
- No STL usage before module 08 (except specific exercises)
- Proper memory management (no leaks)
- Orthodox Canonical Form for classes (where applicable)
- Compilation with `-Wall -Wextra -Werror`

## 🎓 Skills Developed

By completing these modules, you will master:
- ✅ Object-Oriented Programming (OOP) principles
- ✅ Memory management and RAII
- ✅ Operator overloading and type conversions
- ✅ Inheritance, polymorphism, and abstraction
- ✅ Exception handling and error safety
- ✅ Template metaprogramming
- ✅ STL containers, iterators, and algorithms
- ✅ Algorithm analysis and optimization
- ✅ Modern C++ best practices

## 🤝 Contributing

This is a learning project. Feel free to:
- Report issues
- Suggest improvements
- Share alternative implementations

## 📜 License

This project is part of the 42 School curriculum.

## 👤 Author

**absalem42**

---

*Each module builds upon previous knowledge, creating a comprehensive C++ learning journey from beginner to advanced levels.*
