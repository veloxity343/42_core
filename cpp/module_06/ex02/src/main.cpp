#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <cstdio>
#include <typeinfo>

static Base *generate(void) {
	switch (rand() % 3) {
	case 0:
		return (new A());
		break;
	case 1:
		return (new B());
		break;
	case 2:
		return (new C());
		break;
	default:
		perror("Error: Something went wrong with the random generator");
		return (NULL);
	}
}

static void identify(Base *ptr) {
	if (dynamic_cast<A *>(ptr))
		std::cout << "A is the identified type (from pointer)" << std::endl;
	else if (dynamic_cast<B *>(ptr))
		std::cout << "B is the identified type (from pointer)" << std::endl;
	else if (dynamic_cast<C *>(ptr))
		std::cout << "C is the identified type (from pointer)" << std::endl;
	else
		std::cout << "Unknown type (from pointer)" << std::endl;
}

void identify(Base& ref) {
	try {
		(void)dynamic_cast<A&>(ref);
		std::cout << "A is the identified type (from reference)" << std::endl;
		return;
	} catch (std::bad_cast&) {}

	try {
		(void)dynamic_cast<B&>(ref);
		std::cout << "B is the identified type (from reference)" << std::endl;
		return;
	} catch (std::bad_cast&) {}

	try {
		(void)dynamic_cast<C&>(ref);
		std::cout << "C is the identified type (from reference)" << std::endl;
		return;
	} catch (std::bad_cast&) {}

	std::cout << "Unknown type (from reference)" << std::endl;
}

int main() {
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		Base *obj = generate();
		if (!obj)
			return 1;
			
		identify(obj);
		identify(*obj);
		delete (obj);

		std::cout << std::endl;
	}
	return 0;
}
