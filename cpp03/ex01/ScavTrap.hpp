#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
  public:
    ScavTrap();
    ScavTrap(const std::string& str);
    ScavTrap(const ScavTrap& other);
    ~ScavTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void guardGate();
};

#endif