#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
    std::cout << "Default constructor of Cat is called" << std::endl;
}

Cat::Cat(const std::string& type) : Animal(type), brain(new Brain(type))
{
    std::cout << "Cat " << type << " is created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Cat " << other.type << " is created by copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
   Animal::operator=(other);
	*brain = *other.brain;
	return (*this);
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat is destroyed" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat meows" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (this->brain);
}
