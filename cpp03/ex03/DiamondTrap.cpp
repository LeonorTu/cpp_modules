#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
  hitPoints = FragTrap::hitPoints;
  energyPoints = ScavTrap::energyPoints;
  attackDamage = FragTrap::attackDamage;
  std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& str): ClapTrap(str + "_clap_name"), ScavTrap(str), FragTrap(str)
{
  name = str;
  hitPoints = 100;
  energyPoints = 50;
  attackDamage = 30;
  std::cout << "Created DiamondTrap " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), ScavTrap(other), FragTrap(other)
{
  name = other.name;
  std::cout << "DiamondTrap " << name << " copy constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
  std::cout << "Destroyed DiamondTrap " << name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
  std::cout << "DiamondTrap " << name << " assignment operator called." << std::endl;
  if (this != &other) {
    ClapTrap::operator=(other);
    name = other.name;
  }
  return *this;
}

void DiamondTrap::whoAmI()
{
  std::cout << "I am " << name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}