#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
  ScavTrap scavtrap("TestA");

  scavtrap.attack("TestB");
  scavtrap.takeDamage(50);
  scavtrap.beRepaired(10);
  scavtrap.takeDamage(100);
  scavtrap.guardGate();
  return 0;
}