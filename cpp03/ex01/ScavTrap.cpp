#include "ScavTrap.hpp"


ScavTrap::ScavTrap(): ClapTrap()
{
  hitPoints = 100;
  energyPoints = 50;
  attackDamage = 20;
  std::cout << "ScavTrap default constructor called." << std::endl;
}


ScavTrap::ScavTrap(const std::string& str): ClapTrap(str)
{
  name = str;
  hitPoints = 100;
  energyPoints = 50;
  attackDamage = 20;
  std::cout << "Created ScavTrap " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
  name = other.name;
  hitPoints = other.hitPoints;
  energyPoints = other.energyPoints;
  attackDamage = other.attackDamage;
  std::cout << "ScavTrap" << name << "copy constructor called." << std::endl;
}

ScavTrap::~ScavTrap()
{
  std::cout << "Destroyed ScavTrap " << name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
  if (hitPoints == 0 && energyPoints == 0)
    std::cout << "ScavTrap " << name << " is out of energy or hit points!" << std::endl;
  else
  {
    energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage! " << energyPoints << " energypoints left." << std::endl;
  }
}

void ScavTrap::takeDamage(unsigned int amount)
{
  if (hitPoints == 0)
    std::cout << "ScavTrap " << name << " has already died. Can't take more damage." << std::endl;
  if (amount > hitPoints)
  {
    hitPoints = 0;
    std::cout << "ScavTrap " << name << " is dead!" << std::endl;
  }
  else
  {
    hitPoints -= amount;
    std::cout << "ScavTrap " << name << " takes " << amount << " points of damage! " << hitPoints << " hitpoints left."  << std::endl;
  }
}

void ScavTrap::beRepaired(unsigned int amount)
{
  if (hitPoints == 0)
    std::cout << "ScavTrap " << name << " has already died. Can't be repaired." << std::endl;
  else if (energyPoints == 0)
    std::cout << "ScavTrap " << name << " is out of energy. Can't be repaired." << std::endl;
  else
  {
    hitPoints += amount;
    energyPoints--;
    std::cout << "ScavTrap " << name << " is repaired for " << amount << " points! " << hitPoints << " hitpoints left. " << energyPoints << " energypoints left." << std::endl;
  }
}

void ScavTrap::guardGate()
{
  std::cout << "ScavTrap " << name << " is now in Gate keeper mode.\n";
}