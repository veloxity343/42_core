#include "../inc/RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm():
	AForm("Robotomy Request Form", 72, 45), target("def") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& robo):
	AForm(robo), target(robo.target) {}

RobotomyRequestForm::RobotomyRequestForm(std::string tg):
	AForm("Robotomy Request Form", 72, 45), target(tg) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	if (&rhs != this)
		AForm::operator=(rhs);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeForm() const {
	int outcome;

	std::cout << "WRRRRR BZZZZTTTT~~\n";
	srand(time(NULL));
	outcome = rand() % 2;
	if (outcome == 1)
		std::cout << target << " has been successfully robotomized\n";
	else
		std::cout << target << "'s robotomization has failed\n";
}
