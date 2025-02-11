#ifndef SHRUBBERYCREATIONFOTM_HPP
#define SHRUBBERYCREATIONFOTM_HPP

#include "AForm.hpp"
#include "fstream"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const & executor) const override;
};

#endif