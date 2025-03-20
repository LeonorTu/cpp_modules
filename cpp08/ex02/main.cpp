#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
  std::cout << "=== Testing MutantStack ===" << std::endl;
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << "Top element: " << mstack.top() << std::endl;
  mstack.pop();
  std::cout << "Size after pop: " << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  std::cout << "Elements in MutantStack:" << std::endl;
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }

  std::cout << "Elements in MutantStack (reverse):" << std::endl;
  MutantStack<int>::reverse_iterator rit = mstack.rbegin();
  MutantStack<int>::reverse_iterator rite = mstack.rend();
  while (rit != rite) {
    std::cout << *rit << std::endl;
    ++rit;
  }

  std::cout << "Elements in MutantStack (const):" << std::endl;
  MutantStack<int>::const_iterator cit = mstack.begin();
  MutantStack<int>::const_iterator cite = mstack.end();
  while (cit != cite) {
    std::cout << *cit << std::endl;
    ++cit;
  }

  std::stack<int> s(mstack);

  std::cout << "\n=== Testing std::list ===" << std::endl;
  std::list<int> lst;
  lst.push_back(5);
  lst.push_back(17);
  std::cout << "Top element: " << lst.back() << std::endl;
  lst.pop_back();
  std::cout << "Size after pop: " << lst.size() << std::endl;
  lst.push_back(3);
  lst.push_back(5);
  lst.push_back(737);
  lst.push_back(0);

  std::cout << "Elements in std::list:" << std::endl;
  std::list<int>::iterator lit = lst.begin();
  std::list<int>::iterator lite = lst.end();
  while (lit != lite) {
    std::cout << *lit << std::endl;
    ++lit;
  }

  std::cout << "Elements in std::list (reverse):" << std::endl;
  std::list<int>::reverse_iterator rlit = lst.rbegin();
  std::list<int>::reverse_iterator rlite = lst.rend();
  while (rlit != rlite) {
    std::cout << *rlit << std::endl;
    ++rlit;
  }

  std::cout << "Elements in std::list (const):" << std::endl;
  std::list<int>::const_iterator clit = lst.begin();
  std::list<int>::const_iterator clite = lst.end();
  while (clit != clite) {
    std::cout << *clit << std::endl;
    ++clit;
  }

  return 0;
}