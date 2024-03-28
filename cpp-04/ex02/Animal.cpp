#include "Animal.hpp"

Animal::Animal() 
{
    std::cout << "Default constructor of Animal is called" << std::endl;
    type = "Default";
}

Animal::Animal(const std::string& type) 
{
    std::cout << "Animal " << type << " is created" << std::endl;
    this->type = type;
}

Animal::Animal(const Animal& other)
{
    type = other.type;
}

Animal& Animal::operator=(const Animal& other)
{
    type = other.type;
    return(*this);
}

Animal::~Animal()
{
    std::cout << "Animal " << type << " is destroyed" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}

// void Animal::makeSound() const
// {
//     std::cout << "animal make sound" << std::endl;
// }
