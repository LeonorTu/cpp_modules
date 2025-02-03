#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
  std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(const std::string& str): ClapTrap(str)
{
  name = str;
  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
  std::cout << "Created FragTrap " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
  std::cout << "FragTrap " << name << " copy constructor called." << std::endl;
}

FragTrap::~FragTrap()
{
  std::cout << "Destroyed FragTrap " << name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
  std::cout << "FragTrap " << name << " assignment operator called." << std::endl;
  if (this != &other) {
      ClapTrap::operator=(other);
  }
  return *this;
}

void FragTrap::highFivesGuys()
{
  if (energyPoints <= 0 || hitPoints <= 0)
    std::cout << "FrahTrap " << name << " has no energy point or hit point left to give a high five.\n";
  else
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}