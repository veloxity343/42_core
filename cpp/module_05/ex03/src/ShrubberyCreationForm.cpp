#include "../inc/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("Shrubbery Creation Form", 145, 137), target("def") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& shrub):
	AForm(shrub), target(shrub.target) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string tg):
	AForm("Shrubbery Creation Form", 145, 137), target(tg) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	if (&rhs != this)
		AForm::operator=(rhs);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeForm() const {
	std::string outf_name = target + "_shrubbery";
	std::ofstream outf(outf_name.c_str());
	if (!outf)
		throw std::runtime_error("Failed to open file: " + outf_name);

	outf <<
"               ,@@@@@@@,\n"
"       ,,,.   ,@@@@@@/@@,  .oo8888o. \n"
"    ,@##@#@@@,@@@@@/@@@@@@,8888\\88/8o \n"
"   ,#@\\#@@#@#@,@@@\\@@@/@#@88\\88888/88' \n"
"   #@@#@#@/#@@#@@\\@@/ /@@@#8888\\88888' \n"
"   #@@@/ #@##@#@@@\\ V /@@' `88\\8 `/88' \n"
"   `@#\\ ` /#@'    |.|        \\ '|8' \n"
"       |o|        | |         | | \n"
"       |.|        | |         | | \n"
" \\._\\\\/ ._\\//_/__/  ,\\\\_//__\\/.  \\_//__/_ \n";
	outf.close();
}
