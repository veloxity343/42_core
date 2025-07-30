#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include <algorithm>
# include <sstream>
# include <vector>

typedef std::string Str;

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
T genJacobsthal(std::size_t n) {
	T iSeq, jSeq;
	if (n < 1)
		return iSeq;
	if (n == 1) {
		iSeq.push_back(0);
		return iSeq;
	}

	jSeq.push_back(1);
	std::size_t j0 = 0, j1 = 1, jval;
	
	while (true) {
		jval = j1 + 2 * j0;
		if (jval >= n)
			break;
		if (jval != jSeq.back())
			jSeq.push_back(jval);
		j0 = j1;
		j1 = jval;
	}

	iSeq.insert(iSeq.end(), jSeq.begin(), jSeq.end());

	for (std::size_t i = n; i-- > 0;) {
		if (!std::binary_search(jSeq.begin(), jSeq.end(), i))
			iSeq.push_back(i);
	}
	return iSeq;
}

template <typename T>
T mergeInsertSort(const T& container) {

	if (container.size() < 2)
		return container;
	

	T main, pending;
	
	for (std::size_t i = 0; i + 1 < container.size(); i += 2) {
		if (container[i] >= container[i + 1]) {
			main.push_back(container[i]);
			pending.push_back(container[i + 1]);
		}
		else {
			main.push_back(container[i + 1]);
			pending.push_back(container[i]);
		} 
	}
	if (container.size() % 2 != 0)
		main.push_back(container.back());

	main = mergeInsertSort(main);

	T jseq = genJacobsthal<T>(pending.size());
	for (typename T::iterator it = jseq.begin(); it != jseq.end(); ++it) {
		typename T::iterator pos = std::lower_bound(main.begin(), main.end(), pending[*it]);
		main.insert(pos, pending[*it]);
	}
	return main;
}

#endif
