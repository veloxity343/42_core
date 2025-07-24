#pragma once

#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>
#include <limits>

class Span {
public:
	Span(unsigned int N);
	~Span();

	void addNumber(int num);

	template <typename InputIterator>
	void addRange(InputIterator begin, InputIterator end);

	int shortestSpan() const;
	int longestSpan() const;

	class FullSpanException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class ElementException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class RangeException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	unsigned int _maxSize;
	std::vector<int> _storage;
};

template <typename InputIterator>
void Span::addRange(InputIterator begin, InputIterator end) {
	unsigned int distance = static_cast<unsigned int>(std::distance(begin, end));
	if (_storage.size() + distance > _maxSize)
		throw RangeException();
	_storage.insert(_storage.end(), begin, end);
}
