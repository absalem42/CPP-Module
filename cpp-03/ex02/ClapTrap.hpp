#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
    protected:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage; 
    public:
        ClapTrap();
        ClapTrap(const std::string& newName);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void	displayStats() const;
        
    // Setter functions    
        void setName(const std::string& newName); 
        void setHitPoints(int newHitPoints); 
        void setEnergyPoints(int newEnergyPoints); 
        void setAttackDamage(int newAttackDamage);
    // Getter functions
        std::string getName() const;
        int getHitPoints() const;
        int getEnergyPoints() const; 
        int getAttackDamage() const;
};

#endif