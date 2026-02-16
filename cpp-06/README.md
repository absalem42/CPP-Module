# CPP Module 06

## Overview
This module explores C++ casts and type conversions. Learn about the different types of casts in C++98 and when to use each one: static_cast, dynamic_cast, reinterpret_cast, and const_cast.

## Exercises

### Ex00: Conversion of scalar types
Converting string representations to various scalar types.

**Key Concepts:**
- Type detection from strings
- static_cast for scalar conversions
- Conversion between char, int, float, double
- Handling special values (nan, inf)
- Overflow detection
- Display impossibility and precision

**Class:**
- `ScalarConverter` - Static class with convert() method

**Features:**
- Detects input type (char, int, float, double)
- Converts to all scalar types
- Handles literals: `-inff`, `+inff`, `nanf`, `-inf`, `+inf`, `nan`
- Displays impossible conversions
- Shows precision for float and double

**Compilation:**
```bash
make
```

**Usage:**
```bash
./convert 0
./convert nan
./convert 42.0f
```

**Output Format:**
```
char: Non displayable / impossible
int: 42
float: 42.0f
double: 42.0
```

---

### Ex01: Serialization
Converting pointers to integers and back using reinterpret_cast.

**Key Concepts:**
- reinterpret_cast usage
- Pointer to integer conversion (uintptr_t)
- Serialization and deserialization
- Low-level type reinterpretation
- Understanding memory addresses

**Class:**
- `Serializer` - Static class for pointer/integer conversion

**Data Structure:**
```cpp
struct Data {
    // Member variables
};
```

**Static Functions:**
- `uintptr_t serialize(Data* ptr)` - Convert pointer to integer
- `Data* deserialize(uintptr_t raw)` - Convert integer back to pointer

**Key Requirement:**
- `deserialize(serialize(ptr)) == ptr` must be true

**Compilation:**
```bash
make
```

---

### Ex02: Identify real type
Runtime type identification using dynamic_cast.

**Key Concepts:**
- dynamic_cast for polymorphic types
- Runtime Type Identification (RTTI)
- Pointer vs. reference casting
- Exception handling with dynamic_cast
- Random object generation

**Classes:**
- `Base` - Abstract base class with virtual destructor
- `A` - Derived from Base
- `B` - Derived from Base
- `C` - Derived from Base

**Functions:**
- `Base* generate(void)` - Randomly creates A, B, or C
- `void identify(Base* p)` - Identifies type using pointers
- `void identify(Base& p)` - Identifies type using references

**Methods:**
- Pointer version: Use dynamic_cast and check for NULL
- Reference version: Use dynamic_cast with exception handling

**Compilation:**
```bash
make
```

**Usage:**
```cpp
Base* obj = generate();
identify(obj);     // Pointer-based identification
identify(*obj);    // Reference-based identification
```

## Cast Types Summary

| Cast Type | Usage | Example |
|-----------|-------|---------|
| static_cast | Compile-time type conversion | `static_cast<int>(42.5f)` |
| dynamic_cast | Runtime polymorphic casting | `dynamic_cast<Derived*>(base)` |
| reinterpret_cast | Low-level reinterpretation | `reinterpret_cast<uintptr_t>(ptr)` |
| const_cast | Add/remove const qualifier | `const_cast<char*>(str)` |

## Learning Objectives
- Understand all four C++ cast types
- Master static_cast for scalar conversions
- Use reinterpret_cast for pointer/integer conversions
- Apply dynamic_cast for safe downcasting
- Implement runtime type identification (RTTI)
- Handle special floating-point values
- Practice exception-based type checking
- Understand when each cast type is appropriate
