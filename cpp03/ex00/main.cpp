#include "ClapTrap.hpp"

int main()
{
  ClapTrap claptrap("TestA");

  claptrap.attack("TestB");
  claptrap.takeDamage(5);
  claptrap.beRepaired(3);
  claptrap.attack("TestC");
  claptrap.takeDamage(9);
  claptrap.beRepaired(5);
  return 0;
}