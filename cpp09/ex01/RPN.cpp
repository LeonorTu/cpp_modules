#include "RPN.hpp"

RPN::RPN()
{}

RPN::~RPN()
{}

bool RPN::isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

float RPN::calculate(char op, float a, float b)
{
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
            throw std::runtime_error("Error: can't divide by 0");
        return a / b;
    default:
        throw std::runtime_error("Error: Invalid operator");
    }
}

float RPN::evaluate(const std::string &expression)
{
    std::stack<float> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token.length() == 1 && isOperator(token[0])) {
            if (stack.size() < 2)
                throw std::runtime_error("Error: Invalid expression");
            float b = stack.top();
            stack.pop();
            float a = stack.top();
            stack.pop();
            float result = calculate(token[0], a, b);
            stack.push(result);
        }
        else {
            try {
                std::istringstream iss(token);
                float number;
                if (!(iss >> number) || !iss.eof()) {
                    throw std::runtime_error("Error: Invalid token");
                }
                stack.push(number);
            }
            catch (const std::exception &) {
                throw std::runtime_error("Error: Invalid token");
            }
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Error: Invalid expression");
    }
    return stack.top();
}