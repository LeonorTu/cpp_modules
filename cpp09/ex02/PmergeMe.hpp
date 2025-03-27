#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <chrono>

class PmergeMe
{
public:
    PmergeMe();
    ~PmergeMe();
    void run(int argc, char **argv);

    private:
    PmergeMe(const PmergeMe &) = default;
    PmergeMe &operator=(const PmergeMe &) = default;

    std::vector<int> _vector;
    std::deque<int> _deque;
    void displayBefore(int argc, char **argv);
    void displayAfter(const std::deque<int> &container);
    void parseAndSorts(int argc, char **argv);
    void displayTime(size_t size, const std::string &containerName, double timeUs);
    void mergeInsertionDeque(size_t begin, size_t end);
    void mergeInsertionVector(size_t begin, size_t end);
    void mergeDeque(size_t begin, size_t mid, size_t end);
    void mergeVector(size_t begin, size_t mid, size_t end);
    void insertionDeque(size_t begin, size_t end);
    void insertionVector(size_t begin, size_t end);
    void mergeInsertSortDeque(size_t begin, size_t end);
    void mergeInsertSortVector(size_t begin, size_t end);
    template <typename Container> void parseNumbers(int argc, char **argv, Container &container);
};