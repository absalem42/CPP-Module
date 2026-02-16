# CPP Module 09

## Overview
This module focuses on advanced container usage and algorithmic problem-solving using the STL. Work with real-world applications including data processing, expression evaluation, and algorithm analysis.

## Exercises

### Ex00: Bitcoin Exchange
A program that evaluates Bitcoin prices using historical exchange rate data.

**Key Concepts:**
- std::map for key-value storage
- File parsing and validation
- Date handling and validation
- Error handling for invalid input
- Database lookup operations

**Class:**
- `BitcoinExchange` - Manages exchange rate database

**Features:**
- Loads historical BTC prices from CSV database
- Processes input file with date | value format
- Validates dates (YYYY-MM-DD format)
- Validates values (0-1000 range)
- Finds closest earlier date if exact match not found
- Calculates BTC value: amount × rate

**File Format:**
- Database: `date,exchange_rate`
- Input: `date | value`

**Error Handling:**
- Bad input format
- Invalid dates
- Negative numbers
- Values too large (> 1000)
- Dates before database start

**Compilation:**
```bash
make
```

**Usage:**
```bash
./btc input.txt
```

**Example Output:**
```
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
Error: not a positive number.
Error: bad input => 2001-42-42
```

---

### Ex01: Reverse Polish Notation
A calculator that evaluates mathematical expressions in RPN (postfix) notation.

**Key Concepts:**
- std::stack for expression evaluation
- Postfix expression parsing
- Operator handling
- Stack-based algorithms
- Input validation

**Class:**
- `RPN` - Evaluates RPN expressions

**Supported Operations:**
- Addition (+)
- Subtraction (-)
- Multiplication (*)
- Division (/)

**Algorithm:**
1. Read token from input
2. If number: push to stack
3. If operator: pop two operands, apply operation, push result
4. Final stack should contain single result

**Error Handling:**
- Invalid tokens
- Insufficient operands
- Division by zero
- Multiple values left on stack

**Compilation:**
```bash
make
```

**Usage:**
```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "7 7 * 7 -"
./RPN "1 2 * 2 / 2 * 2 4 - +"
./RPN "(1 + 1)"  # Error: invalid token
```

**Example:**
```
Input: 3 4 + 2 *
Stack operations:
  push 3     → [3]
  push 4     → [3, 4]
  + operator → [7]
  push 2     → [7, 2]
  * operator → [14]
Result: 14
```

---

### Ex02: PmergeMe
Implementation of merge-insertion sort (Ford-Johnson algorithm) with performance comparison.

**Key Concepts:**
- std::vector and std::list comparison
- Merge-insertion sort algorithm
- Algorithm complexity analysis
- Performance measurement
- Templated algorithm implementation

**Class:**
- `PmergeMe` - Sorts using both vector and list

**Algorithm (Ford-Johnson):**
1. Pair elements
2. Sort pairs
3. Insert remaining elements efficiently
4. Optimize insertion using binary search

**Features:**
- Sorts positive integers
- Uses both std::vector and std::list
- Measures and compares execution time
- Displays before/after sequences
- Shows time in microseconds

**Time Complexity:**
- Best case: O(n log n)
- Average: O(n log n)
- Worst: O(n log n)

**Compilation:**
```bash
make
```

**Usage:**
```bash
./PmergeMe 3 5 9 7 4
```

**Example Output:**
```
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process with std::vector: 0.00123 us
Time to process with std::list:   0.00145 us
```

**Error Handling:**
- Non-positive integers
- Non-numeric input
- Duplicate values
- Empty input

## Container Comparison

| Container | Ex00 | Ex01 | Ex02 | Characteristics |
|-----------|------|------|------|-----------------|
| std::map | ✓ | | | Ordered key-value pairs, O(log n) lookup |
| std::stack | | ✓ | | LIFO operations, adapter |
| std::vector | | | ✓ | Dynamic array, fast random access |
| std::list | | | ✓ | Doubly-linked list, fast insertion |

## Algorithms Implemented

1. **Database Lookup** (Ex00): Binary search in ordered map
2. **RPN Evaluation** (Ex01): Stack-based expression processing
3. **Merge-Insertion Sort** (Ex02): Hybrid sorting algorithm

## Learning Objectives
- Apply STL containers to real-world problems
- Implement complex algorithms with STL
- Compare container performance
- Parse and validate input data
- Handle file I/O operations
- Implement stack-based algorithms
- Analyze algorithm complexity
- Measure execution time accurately
- Make data-driven container choices
- Practice error handling in production-like scenarios
