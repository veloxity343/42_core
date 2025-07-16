#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

typedef struct Data {
	std::string	name;
	size_t		age;
	Data		*next;
}				Data;

class Serializer {
public:
	Serializer();
	Serializer(const Serializer &src);
	~Serializer();
	Serializer &operator=(const Serializer &src);

	static uintptr_t serialize(Data *ptr);
	static Data* unserialize(uintptr_t raw);
};
