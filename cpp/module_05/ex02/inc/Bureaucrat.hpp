#pragma once

#include <string>
#include <ostream>
#include "AForm.hpp"

class Bureaucrat {
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat&);
	Bureaucrat(std::string, int);
	Bureaucrat& operator=(const Bureaucrat&);
	~Bureaucrat();

	class GradeTooHighException: public std::exception {
		const char* what() const throw();
	};
	
	class GradeTooLowException: public std::exception {
		const char* what() const throw();
	};

	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	// Form operations
	void signForm(AForm&);
	void executeForm(AForm const&);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
