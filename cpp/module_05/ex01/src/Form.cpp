#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form(): name("blank form"), grade_to_sign(150), is_signed(false) {}

Form::Form(const Form& f): 
	name(f.name),
	grade_to_sign(f.grade_to_sign),
	is_signed(false) {}

Form::Form(std::string n, int tosign): 
	name(n),
	grade_to_sign(tosign),
	is_signed(false) {
	if (grade_to_sign <= 0)
		throw GradeTooHighException();
	else if (grade_to_sign >= 151)
		throw GradeTooLowException();
}

Form& Form::operator=(const Form& rhs) {
	if (&rhs != this)
		is_signed = rhs.is_signed;
	return (*this);
}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade Too High");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade Too Low");
}

std::string Form::getName() const { return (name); }

int Form::getGradeToSign() const { return (grade_to_sign); }

bool Form::getIsSigned() const { return (is_signed); }

void Form::beSigned(const Bureaucrat& bureau) {
	if (bureau.getGrade() > grade_to_sign)
		throw GradeTooLowException();
	else
		is_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << f.getName() << " |To sign:" << f.getGradeToSign() << "|Signed:" << f.getIsSigned();
	return (os);
}
