#include "Dog.hpp"


Dog::Dog() : Animal ("Dog"), brain(new Brain())
{
    std::cout << "Default constructor of Dog is called" << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type), brain(new Brain(type))
{
    std::cout << "Dog " << type << " is created" << std::endl;
}

Dog::Dog(const Dog& other) : Animal (other), brain(new Brain(*other.brain))
{
	std::cout << "Dog " << other.type << " is created by copy constructor" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	Animal::operator=(other);
	*brain = *other.brain;
	return (*this);
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog is destroyed" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog barks" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (this->brain);
}