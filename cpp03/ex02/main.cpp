#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "=== Testing FragTrap ===" << std::endl;
    FragTrap frag("Fraggy");
    frag.attack("enemy");
    frag.highFivesGuys();

    std::cout << "=== Testing ScavTrap ===" << std::endl;
    ScavTrap scav("Scavvy");
    scav.attack("enemy");

    return 0;
}
