#pragma once

#include <string>
#include <iostream>

typedef struct Data {
	std::string	name;
	size_t		age;
	Data		*next;
}				Data;
