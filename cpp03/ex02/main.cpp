#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "Creating a FragTrap:" << std::endl;
    FragTrap frag("Fraggy");
    frag.attack("enemy");
    frag.highFivesGuys();
     // FragTrap and ClapTrap destructors will be called here


    std::cout << "Creating a ScavTrap:" << std::endl;
    ScavTrap scav("Scavvy");
    scav.attack("enemy");
    // ScavTrap and ClapTrap destructors will be called here

    return 0;
}
