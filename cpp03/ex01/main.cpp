#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
  // ClapTrap claptrap("TestA");

  // claptrap.attack("TestB");
  // claptrap.takeDamage(5);
  // claptrap.beRepaired(3);
  // claptrap.attack("TestC");
  // claptrap.takeDamage(9);
  // claptrap.beRepaired(5);

  ScavTrap scavtrap("TestA");

  scavtrap.attack("TestB");
  scavtrap.takeDamage(50);
  scavtrap.beRepaired(10);
  scavtrap.takeDamage(100);
  scavtrap.guardGate();
  return 0;
}