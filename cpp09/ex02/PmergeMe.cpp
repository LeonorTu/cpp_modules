#include "PmergeMe.hpp"

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
            _deque[k++] = temp[k++];
        while (k < end - begin)
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
            _vector[k++] = temp[k++];
        while (k < end - begin)
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
    if (end - begin <= 10) { // Use insertion sort for small subarrays
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
    if (end - begin <= 10) { // Use insertion sort for small subarrays
        insertionVector(begin, end);
        return;
    }

    size_t mid = (begin + end) / 2;
    mergeInsertSortVector(begin, mid);
    mergeInsertSortVector(mid, end);
    mergeVector(begin, mid, end);
}