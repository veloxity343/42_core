#pragma once

#include <string>
#include <ostream>

class Bureaucrat;

class AForm {
private:
	const std::string name;
	const int grade_to_sign;
	const int grade_to_exec;
	bool is_signed;
	virtual void	executeForm() const = 0;
public:
	//constructors, destructors, and assignment overload
	AForm();
	AForm(const AForm&);
	AForm(std::string, int, int);
	AForm& operator=(const AForm&);
	virtual ~AForm();

	//exception
	class GradeTooHighException: public std::exception {
		const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		const char* what() const throw();
	};
	class NotSignedException: public std::exception {
		const char* what() const throw();
	};

	//getters
	std::string	getName() const;
	int 		getGradeToSign() const;
	int 		getGradeToExec() const;
	bool		getIsSigned() const;

	void	beSigned(const Bureaucrat&);
	void	execute(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream&, const AForm&);
