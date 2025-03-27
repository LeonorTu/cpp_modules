#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::~PmergeMe()
{}

void PmergeMe::run(int argc, char **argv)
{
    displayBefore(argc, argv);
    parseAndSorts(argc, argv);
}

void PmergeMe::displayBefore(int argc, char **argv)
{
    std::cout << "Before: ";
    for (int i = 1; i < argc && i <= 10; ++i)
        std::cout << argv[i] << " ";
    if (argc > 10)
        std::cout << "[...]";
    std::cout << std::endl;
}

void PmergeMe::displayAfter(const std::deque<int> &container)
{
    std::cout << "After: ";
    for (size_t i = 0; i < container.size() && i < 10; ++i)
        std::cout << container[i] << " ";
    if (container.size() > 10)
        std::cout << "[...]";
    std::cout << std::endl;
}

void PmergeMe::parseAndSorts(int argc, char **argv)
{
    // Process with deque
    _deque.clear();
    auto startDeque = std::chrono::high_resolution_clock::now();
    parseNumbers(argc, argv, _deque);
    mergeInsertionDeque(0, _deque.size());
    auto endDeque = std::chrono::high_resolution_clock::now();
    auto dequeTime =
        std::chrono::duration_cast<std::chrono::microseconds>(endDeque - startDeque).count();
    displayAfter(_deque);
    displayTime(_deque.size(), "std::deque", dequeTime);

    // Process with vector
    _vector.clear();
    auto startVector = std::chrono::high_resolution_clock::now();
    parseNumbers(argc, argv, _vector);
    mergeInsertionVector(0, _vector.size());
    auto endVector = std::chrono::high_resolution_clock::now();
    auto vectorTime =
        std::chrono::duration_cast<std::chrono::microseconds>(endVector - startVector).count();
    displayTime(_vector.size(), "std::vector", vectorTime);
}

// Parse numbers from arguments into a container
template <typename Container>
void PmergeMe::parseNumbers(int argc, char **argv, Container &container)
{
    for (int i = 1; i < argc; ++i) {
        std::istringstream iss(argv[i]);
        int num;
        if (!(iss >> num) || !iss.eof() || num < 0)
            throw std::runtime_error("Error: only positive integer is allowed");

        container.push_back(num);
    }
}

void PmergeMe::displayTime(size_t size, const std::string &containerName, double timeUs)
{
    std::cout << "Time to process a range of " << size << " elements with " << containerName
              << " : " << std::fixed << std::setprecision(5) << timeUs << " us" << std::endl;
}

void PmergeMe::mergeInsertionDeque(size_t begin, size_t end)
{
    if (end - begin <= 10) {
        insertionDeque(begin, end);
        return;
    }

    size_t mid = (begin + end) / 2;
    mergeInsertionDeque(begin, mid);
    mergeInsertionDeque(mid, end);
    mergeDeque(begin, mid, end);
}

void PmergeMe::mergeInsertionVector(size_t begin, size_t end)
{
    if (end - begin <= 10) {
        insertionVector(begin, end);
        return;
    }

    size_t mid = (begin + end) / 2;
    mergeInsertionVector(begin, mid);
    mergeInsertionVector(mid, end);
    mergeVector(begin, mid, end);
}

void PmergeMe::mergeDeque(size_t begin, size_t mid, size_t end)
{
    std::deque<int> temp(_deque.begin() + begin, _deque.begin() + end);
    size_t i = 0, j = mid - begin, k = begin;
    while (i < mid - begin && j < end - begin) {
        if (temp[i] <= temp[j]) {
            _deque[k++] = temp[i++];
        }
        else
            _deque[k++] = temp[j++];
    }

    while (i < mid - begin)
        _deque[k++] = temp[i++];
    while (j < end - begin)
        _deque[k++] = temp[j++];
}

void PmergeMe::mergeVector(size_t begin, size_t mid, size_t end)
{
    std::deque<int> temp(_vector.begin() + begin, _vector.begin() + end);
    size_t i = 0, j = mid - begin, k = begin;
    while (i < mid - begin && j < end - begin) {
        if (temp[i] <= temp[j]) {
            _vector[k++] = temp[i++];
        }
        else
            _vector[k++] = temp[j++];
    }

    while (i < mid - begin)
        _vector[k++] = temp[i++];
    while (j < end - begin)
        _vector[k++] = temp[j++];
}

void PmergeMe::insertionDeque(size_t begin, size_t end)
{
    for (size_t i = begin + 1; i < end; ++i) {
        int key = _deque[i];
        size_t j = i;
        for (; j > begin && _deque[j - 1] > key; --j)
            _deque[j] = _deque[j - 1];
        _deque[j] = key;
    }
}

void PmergeMe::insertionVector(size_t begin, size_t end)
{
    for (size_t i = begin + 1; i < end; ++i) {
        int key = _vector[i];
        size_t j = i;
        for (; j > begin && _vector[j - 1] > key; --j)
            _vector[j] = _vector[j - 1];
        _vector[j] = key;
    }
}

void PmergeMe::mergeInsertSortDeque(size_t begin, size_t end)
{
    if (end - begin <= 10) {
        insertionDeque(begin, end);
        return;
    }

    size_t mid = (begin + end) / 2;
    mergeInsertSortDeque(begin, mid);
    mergeInsertSortDeque(mid, end);
    mergeDeque(begin, mid, end);
}

void PmergeMe::mergeInsertSortVector(size_t begin, size_t end)
{
    if (end - begin <= 10) {
        insertionVector(begin, end);
        return;
    }

    size_t mid = (begin + end) / 2;
    mergeInsertSortVector(begin, mid);
    mergeInsertSortVector(mid, end);
    mergeVector(begin, mid, end);
}
