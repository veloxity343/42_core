#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include <algorithm>
# include <sstream>
# include <ctime>
# include <sys/time.h>
# include <utility> // for std::pair

typedef std::string Str;

// Forward declaration
template<typename Container>
Container mergeInsertSort(const Container& input);

// =============================================================================
// UTILITY FUNCTIONS
// =============================================================================

template <typename T>
Str containerToStr(const T& container) {
    std::ostringstream oss;
    typename T::const_iterator it = container.begin();
    if (it != container.end()) {
        oss << *it++;
    }
    for (; it != container.end(); ++it) {
        oss << " " << *it;
    }
    return oss.str();
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

// =============================================================================
// JACOBSTHAL SEQUENCE GENERATION
// =============================================================================

template<typename Container>
Container calculateJacobsthalSequence(std::size_t numElements) {
    Container jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    while (jacobsthal.back() < numElements) {
        std::size_t k = jacobsthal.size();
        std::size_t next = jacobsthal[k-1] + 2 * jacobsthal[k-2];
        jacobsthal.push_back(next);
    }
    
    return jacobsthal;
}

// =============================================================================
// FORD-JOHNSON RECURSIVE IMPLEMENTATION
// =============================================================================

template<typename Container>
void splitIntoMainAndPending(
    const Container& elements,
    const Container& indices,
    Container& main,
    Container& mainIndices,
    Container& pending,
    Container& pendingIndices,
    Container& pendingPartners) {
    std::size_t n = elements.size();
    for (std::size_t i = 0; i + 1 < n; i += 2) {
        if (elements[i] < elements[i+1]) {
            main.push_back(elements[i+1]);
            pending.push_back(elements[i]);
            mainIndices.push_back(indices[i+1]);
            pendingIndices.push_back(indices[i]);
            pendingPartners.push_back(elements[i+1]);
        } else {
            main.push_back(elements[i]);
            pending.push_back(elements[i+1]);
            mainIndices.push_back(indices[i]);
            pendingIndices.push_back(indices[i+1]);
            pendingPartners.push_back(elements[i]);
        }
    }
}

template<typename Container>
void appendOddElement(
    const Container& elements,
    const Container& indices,
    Container& main,
    Container& mainIndices
) {
    std::size_t n = elements.size();
    if (n % 2 == 1) {
        main.push_back(elements[n-1]);
        mainIndices.push_back(indices[n-1]);
    }
}

template<typename Container>
Container buildInsertionOrderFromJacobsthal(std::size_t pendingSize) {
    Container jacobsthalSeq = calculateJacobsthalSequence<Container>(pendingSize);
    Container insertionOrder;
    std::size_t processed = 0;

    for (std::size_t k = 1; processed < pendingSize; ++k) {
        std::size_t start = jacobsthalSeq[k-1];
        std::size_t end = std::min(jacobsthalSeq[k], pendingSize);
        for (std::size_t x = end; x-- > start; ) {
            insertionOrder.push_back(x);
            ++processed;
        }
    }
    return insertionOrder;
}

template<typename Container>
void insertPendingIntoMain(
    Container& result,
    Container& resultIndices,
    const Container& pending,
    const Container& pendingIndices,
    const Container& pendingPartners,
    const Container& insertionOrder) {
    for (std::size_t p = 0; p < insertionOrder.size(); ++p) {
        std::size_t pendingIndex = insertionOrder[p];
        typename Container::value_type keyValue = pending[pendingIndex];
        typename Container::value_type keyIndex = pendingIndices[pendingIndex];
        typename Container::value_type boundValue = pendingPartners[pendingIndex];

        std::size_t bound = 0;
        while (bound < result.size() && result[bound] != boundValue) {
            ++bound;
        }

        typename Container::iterator insertPos =
            std::lower_bound(result.begin(), result.begin() + bound, keyValue);
        std::size_t insertPosition = insertPos - result.begin();

        result.insert(insertPos, keyValue);
        resultIndices.insert(resultIndices.begin() + insertPosition, keyIndex);
    }
}

template<typename Container>
void fordJohnsonRecursive(Container& elements, Container& indices) {
    std::size_t n = elements.size();
    if (n < 2) return;

    Container main, pending, pendingPartners;
    Container mainIndices, pendingIndices;

    splitIntoMainAndPending(elements, indices, main, mainIndices, pending, pendingIndices, pendingPartners);
    appendOddElement(elements, indices, main, mainIndices);

    fordJohnsonRecursive(main, mainIndices);

    Container insertionOrder = buildInsertionOrderFromJacobsthal<Container>(pending.size());

    Container result = main;
    Container resultIndices = mainIndices;
    insertPendingIntoMain(result, resultIndices, pending, pendingIndices, pendingPartners, insertionOrder);

    elements.swap(result);
    indices.swap(resultIndices);
}

// =============================================================================
// MAIN FORD-JOHNSON ENTRY POINT
// =============================================================================

template<typename Container>
Container mergeInsertSort(const Container& input) {
    Container elements = input;
    std::size_t n = elements.size();
    
    if (n < 2) return elements;
    
    // Initialize indices array
    Container indices(n);
    for (std::size_t i = 0; i < n; ++i) {
        indices[i] = i;
    }
    
    // Apply Ford-Johnson algorithm
    fordJohnsonRecursive(elements, indices);
    
    return elements;
}

#endif
