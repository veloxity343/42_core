/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:11:40 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/06/18 21:03:17 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form(): name("blank form"), grade_to_sign(150), grade_to_exec(150), is_signed(false) {}

// don't copy is_signed because a new form should be not signed yet
Form::Form(const Form& f): 
	name(f.name),
	grade_to_sign(f.grade_to_sign),
	grade_to_exec(f.grade_to_exec),
	is_signed(false) {}

Form::Form(std::string n, int tosign, int toexec): 
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
Form& Form::operator=(const Form& rhs)
{
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

int Form::getGradeToExec() const { return (grade_to_exec); }

bool Form::getIsSigned() const { return (is_signed); }

void Form::beSigned(const Bureaucrat& bureau)
{
	if (bureau.getGrade() > grade_to_sign)
		throw GradeTooLowException();
	else
		is_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << " |To sign:" << f.getGradeToSign() << "|To execute:" << f.getGradeToExec() << "|Signed:" << f.getIsSigned();
	return (os);
}
