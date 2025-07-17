#include "../inc/ScalarConverter.hpp"
#include "../inc/Data.hpp"

int main() {
	Data original;
	original.id = 42;
	original.score = 98.6f;
	original.grade = 'A';

	std::cout << "Original Data:\n";
	std::cout << "ID: " << original.id << "\n";
	std::cout << "Score: " << original.score << "\n";
	std::cout << "Grade: " << original.grade << "\n";

	// Serialize
	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "\nSerialized pointer: " << raw << "\n";

	// Unserialize
	Data* deserialized = Serializer::unserialize(raw);
	std::cout << "\nDeserialized Data:\n";
	std::cout << "ID: " << deserialized->id << "\n";
	std::cout << "Score: " << deserialized->score << "\n";
	std::cout << "Grade: " << deserialized->grade << "\n";

	return 0;
}
