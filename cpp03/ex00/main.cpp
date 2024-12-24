#include "ClapTrap.hpp"

int main()
{
  ClapTrap claptrap("TestA");

  claptrap.attack("TestB");
  claptrap.takeDamage(5);
  claptrap.beRepaired(3);
  return 0;
}