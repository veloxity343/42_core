#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>

typedef std::string Str;

template <typename T>
Str containerToStr(const T& container);

template <typename T>
T mergeInsertSort(const T& container);

template <typename T>
T genJacobsthal(const std::size_t n);

class PmergeMe {
private:
	std::vector<std::size_t> _vector;
	std::deque<std::size_t> _deque;

	bool checkAndLoadInput(const Str& input);
	void cpuRunTime(const Str& input);
	void realRunTime(const Str& input);
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void Run(const Str& input);
};

# include "PmergeMe.tpp"

#endif
