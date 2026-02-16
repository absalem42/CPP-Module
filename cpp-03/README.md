# CPP Module 03

## Overview
This module introduces inheritance in C++. You'll learn about derived classes, access specifiers, and how to build class hierarchies.

## Exercises

### Ex00: Aaaaand... OPEN!
Introduction to a base class with basic game-like attributes.

**Key Concepts:**
- Class design with attributes and methods
- Member initialization
- Basic combat mechanics simulation
- Encapsulation

**Class:**
- `ClapTrap` - A robot with hit points, energy points, and attack damage

**Attributes:**
- Name
- Hit points (10)
- Energy points (10)
- Attack damage (0)

**Member Functions:**
- `attack(const std::string& target)` - Attack a target
- `takeDamage(unsigned int amount)` - Take damage
- `beRepaired(unsigned int amount)` - Repair hit points

**Compilation:**
```bash
make
```

---

### Ex01: Serena, my love!
First derived class introducing inheritance.

**Key Concepts:**
- Public inheritance
- Constructor chaining
- Method overriding
- Derived class specific attributes
- Calling base class constructors

**Classes:**
- `ClapTrap` - Base class
- `ScavTrap` - Derived class with modified attributes

**ScavTrap Specifics:**
- Hit points: 100
- Energy points: 50
- Attack damage: 20
- Special ability: `guardGate()` - Gate keeper mode

**Compilation:**
```bash
make
```

**Usage:**
```cpp
ScavTrap scav("SC4V-TP");
scav.attack("target");
scav.takeDamage(30);
scav.beRepaired(20);
scav.guardGate();  // Special ability
```

---

### Ex02: Repetitive work
Adding another derived class to practice inheritance.

**Key Concepts:**
- Multiple derived classes from same base
- Different initialization values per derived class
- Polymorphic behavior
- Class hierarchy design

**Classes:**
- `ClapTrap` - Base class
- `ScavTrap` - First derived class
- `FragTrap` - Second derived class

**FragTrap Specifics:**
- Hit points: 100
- Energy points: 100
- Attack damage: 30
- Special ability: `highFivesGuys()` - Positive high fives request

**Compilation:**
```bash
make
```

**Usage:**
```cpp
FragTrap frag("FR4G-TP");
frag.attack("enemy");
frag.takeDamage(40);
frag.beRepaired(30);
frag.highFivesGuys();  // Special ability
```

## Class Hierarchy

```
    ClapTrap
    /      \
ScavTrap  FragTrap
```

## Learning Objectives
- Understand inheritance and class hierarchies
- Learn constructor chaining in derived classes
- Practice method overriding
- Implement class-specific behavior in derived classes
- Master access specifiers (public, protected, private)
- Understand the "is-a" relationship in inheritance
