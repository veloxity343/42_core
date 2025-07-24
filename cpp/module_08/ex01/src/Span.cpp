#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::~Span() {}

void Span::addNumber(int num) {
	if (_storage.size() >= _maxSize)
		throw FullSpanException();
	_storage.push_back(num);
}

int Span::shortestSpan() const {
	if (_storage.size() < 2)
		throw ElementException();

	std::vector<int> temp = _storage;
	std::sort(temp.begin(), temp.end());

	int minSpan = std::numeric_limits<int>::max();
	for (std::size_t i = 1; i < temp.size(); ++i) {
		int span = temp[i] - temp[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan() const {
	if (_storage.size() < 2)
		throw ElementException();

	int min = *std::min_element(_storage.begin(), _storage.end());
	int max = *std::max_element(_storage.begin(), _storage.end());
	return max - min;
}

const char* Span::FullSpanException::what() const throw() {
	return "Span is already full.";
}

const char* Span::ElementException::what() const throw() {
	return "Insufficient elements.";
}

const char* Span::RangeException::what() const throw() {
	return "Range too large.";
}
