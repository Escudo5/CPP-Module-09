/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:25:24 by smarquez          #+#    #+#             */
/*   Updated: 2025/11/05 17:51:57 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::RPN()
{
    
}

// RPN::RPN(const RPN &copy)
// {

// }

// RPN &RPN::operator=(const RPN &copy)
// {
    
// }

RPN::~RPN()
{

}

bool RPN::isNumber(const std::string &token)const
{
   if (token.empty())
        return false;
    if (token.length() != 1)
        return false;
    return std::isdigit(token[0]);
}

bool RPN::isOperator(const std::string &token)const
{
    if (token.length() != 1)
        return false;
    char c = token[0];
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::evaluate(const std::string &expression)
{
    std::stringstream ss(expression);
    std::string numbers;

    while (ss >> numbers)
    {
        if (isNumber(numbers))
        {
            int num = std::atoi(numbers.c_str());
            _stack.push(num);
        }
        else if (isOperator(numbers))
        {
            if (_stack.size() < 2)
            {
                std::cerr << "Error: stack too small " << std::endl;
                throw std::runtime_error("Error");
            }

            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();

            int result;
            char op = numbers[0];
            if (op == '+')
                result = a + b;
            else if (op == '-')
                result = a - b;
            else if (op == '*')
                result = a * b;
            else if (op == '/')
            {
                if (b == 0)
                {
                    std::cerr << "Error can't divide by 0 " << std::endl;
                    throw std::runtime_error("Error");
                }
                result = a / b;
            }
            _stack.push(result);
        }
        else
        {
            throw std::runtime_error("Error");
        }
            
    
    }
    if (_stack.size() != 1)
    {
        throw std::runtime_error("Error");
    }
    return _stack.top();
}

// double RPN::operate(char op, int b, int a) const
// {
    
// }