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
  std::cout << "ScavTrap " << name << " copy constructor called." << std::endl;
}

ScavTrap::~ScavTrap()
{
  std::cout << "Destroyed ScavTrap " << name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
  std::cout << "ScavTrap " << name << " assignation operator called." << std::endl;
  if (this == &other)
    return *this;
  ClapTrap::operator=(other);
  return *this;
}

void ScavTrap::attack(const std::string& target)
{
  if (energyPoints == 0)
    std::cout << "ScavTrap " << name << " has no energy left to attack.\n";
  else if (hitPoints == 0)
    std::cout << "ScavTrap " << name << " has already died. Cannot attack anymore.\n";
  else
  {
    energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage! " << energyPoints << " energypoints left." << std::endl;
  }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode.\n";
}
