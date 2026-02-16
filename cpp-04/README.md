# CPP Module 04

## Overview
This module focuses on subtype polymorphism, abstract classes, and interfaces in C++. Learn about virtual functions, dynamic binding, and proper object-oriented design.

## Exercises

### Ex00: Polymorphism
Introduction to virtual functions and runtime polymorphism.

**Key Concepts:**
- Virtual functions
- Dynamic binding (runtime polymorphism)
- Base class pointers to derived objects
- Virtual destructors
- Proper vs. improper polymorphism

**Classes:**
- `Animal` - Base class with virtual `makeSound()`
- `Dog` - Derived class implementing dog sound
- `Cat` - Derived class implementing cat sound
- `WrongAnimal` - Base class without virtual (demonstrates wrong approach)
- `WrongCat` - Shows static binding issues

**Compilation:**
```bash
make
```

**Key Demonstration:**
```cpp
const Animal* dog = new Dog();
const Animal* cat = new Cat();
dog->makeSound();  // Outputs dog sound (dynamic binding)
cat->makeSound();  // Outputs cat sound (dynamic binding)

const WrongAnimal* wrong = new WrongCat();
wrong->makeSound();  // Outputs wrong animal sound (static binding)
```

---

### Ex01: I don't want to set the world on fire
Deep copy and object composition with nested objects.

**Key Concepts:**
- Object composition
- Deep copy vs. shallow copy
- Copy constructors with dynamically allocated members
- Memory management in complex objects
- Brain class containing ideas

**Classes:**
- `Animal` - Base class
- `Dog` - Has a `Brain*` member (deep copy required)
- `Cat` - Has a `Brain*` member (deep copy required)
- `Brain` - Contains 100 ideas (strings)

**Important:**
- Demonstrates why deep copy is necessary
- Proper cleanup in destructors
- Copy constructor implementation
- Assignment operator implementation

**Compilation:**
```bash
make
```

---

### Ex02: Abstract class
Making Animal an abstract class using pure virtual functions.

**Key Concepts:**
- Pure virtual functions (`= 0`)
- Abstract classes (cannot be instantiated)
- Forcing derived classes to implement specific methods
- Interface design
- Concrete vs. abstract classes

**Changes:**
- `Animal` becomes abstract with `virtual void makeSound() const = 0;`
- Cannot create Animal objects directly
- Must create Dog or Cat objects
- Enforces implementation in derived classes

**Compilation:**
```bash
make
```

**Key Points:**
```cpp
// This will NOT compile:
// Animal* animal = new Animal();  // Error: Animal is abstract

// This is correct:
Animal* dog = new Dog();
Animal* cat = new Cat();
```

## Class Hierarchy

```
      Animal (Abstract in Ex02)
       /    \
     Dog    Cat
      |      |
    Brain  Brain
```

## Learning Objectives
- Master virtual functions and polymorphism
- Understand dynamic vs. static binding
- Learn when and why to use virtual destructors
- Implement deep copy for objects with dynamic memory
- Create and use abstract classes
- Design interfaces using pure virtual functions
- Prevent object slicing
- Understand the virtual table (vtable) concept
