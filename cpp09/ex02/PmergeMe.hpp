#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>

class PmergeMe
{
public:
private:
    std::vector<int> _vector;
    std::deque<int> _deque;
    PmergeMe() = default;
    PmergeMe(const PmergeMe &) = default;
    PmergeMe &operator=(const PmergeMe &) = default;
    ~PmergeMe() = default;
    void mergeDeque(size_t begin, size_t mid, size_t end);
    void mergeVector(size_t begin, size_t mid, size_t end);
    void insertionDeque(size_t begin, size_t end);
    void insertionVector(size_t begin, size_t end);
    void mergeInsertSortDeque(size_t begin, size_t end);
    void mergeInsertSortVector(size_t begin, size_t end);
};