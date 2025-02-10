#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
  private:
    const std::string name_;
    bool isSigned_;
    const int gradeToSign_;
    const int gradeToExecute_;

  public:
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
    std::string getName() const;
    bool getIsSigned() const;
    const int getGradeToSign() const;
    const int getGradeToExecute() const;
    void beSigned(Bureaucrat& bureaucrat);
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
}

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif