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
		throw std::runtime_error("Input must be positive integers");
	
	realRunTime(input);
	// cpuRunTime(input);
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

void PmergeMe::realRunTime(const Str& input) {
	double vecTime = measureRealTime(_vector, mergeInsertSort<std::vector<std::size_t> >);
	double deqTime = measureRealTime(_deque, mergeInsertSort<std::deque<std::size_t> >);
	printBenchmark("Real-time", input, vecTime, deqTime);
}

void PmergeMe::cpuRunTime(const Str& input) {
	double vecTime = measureCPUTime(_vector, mergeInsertSort<std::vector<std::size_t> >);
	double deqTime = measureCPUTime(_deque, mergeInsertSort<std::deque<std::size_t> >);
	printBenchmark("CPU", input, vecTime, deqTime);
}

void PmergeMe::printBenchmark(const Str& benchmarkType, const Str& input, 
						   double vectorTime, double dequeTime) {
	std::cout << benchmarkType << " Benchmark\n"
			  << "Before:\t" << input << std::endl
			  << "After:\t" << containerToStr(_vector) << std::endl
			  << "Time to process a range of " << _vector.size() << " elements with std::vector: " << vectorTime << " ms" << std::endl
			  << "Time to process a range of " << _deque.size() << " elements with std::deque: " << dequeTime << " ms" << std::endl
			  << std::endl;
}
