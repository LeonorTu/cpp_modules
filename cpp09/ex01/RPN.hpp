#pragma once

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN {
public:
  RPN();
  ~RPN();

  bool isOperator(char c);
  float calculate(char op, float a, float b);
  float evaluate(const std::string &expression);

private:
  RPN(const RPN &) = default;
  RPN &operator=(const RPN &) = default;
};