#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

class PmergeMe
{
public:
    PmergeMe();
    ~PmergeMe();
    void parse(int argc, char **argv);


    private:
    PmergeMe(const PmergeMe &) = default;
    PmergeMe &operator=(const PmergeMe &) = default;

    std::vector<int> _vector;
    std::deque<int> _deque;
    void sortDisplay(int argc, char **argv);
    void mergeInsertionDeque(size_t begin, size_t end);
    void mergeInsertionVector(size_t begin, size_t end);
    void mergeDeque(size_t begin, size_t mid, size_t end);
    void mergeVector(size_t begin, size_t mid, size_t end);
    void insertionDeque(size_t begin, size_t end);
    void insertionVector(size_t begin, size_t end);
    void mergeInsertSortDeque(size_t begin, size_t end);
    void mergeInsertSortVector(size_t begin, size_t end);
};