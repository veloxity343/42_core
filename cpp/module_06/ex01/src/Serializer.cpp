#include "../inc/Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Serializer Default Constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &src) {
	std::cout << "Serializer Copy Constructor called" << std::endl;
	*this = src;
}

Serializer::~Serializer() {
	std::cout << "Serializer Destructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &src) {
	std::cout << "Serializer Assignment Operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::unserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
