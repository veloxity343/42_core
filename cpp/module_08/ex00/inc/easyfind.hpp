#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <vector>
# include <list>
# include <deque>
# include <exception>
# include <iostream>

class NotFoundException: public std::exception {
public:
	virtual const char *what() const throw() {
		return ("Error: Int not found in container\n");
	}
};

# include "easyfind.tpp"

#endif
