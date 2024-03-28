#include "Dog.hpp"


Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Default constructor of Dog is called" << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type)
{
    std::cout << "Dog " << type << " is created" << std::endl;
    this->type = type;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    type = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
    type = other.type;
    return(*this);
}

Dog::~Dog()
{
    std::cout << "Dog is destroyed" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog barks" << std::endl;
}