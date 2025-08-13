#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include <algorithm>
# include <sstream>
# include <ctime>
# include <sys/time.h>
# include <utility> 

typedef std::string Str;

template <typename Container>
struct FJCon {
	Container elements;
	Container indices;
	Container main;
	Container mainIndices;
	Container pending;
	Container pendingIndices;
	Container pendingPartners;
};

template<typename Container>
void fordJohnsonRecursive(FJCon<Container>& fj);

template<typename Container>
void splitContainer(FJCon<Container>& fj);

template<typename Container>
Container insertionOrder(std::size_t pendingSize);

template<typename Container>
Container calcJacobsthalSeq(std::size_t numElements);

template<typename Container>
void insertPendingIntoMain(FJCon<Container>& fj, const Container& order);

template<typename Container>
Container mergeInsertSort(const Container& input) {
	FJCon<Container> fj;
	fj.elements = input;
	fj.indices.resize(input.size());

	for (std::size_t i = 0; i < input.size(); ++i)
		fj.indices[i] = i;

	fordJohnsonRecursive(fj);
	return fj.elements;
}

template<typename Container>
void fordJohnsonRecursive(FJCon<Container>& fj) {
	if (fj.elements.size() < 2)
		return;

	splitContainer(fj);
	if (fj.elements.size() % 2) {
		fj.main.push_back(fj.elements.back());
		fj.mainIndices.push_back(fj.indices.back());
	}

	FJCon<Container> mainfj;
	mainfj.elements = fj.main;
	mainfj.indices = fj.mainIndices;
	fordJohnsonRecursive(mainfj);

	fj.main = mainfj.elements;
	fj.mainIndices = mainfj.indices;

	Container order = insertionOrder<Container>(fj.pending.size());
	insertPendingIntoMain(fj, order);
}

template<typename Container>
void splitContainer(FJCon<Container>& fj) {
	for (std::size_t i = 0; i + 1 < fj.elements.size(); i += 2) {
		std::size_t hi;
		std::size_t lo;

		if (fj.elements[i] >= fj.elements[i + 1]) {
			hi = i;
			lo = i + 1;
		} else {
			hi = i + 1;
			lo = i;
		}

		fj.main.push_back(fj.elements[hi]);
		fj.pending.push_back(fj.elements[lo]);

		fj.mainIndices.push_back(fj.indices[hi]);
		fj.pendingIndices.push_back(fj.indices[lo]);
		
		fj.pendingPartners.push_back(fj.elements[hi]);
	}
}

template<typename Container>
Container insertionOrder(std::size_t pendingSize) {
	Container jacobsthalSeq = calcJacobsthalSeq<Container>(pendingSize);
	Container order;
	std::size_t processed = 0;

	for (std::size_t k = 1; processed < pendingSize; ++k) {
		std::size_t rangeStart = jacobsthalSeq[k - 1];
		std::size_t rangeEnd = std::min(jacobsthalSeq[k], pendingSize);

		for (std::size_t idx = rangeEnd; idx-- > rangeStart;) {
			order.push_back(idx);
			++processed;
		}
	}

	return order;
}

template<typename Container>
Container calcJacobsthalSeq(std::size_t numElements) {
	Container jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);

	while (jacobsthal.back() < numElements) {
		std::size_t k = jacobsthal.size();
		jacobsthal.push_back(jacobsthal[k - 1] + 2 * jacobsthal[k - 2]);
	}
	return jacobsthal;
}

template<typename Container>
void insertPendingIntoMain(FJCon<Container>& fj, const Container& order) {
	if (order.empty())
		return;

	Container result = fj.main;
	Container resultIndices = fj.mainIndices;

	for (std::size_t p = 0; p < order.size(); ++p) {
		std::size_t idx = order[p];
		typename Container::value_type keyValue = fj.pending[idx];
		typename Container::value_type keyIndex = fj.pendingIndices[idx];
		typename Container::value_type boundValue = fj.pendingPartners[idx];

		typename Container::iterator posBound =
			std::lower_bound(result.begin(), result.end(), boundValue);

		typename Container::iterator pos =
			std::lower_bound(result.begin(), posBound, keyValue);

		std::size_t insertPos = pos - result.begin();

		result.insert(pos, keyValue);
		resultIndices.insert(resultIndices.begin() + insertPos, keyIndex);
	}
	fj.elements.swap(result);
	fj.indices.swap(resultIndices);
}

template <typename Container, typename Func>
double measureRealTime(Container& cont, Func sortFunc) {
	struct timeval start, end;
	gettimeofday(&start, NULL);
	cont = sortFunc(cont);
	gettimeofday(&end, NULL);
	return (end.tv_sec - start.tv_sec) * 1000.0 +
		   (end.tv_usec - start.tv_usec) / 1000.0;
}

template <typename Container, typename Func>
double measureCPUTime(Container& cont, Func sortFunc) {
	std::clock_t start = std::clock();
	cont = sortFunc(cont);
	std::clock_t end = std::clock();
	return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
}

template <typename T>
Str containerToStr(const T& container) {
	std::ostringstream oss;
	typename T::const_iterator it = container.begin();

	if (it != container.end())
		oss << *it++;

	for (; it != container.end(); ++it)
		oss << " " << *it;

	return oss.str();
}

#endif
