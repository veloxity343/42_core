#pragma once

#include <string>
#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer {
private:
	Serializer();
	Serializer(const Serializer &src);
	Serializer &operator=(const Serializer &src);
	~Serializer();

public:
	static uintptr_t serialize(Data *ptr);
	static Data* unserialize(uintptr_t raw);
};
