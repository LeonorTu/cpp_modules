#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
  protected:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

  public:
    ClapTrap();
    ClapTrap(const std::string& str);
    ClapTrap(const ClapTrap& other);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif