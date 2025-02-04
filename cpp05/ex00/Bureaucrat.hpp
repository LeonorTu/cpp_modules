#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string	name;
		int	grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& string, int number);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		std::string	getName() const;
		int		getGrade() const;
		void	incrementGrade();
		void	decrementGrade();
		class GradeTooHighException : public std::exception{
			private:
				std::string	message;
			public:
				GradeTooHighException(const std::string& message);
				const char* what() const noexcept;
		};
		class GradeTooLowException : public std::exception{
			private:
				std::string	message;
			public:
				GradeTooLowException(const std::string& message);
				const char* what() const noexcept;
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif