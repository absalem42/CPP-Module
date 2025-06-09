# C++ Programming Exercises

This repository contains a collection of C++ programming exercises, organized into modules. These exercises cover various fundamental and advanced concepts in C++.

Feel free to explore the different modules and their respective exercises.

## Table of Contents
- [Project Structure](#project-structure)
- [Module Overview](#module-overview)
  - [Module 00: Basics, Namespaces, Classes, and I/O Streams](#module-00-basics-namespaces-classes-and-io-streams)
  - [Module 01: Memory Allocation, Pointers, References, and File I/O](#module-01-memory-allocation-pointers-references-and-file-io)
  - [Module 02: Ad-hoc Polymorphism and Canonical Classes](#module-02-ad-hoc-polymorphism-and-canonical-classes)
  - [Module 03: Inheritance](#module-03-inheritance)
  - [Module 04: Subtype Polymorphism, Abstract Classes, and Interfaces](#module-04-subtype-polymorphism-abstract-classes-and-interfaces)
  - [Module 05: Exceptions and Advanced Class Design](#module-05-exceptions-and-advanced-class-design)
  - [Module 06: C++ Casts and Data Serialization](#module-06-c-casts-and-data-serialization)
  - [Module 07: C++ Templates](#module-07-c-templates)
  - [Module 08: Standard Template Library (STL) - Containers and Algorithms](#module-08-standard-template-library-stl---containers-and-algorithms)
  - [Module 09: Advanced STL Usage and Algorithms](#module-09-advanced-stl-usage-and-algorithms)
- [How to Compile and Run](#how-to-compile-and-run)

## Project Structure

The exercises are organized into modules, each contained within a directory named `cpp-XX`, where `XX` is the module number (e.g., `cpp-00`, `cpp-01`).

Inside each module directory, individual exercises are further divided into subdirectories named `exYY`, where `YY` is the exercise number (e.g., `ex00`, `ex01`).

Each exercise subdirectory typically contains:
- Source code files (e.g., `.cpp`, `.hpp`)
- A `Makefile` for compiling the exercise.

## Module Overview

This section provides a brief overview of the topics covered in each module.

### Module 00: Basics, Namespaces, Classes, and I/O Streams

*   **ex00: Megaphone:** A simple program to manipulate and display strings.
*   **ex01: My Awesome PhoneBook:** An exercise to create a basic phone book application, introducing concepts of classes, objects, and managing a collection of contacts.
*   **ex02: Accounts and Logs:** A program to simulate bank account operations, further exploring class design and member functions.

### Module 01: Memory Allocation, Pointers, References, and File I/O

*   **ex00: BraiiiiiiinnnzzzZ:** Introduces dynamic memory allocation (`new` and `delete`) with a `Zombie` class.
*   **ex01: Moar brainz!:** Expands on `ex00` by creating a "horde" of zombies, focusing on managing arrays of allocated objects.
*   **ex02: HI THIS IS BRAIN:** Illustrates the concepts of pointers, references, and the differences in how they store and access memory.
*   **ex03: Unnecessary violence:** Demonstrates the use of references and pointers in the context of interacting classes (`Weapon` and `Human`).
*   **ex04: Sed is for losers:** A program that reads from a file, replaces occurrences of one string with another, and writes the result to a new file, emphasizing string manipulation and file streams.
*   **ex05: Harl:** Implements a `Harl` character that complains at different levels, often used to introduce function pointers or switch/if-else-if chains for mapping strings to functions.
*   **ex06: Harl Filter:** Extends the Harl program from `ex05` to filter messages based on a minimum complaint level.

### Module 02: Ad-hoc Polymorphism and Canonical Classes

This module focuses on understanding and implementing classes in their canonical form and explores operator overloading.
*   **ex00: My First Class in Orthodox Canonical Form:** Introduces the concept of fixed-point numbers and requires the implementation of a `Fixed` class in the Orthodox Canonical Form (default constructor, copy constructor, copy assignment operator, destructor).
*   **ex01: Towards a more useful Fixed-Point Number class:** Extends the `Fixed` class by overloading the insertion (`<<`) operator for output and adding conversion functions to `float` and `int`.
*   **ex02: Now we’re talking:** Completes the `Fixed` class by overloading comparison operators (`>`, `<`, `>=`, `<=`, `==`, `!=`), arithmetic operators (`+`, `-`, `*`, `/`), and increment/decrement operators (`++pre/post`, `--pre/post`).

### Module 03: Inheritance

This module explores the concept of inheritance in C++.
*   **ex00: Aaaaand... OPEN!:** Introduces a base class `ClapTrap` with basic functionalities.
*   **ex01: Serena, My Love!:** Implements a `ScavTrap` class that inherits from `ClapTrap` and has its own specific abilities.
*   **ex02: Repetitive work:** Implements a `FragTrap` class, also inheriting from `ClapTrap`, showcasing further use of inheritance and potentially different functionalities.

### Module 04: Subtype Polymorphism, Abstract Classes, and Interfaces

This module delves into polymorphism, virtual functions, abstract base classes, and the concept of interfaces.
*   **ex00: Polymorphism:** Introduces virtual functions with an `Animal` base class and derived `Dog` and `Cat` classes. It also typically includes `WrongAnimal` and `WrongCat` to show the behavior without `virtual`.
*   **ex01: I don’t want to set the world on fire:** Extends the animal classes to include a `Brain` class, focusing on deep vs. shallow copy semantics when copying animal objects.
*   **ex02: Abstract class:** Modifies the `Animal` class to be an abstract base class, typically by declaring pure virtual functions, making it non-instantiable and forcing derived classes to provide implementations.

### Module 05: Exceptions and Advanced Class Design

This module covers C++ exception handling and explores more intricate class interactions, including the use of abstract classes for defining interfaces.
*   **ex00: Mommy, I’m a bureaucrat!:** Introduces a `Bureaucrat` class with a grade that must stay within a valid range (1-150). Custom exceptions are thrown if the grade goes too high or too low.
*   **ex01: Form up, maggots!:** Adds a `Form` class that `Bureaucrat`s can sign. This exercise focuses on interactions between classes and more exception handling (e.g., form already signed, grade too low to sign).
*   **ex02: No, you need form 28B, not 28C...:** The `Form` class becomes an abstract base class (`AForm`). Concrete forms (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`) inherit from `AForm` and implement an `execute` method. Bureaucrats can execute these forms if their grade is sufficient and the form is signed.
*   **ex03: The intern makes coffee:** Introduces an `Intern` class that can create instances of the different concrete form types based on a name string, returning a pointer to the abstract `AForm`.

### Module 06: C++ Casts and Data Serialization

This module explores different types of C++ casts and basic data serialization concepts.
*   **ex00: Convert:** Implements a static `ScalarConverter` class that takes a string literal representing a char, int, float, or double. It then attempts to convert this literal to all four scalar types, printing the results and handling impossible conversions or special values (e.g., `nan`, `inf`). This exercise heavily utilizes C++ casts.
*   **ex01: Serialization:** Introduces basic serialization by implementing a `Serializer` class with static methods to convert a pointer to a custom data structure to `uintptr_t` and back, typically using `reinterpret_cast`.
*   **ex02: Identify real type:** Focuses on runtime type identification. It involves a base class `Base` and derived classes `A`, `B`, and `C`. The goal is to write functions that can identify the actual instantiated type of an object when given a `Base*` or `Base&`, primarily using `dynamic_cast`.

### Module 07: C++ Templates

This module introduces C++ templates, allowing for generic programming.
*   **ex00: Whatever:** Implements simple template functions such as `swap`, `min`, and `max` that can operate on arguments of any type that supports the necessary comparison or assignment operations.
*   **ex01: Iter:** Features a template function `iter` that takes an array, its length, and a function. It applies the given function to each element of the array. This demonstrates how templates can be used for generic algorithms.
*   **ex02: Array:** Requires the creation of a class template `Array` that mimics the behavior of a standard array but is dynamically allocated. It must implement element access via the `[]` operator and handle out-of-bounds access by throwing an exception.

### Module 08: Standard Template Library (STL) - Containers and Algorithms

This module focuses on using the C++ Standard Template Library, particularly its containers, iterators, and algorithms.
*   **ex00: Easyfind:** Implements a template function `easyfind` that searches for a given integer value within various STL sequence containers (like `std::vector`, `std::deque`, `std::list`). It returns an iterator to the first occurrence or throws an exception if the value is not found.
*   **ex01: Span:** Involves creating a `Span` class capable of storing a predefined maximum number of integers. The class should support adding numbers individually or from a range of iterators and include methods to calculate the shortest and longest spans (differences) between any two numbers in its storage. This exercise encourages the use of STL algorithms.
*   **ex02: MutantStack:** Requires the creation of a `MutantStack` class. This class adapts an STL stack (or underlying container like `std::deque`) to provide iterator support, allowing users to iterate over the stack's elements, a feature not directly available in `std::stack`.

### Module 09: Advanced STL Usage and Algorithms

This module presents more complex challenges that require a good understanding of STL containers, algorithms, and data processing techniques.
*   **ex00: Bitcoin Exchange:** Implements a program to calculate the value of Bitcoin holdings on specific dates. It involves reading and parsing a CSV file of historical Bitcoin price data and processing an input file containing dates and values to multiply. This heavily uses STL containers like `std::map` for efficient data lookup and file stream operations.
*   **ex01: Reverse Polish Notation (RPN) Calculator:** Requires the creation of a calculator that evaluates expressions written in Reverse Polish Notation. This typically involves parsing the input string and using `std::stack` to perform the calculations.
*   **ex02: PmergeMe:** Implements the Ford-Johnson merge-insertion sort algorithm for two different STL containers (e.g., `std::vector` and `std::list` or `std::deque`). The exercise also involves comparing the performance of this custom sort against the standard `std::sort` (or list's sort method).

## How to Compile and Run

Each exercise within a module (e.g., `cpp-00/ex00/`) contains its own `Makefile`.

To compile an exercise:
1.  Navigate to the specific exercise directory:
    ```bash
    cd cpp-XX/exYY
    ```
    (Replace `XX` with the module number and `YY` with the exercise number).
2.  Run the `make` command:
    ```bash
    make
    ```
    This will typically produce an executable file in the same directory. The name of the executable may vary depending on the exercise (e.g., `megaphone`, `phonebook`, `fixed`, `animal`, etc.).

To run the compiled exercise:
1.  Execute the program from within its directory:
    ```bash
    ./<executable_name>
    ```
    (Replace `<executable_name>` with the actual name of the compiled program).

Some exercises might require specific command-line arguments. Refer to the exercise's subject or source code for such details.

To clean up compiled files:
```bash
make fclean
```
This command is generally available in the Makefiles to remove the executable and any object files.
