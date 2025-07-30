#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <sys/time.h>
#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() : _vector(0), _deque(0) {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vector(other._vector), _deque(other._deque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::Run(const Str& input) {
	if (!checkAndLoadInput(input))
		throw std::runtime_error("Error: only accept positive value");
	
	cpuRunTime(input);
	realRunTime(input);
}

bool PmergeMe::checkAndLoadInput(const Str& input) {
	if (input.find("-") != Str::npos)
		return false;

	std::stringstream ss(input);
	Str token;

	while (ss >> token) {
		std::stringstream tss(token);
		std::size_t val;
		char leftover;

		if (!(tss >> val) || (tss >> leftover))
			return false;
		_vector.push_back(val);
		_deque.push_back(val);
	}
	return !input.empty();
}

void PmergeMe::cpuRunTime(const Str& input) {
	std::clock_t st, end;

	st = std::clock();
	_vector = mergeInsertSort(_vector);
	end = std::clock();
	double vec_ms = static_cast<double>(end - st) / CLOCKS_PER_SEC * 1000.0;


	st = std::clock();
	_deque = mergeInsertSort(_deque);
	end = std::clock();
	double deq_ms = static_cast<double>(end - st) / CLOCKS_PER_SEC * 1000.0;


	std::cout
		<< "CPU Benchmark\n"
		<< "Before:	" << input << "\n"
		<< "After:	" << containerToStr(_vector) << "\n" 
		<< "Time to process a range of " << _vector.size() << " elements with std::vector : " << vec_ms << " ms\n"
		<< "Time to process a range of " << _deque.size() << " elements with std::deque : " << deq_ms << " ms\n"
		<< std::endl;
}

void PmergeMe::realRunTime(const Str& input) {
	struct timeval st, end;

	gettimeofday(&st, NULL);
	_vector = mergeInsertSort(_vector);
	gettimeofday(&end, NULL);

	double vec_ms = (end.tv_sec - st.tv_sec) * 1000.0 + (end.tv_usec - st.tv_usec) / 1000.0;


	gettimeofday(&st, NULL);
	_deque = mergeInsertSort(_deque);
	gettimeofday(&end, NULL);

	double deq_ms = (end.tv_sec - st.tv_sec) * 1000.0 + (end.tv_usec - st.tv_usec) / 1000.0;

	std::cout
		<< "Real-time Benchmark\n"
		<< "Before:	" << input << "\n"
		<< "After:	" << containerToStr(_vector) << "\n" 
		<< "Time to process a range of " << _vector.size() << " elements with std::vector : " << vec_ms << " ms\n"
		<< "Time to process a range of " << _deque.size() << " elements with std::deque : " << deq_ms << " ms\n"
		<< std::endl;
}
