#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName) : name(zombieName) {}

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie (void)
{
    std::cout << name << ": I am daying !!!\n";
}