#include <iostream>
#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name(""), grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat& b): name(b.name), grade(b.grade) {}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name) {
	if (grade <= 0)
		throw GradeTooHighException();
	else if  (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (&rhs != this) {
		grade = rhs.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade too low");
}

std::string Bureaucrat::getName() const { return (name); }

int Bureaucrat::getGrade() const { return (grade); }

void	Bureaucrat::incrementGrade(void)
{
	if (grade == 1)
		throw GradeTooHighException();
	else
		grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (grade == 150)
		throw GradeTooLowException();
	else
		grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}

void	Bureaucrat::signForm(AForm& targetform)
{
	if (targetform.getIsSigned() == true) {
		std::cout << name << " is trying to sign " << targetform.getName() << " but it is already signed\n";
		return ;
	}
	try {
		targetform.beSigned(*this);
		std::cout << name << " signed " << targetform.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << name << " couldn't sign " << targetform.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const& form)
{
	try {
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << name << " couldn't execute " <<  form.getName() << " because " << e.what() << std::endl;
	}
}
