#pragma once

#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
private:
	const std::string target;
	void executeForm() const;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm&);
	RobotomyRequestForm(std::string);
	RobotomyRequestForm& operator=(const RobotomyRequestForm&);
	~RobotomyRequestForm();
};
