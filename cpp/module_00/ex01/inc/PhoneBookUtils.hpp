#ifndef PHONEBOOK_UTILS_H
# define PHONEBOOK_UTILS_H

# include <cstdlib>
# include <iostream>

void		display_welcome(void);
void		display_menu_and_prompt(std::string &input);
void		wait_for_enter(void);
void		get_input(std::string prompt, std::string &str);
std::string	truncate(std::string str);
std::string	trim_whitespace(std::string str);

#endif
