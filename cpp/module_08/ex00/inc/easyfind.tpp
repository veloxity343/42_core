#include <algorithm>
#include "easyfind.hpp"

template <typename T> typename T::iterator easyfind(T &container, int n) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}
