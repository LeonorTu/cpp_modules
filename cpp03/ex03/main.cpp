#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
   // Test constructors
   std::cout << "\n=== Testing Constructors ===\n";
   DiamondTrap d1("D1");
   DiamondTrap d2(d1);
   DiamondTrap d3;
   d3 = d1;

   // Test functionalities
   std::cout << "\n=== Testing Functions ===\n";
   d1.attack("target");
   d1.takeDamage(30);
   d1.beRepaired(20);
   d1.guardGate();
   d1.highFivesGuys();
   d1.whoAmI();

   std::cout << "\n=== Testing Destruction ===\n";
   return 0;
}
