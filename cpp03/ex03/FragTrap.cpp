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

  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
  std::cout << "Created FragTrap " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
  name = other.name;
  hitPoints = other.hitPoints;
  energyPoints = other.energyPoints;
  attackDamage = other.attackDamage;
  std::cout << "FragTrap " << name << " copy constructor called." << std::endl;
}

FragTrap::~FragTrap()
{
  std::cout << "Destroyed FragTrap " << name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
  std::cout << "FragTrap " << name << " assignation operator called." << std::endl;
  if (this != &other) {
      ClapTrap::operator=(other);
  }
  return *this;
}

void FragTrap::highFivesGuys()
{
  if (hitPoints == 0)
    std::cout << "FragTrap " << name << " has already died. Can't give a high five" << std::endl;
  else
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}