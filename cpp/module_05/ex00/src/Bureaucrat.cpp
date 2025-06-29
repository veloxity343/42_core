#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(150) {
	std::cout << "Bureaucrat Default Constructor called for " << name <<
		" with a grade of " << grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b): name(b.name), grade(b.grade) {
	std::cout << "Bureaucrat Copy Constructor called to copy " << b.getName() << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name) {
	std::cout << "\033[1;32mBureaucrat Constructor called for \033[0m" << name <<
		"\033[1;32m with a grade of \033[0m" << grade << std::endl;
	this->setGrade(grade);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
	std::cout << "Bureaucrat Assignment Operator called for " << name << std::endl;
	if (&b != this) {
		grade = b.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "\033[1;31mBureaucrat Destructor called for \033[0m" << name << std::endl;
}

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

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = grade;
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
