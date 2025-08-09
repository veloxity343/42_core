#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include <algorithm>
# include <sstream>
# include <vector>
# include <ctime>
# include <sys/time.h>

typedef std::string Str;

template <typename T>
static void splitContainer(const T& container, T& main, T& pending);

template <typename T>
static void genJacobIndices(std::size_t n, T& jSeq);

template <typename T>
static T genJacobsthal(std::size_t n);

template <typename T>
Str containerToStr(const T& container) {
	const Str sep = " ";

	std::ostringstream oss;
	typename T::const_iterator it = container.begin();
	if (it != container.end()) {
		oss << *it;
		++it;
	}
	for (; it != container.end(); ++it) {
		oss << sep << *it;
	}
	return oss.str();
}

template <typename T>
T mergeInsertSort(const T& container) {

	if (container.size() < 2)
		return container;
	
	T main, pending;

	splitContainer(container, main, pending);

	main = mergeInsertSort(main);

	T jseq = genJacobsthal<T>(pending.size());
	for (typename T::const_iterator it = jseq.begin(); it != jseq.end(); ++it) {
		typename T::iterator pos = std::lower_bound(main.begin(), main.end(), pending[*it]);
		main.insert(pos, pending[*it]);
	}
	return main;
}

template <typename T>
static void splitContainer(const T& container, T& main, T& pending) {
	for (std::size_t i = 0; i + 1 < container.size(); i += 2) {
		if (container[i] >= container[i + 1]) {
			main.push_back(container[i]);
			pending.push_back(container[i + 1]);
		} else {
			main.push_back(container[i + 1]);
			pending.push_back(container[i]);
		}
	}
	if (container.size() % 2 != 0)
		main.push_back(container.back());
}

template <typename T>
static T genJacobsthal(std::size_t n) {
	T iSeq, jSeq;
	if (n < 1)
		return iSeq;
	if (n == 1) {
		iSeq.push_back(0);
		return iSeq;
	}

	genJacobIndices(n, jSeq);

	iSeq.insert(iSeq.end(), jSeq.begin(), jSeq.end());

	for (std::size_t i = n; i-- > 0;) {
		if (!std::binary_search(jSeq.begin(), jSeq.end(), i))
			iSeq.push_back(i);
	}
	return iSeq;
}

template <typename T>
static void genJacobIndices(std::size_t n, T& jSeq) {
	if (n == 0)
		return;

	jSeq.push_back(1);
	std::size_t j0 = 0, j1 = 1;

	while (true) {
		std::size_t jval = j1 + 2 * j0;
		if (jval >= n)
			break;
		if (jval != jSeq.back())
			jSeq.push_back(jval);
		j0 = j1;
		j1 = jval;
	}
}

template <typename Container>
double measureRealTime(Container& cont, Container (*sortFunc)(const Container&)) {
	struct timeval start, end;
	gettimeofday(&start, NULL);
	cont = sortFunc(cont);
	gettimeofday(&end, NULL);
	return (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

template <typename Container>
double measureCPUTime(Container& cont, Container (*sortFunc)(const Container&)) {
	std::clock_t start = std::clock();
	cont = sortFunc(cont);
	std::clock_t end = std::clock();
	return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
}

#endif
