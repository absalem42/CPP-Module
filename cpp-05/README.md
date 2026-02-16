# CPP Module 05

## Overview
This module covers exceptions in C++. Learn how to handle errors elegantly using try-catch blocks, create custom exception classes, and integrate exceptions with your class hierarchies.

## Exercises

### Ex00: Mommy, when I grow up, I want to be a bureaucrat!
Introduction to custom exceptions.

**Key Concepts:**
- Exception basics: try, catch, throw
- Custom exception classes
- Exception class hierarchy (inheriting from std::exception)
- what() method override
- Nested exception classes

**Class:**
- `Bureaucrat` - Has name and grade (1-150)

**Exceptions:**
- `GradeTooHighException` - Thrown when grade < 1
- `GradeTooLowException` - Thrown when grade > 150

**Member Functions:**
- `getName()` - Returns bureaucrat name
- `getGrade()` - Returns current grade
- `incrementGrade()` - Decreases grade number (higher rank)
- `decrementGrade()` - Increases grade number (lower rank)

**Compilation:**
```bash
make
```

---

### Ex01: Form up, maggots!
Adding a Form class with signing requirements.

**Key Concepts:**
- Object interaction and validation
- Grade-based access control
- Boolean state management
- Exception handling in methods

**Classes:**
- `Bureaucrat` - Can sign forms
- `Form` - Can be signed by bureaucrats

**Form Attributes:**
- Name (const)
- Signed status (boolean)
- Grade required to sign (const, 1-150)
- Grade required to execute (const, 1-150)

**Exceptions:**
- `GradeTooHighException`
- `GradeTooLowException`

**Member Functions:**
- `beSigned(Bureaucrat&)` - Attempt to sign the form
- `signForm(Form&)` - Bureaucrat signs a form

**Compilation:**
```bash
make
```

---

### Ex02: No, you need form 28B, not 28C...
Abstract Form class with concrete implementations.

**Key Concepts:**
- Abstract base classes
- Pure virtual functions
- Polymorphic form execution
- Factory pattern preparation
- File I/O integration

**Classes:**
- `AForm` (Abstract) - Base form class
- `ShrubberyCreationForm` - Creates ASCII trees in files
- `RobotomyRequestForm` - 50% chance robotomization
- `PresidentialPardonForm` - Presidential pardon

**Form Requirements:**

| Form | Sign Grade | Exec Grade | Action |
|------|------------|------------|--------|
| Shrubbery | 145 | 137 | Create ASCII tree file |
| Robotomy | 72 | 45 | Drill noises + 50% success |
| Presidential | 25 | 5 | Presidential pardon |

**Pure Virtual:**
- `execute(Bureaucrat const& executor) const = 0`

**Compilation:**
```bash
make
```

---

### Ex03: At least this beats coffee-making
Intern class implementing the Factory pattern.

**Key Concepts:**
- Factory design pattern
- Dynamic form creation
- String-based object creation
- Function pointers or switch statements
- Error handling for unknown forms

**Class:**
- `Intern` - Creates forms by name

**Member Function:**
- `makeForm(std::string formName, std::string target)` - Returns AForm pointer

**Supported Forms:**
- "shrubbery creation"
- "robotomy request"
- "presidential pardon"

**Compilation:**
```bash
make
```

**Usage:**
```cpp
Intern someRandomIntern;
AForm* form;

form = someRandomIntern.makeForm("robotomy request", "Bender");
// Creates and returns a RobotomyRequestForm
```

## Exception Hierarchy

```
std::exception
      |
  Custom Exceptions
  /              \
GradeTooHigh  GradeTooLow
```

## Learning Objectives
- Master exception handling in C++
- Create and throw custom exceptions
- Understand exception safety and RAII
- Design abstract base classes with pure virtual functions
- Implement the Factory design pattern
- Practice exception propagation
- Learn proper exception what() message formatting
