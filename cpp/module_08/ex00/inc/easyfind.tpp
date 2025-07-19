#pragma once

#include <algorithm>
#include <exception>
#include "easyfind.hpp"

template <typename T> typename T::iterator easyfind(T &cont, int n) {
	typename T::iterator it;

	it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end())
		throw NotFoundExeption();
	return (it);
}
