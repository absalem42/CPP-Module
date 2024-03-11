#include "HumanB.hpp"


HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weaponA = NULL;
}

HumanB::~HumanB()
{
    
}

void	HumanB::setWeapon(Weapon& weapon)
{
    this->weaponA = &weapon;
}

void	HumanB::attack()
{
    if (weaponA)
		std::cout << this->name << " attacks with their "
				<< this->weaponA->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon to attack." << std::endl;
}