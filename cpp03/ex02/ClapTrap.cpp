#include "ClapTrap.hpp"

ClapTrap::ClapTrap():name("default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
  std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string& str):name(str), hitPoints(10), energyPoints(10), attackDamage(0)
{
  std::cout << "Created ClapTrap " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
  std::cout << "ClapTrap " << name << " copy constructor called." << std::endl;
}

ClapTrap::~ClapTrap()
{
  std::cout << "Destroyed ClapTrap " << name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
  if (energyPoints == 0)
    std::cout << "ClapTrap " << name << " has no energy left to attack.\n";
  else if (hitPoints == 0)
    std::cout << "ClapTrap " << name << " has already died. Cannot attack anymore.\n";
  else
  {
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage! " << energyPoints << " energypoints left." << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount)
{
  if (hitPoints == 0)
    std::cout << "ClapTrap " << name << " has already died. Can't take more damage." << std::endl;
  if (amount >= hitPoints)
  {
    hitPoints = 0;
    std::cout << "ClapTrap " << name << " is dead!" << std::endl;
  }
  else
  {
    hitPoints -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! " << hitPoints << " hitpoints left."  << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount)
{
  if (hitPoints == 0)
    std::cout << "ClapTrap " << name << " has already died. Can't be repaired." << std::endl;
  else if (energyPoints == 0)
    std::cout << "ClapTrap " << name << " is out of energy. Can't be repaired." << std::endl;
  else
  {
    hitPoints += amount;
    energyPoints--;
    std::cout << "ClapTrap " << name << " is repaired for " << amount << " points! " << hitPoints << " hitpoints left. " << energyPoints << " energypoints left." << std::endl;
  }
}
