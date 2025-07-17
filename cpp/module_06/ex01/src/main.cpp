#include "../inc/Serializer.hpp"

int main() {
	Data ptr2;
	ptr2.name = "Michaela Mustermann";
	ptr2.age = 42;
	ptr2.next = NULL;

	Data ptr;
	ptr.name = "Max Mustermann";
	ptr.age = 42;
	ptr.next = &ptr2;

	std::cout << "Here is the original struct:" <<
		"\n\taddress: " << &ptr <<
		"\n\tname: " << ptr.name <<
		"\n\tage: " << ptr.age <<
		"\n\tnext address: " << ptr.next << "\n";

	std::cout << "\tptr2 address: " << &ptr2 <<
		"\n\tname: " << ptr2.name <<
		"\n\tage: " << ptr2.age <<
		"\n\tnext address: " << ptr2.next << "\n\n";

	// No instance of Serializer needed
	uintptr_t raw = Serializer::serialize(&ptr);
	Data* deserialized = Serializer::unserialize(raw);

	std::cout << "Here is the deserialized struct:" <<
		"\n\taddress: " << deserialized <<
		"\n\tname: " << deserialized->name <<
		"\n\tage: " << deserialized->age <<
		"\n\tnext address: " << deserialized->next << "\n";

	return 0;
}
