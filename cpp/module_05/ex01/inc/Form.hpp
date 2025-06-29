#pragma once

#include <string>
#include <ostream>

class Bureaucrat;

class Form {
private:
	const std::string name;
	const int grade_to_sign;
	const int grade_to_exec;
	bool is_signed;
public:
	Form();
	Form(const Form&);
	Form(std::string, int, int);
	Form& operator=(const Form&);
	~Form();

	class GradeTooHighException: public std::exception {
		const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		const char* what() const throw();
	};

	std::string	getName() const;
	int 		getGradeToSign() const;
	int 		getGradeToExec() const;
	bool		getIsSigned() const;
	void		beSigned(const Bureaucrat&);
};

std::ostream& operator<<(std::ostream&, const Form&);
