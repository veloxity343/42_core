#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm(): name("blank form"), grade_to_sign(150), grade_to_exec(150), is_signed(false) {}

// don't copy is_signed because a new form should be not signed yet
AForm::AForm(const AForm& f):
	name(f.name),
	grade_to_sign(f.grade_to_sign),
	grade_to_exec(f.grade_to_exec),
	is_signed(false) {}

AForm::AForm(std::string n, int tosign, int toexec):
	name(n),
	grade_to_sign(tosign),
	grade_to_exec(toexec),
	is_signed(false)
{
	if (grade_to_sign <= 0 || grade_to_exec <= 0)
		throw GradeTooHighException();
	else if (grade_to_sign >= 151 || grade_to_exec >= 151)
		throw GradeTooLowException();
}

//only copy the signed status as the others are const
AForm& AForm::operator=(const AForm& rhs)
{
	if (&rhs != this)
		is_signed = rhs.is_signed;
	return (*this);
}

AForm::~AForm() {}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade Too High");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade Too Low");
}

const char* AForm::NotSignedException::what() const throw() {
	return ("Form not signed yet");
}

std::string AForm::getName() const { return (name); }

int AForm::getGradeToSign() const { return (grade_to_sign); }

int AForm::getGradeToExec() const { return (grade_to_exec); }

bool AForm::getIsSigned() const { return (is_signed); }

void AForm::beSigned(const Bureaucrat& bureau)
{
	if (bureau.getGrade() > grade_to_sign)
		throw GradeTooLowException();
	else
		is_signed = true;
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (getIsSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();
	executeForm();
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << f.getName()
		<< ", Grade to sign: " << f.getGradeToSign()
		<< " | Grade to execute: " << f.getGradeToExec()
		<< " | Signed : " << f.getIsSigned() << std::endl;
	return (os);
}
