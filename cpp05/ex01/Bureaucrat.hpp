#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	name_;
		int	grade_;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		std::string	getName() const;
		int		getGrade() const;
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form& form);
		class GradeTooHighException : public std::exception{
			private:
				std::string	message_;
			public:
				GradeTooHighException(const std::string& message);
				const char* what() const noexcept;
		};
		class GradeTooLowException : public std::exception{
			private:
				std::string	message_;
			public:
				GradeTooLowException(const std::string& message);
				const char* what() const noexcept;
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif