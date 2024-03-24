#include "ScavTrap.hpp"

// Hit Points (health)

int main()
{
    ScavTrap scavTrap("Abdullah");

    scavTrap.displayStats();

    scavTrap.attack("Enemy");

    scavTrap.takeDamage(10);

    scavTrap.beRepaired(8);

    scavTrap.displayStats();

    scavTrap.guardGate();

    return 0;
}