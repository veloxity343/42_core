#include "../inc/Serializer.hpp"

int main() {
    Data ptr;
	Data ptr2;

	ptr.name = "Dracula";
	ptr.age = 10000;
	ptr.next = &ptr2;

	ptr2.name = "Helsing";
	ptr2.age = 42;
	ptr2.next = NULL;

	std::cout << "=== Original Struct ===\n";
	std::cout << "ptr address       : " << &ptr << "\n";
	std::cout << "ptr.name          : " << ptr.name << "\n";
	std::cout << "ptr.age           : " << ptr.age << "\n";
	std::cout << "ptr.next address  : " << ptr.next << "\n\n";

	std::cout << "ptr2 address      : " << &ptr2 << "\n";
	std::cout << "ptr2.name         : " << ptr2.name << "\n";
	std::cout << "ptr2.age          : " << ptr2.age << "\n";
	std::cout << "ptr2.next address : " << ptr2.next << "\n\n";

	uintptr_t raw = Serializer::serialize(&ptr);
    uintptr_t raw2 = Serializer::serialize(&ptr2);
	std::cout << "=== Serialization ===\n";
	std::cout << "Serialized uintptr_t value : " << raw << "\n";
    std::cout << "Serialized uintptr_t value2: " << raw2 << "\n\n";

	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "=== Deserialization ===\n";
	std::cout << "deserialized address      : " << deserialized << "\n";
	std::cout << "deserialized->name        : " << deserialized->name << "\n";
	std::cout << "deserialized->age         : " << deserialized->age << "\n";
	std::cout << "deserialized->next address: " << deserialized->next << "\n\n";

    Data* deserialized2 = Serializer::deserialize(raw2);
    std::cout << "deserialized2 address      : " << deserialized2 << "\n";
    std::cout << "deserialized2->name        : " << deserialized2->name << "\n";
    std::cout << "deserialized2->age         : " << deserialized2->age << "\n";
    std::cout << "deserialized2->next address: " << deserialized2->next << "\n\n";

	return 0;
}
