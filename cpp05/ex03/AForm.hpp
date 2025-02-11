#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
  private:
    const std::string name_;
    bool isSigned_;
    const int gradeToSign_;
    const int gradeToExecute_;
    const std::string target;

  public:
    AForm();
    AForm(const std::string& name, const int gradeToSign, const int gradeToExecute, const std::string& target);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat& bureaucrat);
    std::string getTarget() const;
    virtual void execute(Bureaucrat const & executor) const = 0;
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
    class FormNotSignedException : public std::exception{
      private:
        std::string message_;
      public:
        FormNotSignedException(const std::string& message);
        const char* what() const noexcept;
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& Aform);

#endif