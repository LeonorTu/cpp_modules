#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string str)
{
  name = str;
  hitPoints = 10;
  energyPoints = 10;
  attackDamage = 0;
  std::cout << "Created ClapTrap " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
  std::cout << "Destroyed ClapTrap " << name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
  std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
  std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
  hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
  std::cout << "ClapTrap " << name << " is repaired for " << amount << " points!" << std::endl;
  hitPoints += amount;
}
