#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
  public:
    ScavTrap();
    ScavTrap(const std::string& str);
    ScavTrap(const ScavTrap& other);
    ~ScavTrap();
    ScavTrap& operator=(const ScavTrap& other);
    void attack(const std::string& target);
    void guardGate();
};

#endif