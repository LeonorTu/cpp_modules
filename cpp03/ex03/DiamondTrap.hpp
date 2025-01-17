#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: virtual public ScavTrap, virtual public FragTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string& str);
		DiamondTrap(const DiamondTrap& other);
		~DiamondTrap();
		DiamondTrap& operator=(const DiamondTrap& other);
		void whoAmI();
};


#endif