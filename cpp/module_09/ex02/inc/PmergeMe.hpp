#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>

typedef std::string Str;

template <typename T>
Str containerToStr(const T& container);

template <typename Container>
double measureCPUTime(Container& data, Container (*sortFunc)(const Container&));

template <typename Container>
double measureRealTime(Container& data, Container (*sortFunc)(const Container&));

class PmergeMe {
private:
	std::vector<std::size_t> _vector;
	std::deque<std::size_t> _deque;

	bool checkAndLoadInput(const Str& input);
	void realRunTime(const Str& input);
	void cpuRunTime(const Str& input);

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void Run(const Str& input);
	void printBenchmark(const Str& benchmarkType, const Str& input, 
		double vectorTime, double dequeTime);
};

# include "PmergeMe.tpp"

#endif
