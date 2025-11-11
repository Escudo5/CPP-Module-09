/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:11:09 by smarquez          #+#    #+#             */
/*   Updated: 2025/11/11 13:46:32 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

// #include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <exception>
#include <stdexcept>


class RPN
{
    public:
        RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &copy);
        ~RPN();
        int evaluate(const std::string &expression);

        // class ErrorFatal : public std::exception
        // {
        //     public: 
        //         virtual const char* what() const throw();
        // };
        



    private:
        std::stack<int> _stack;
        bool isOperator(const std::string &token)const;
        bool isNumber(const std::string &token)const;
        // double operate(char op, int b, int a) const;


    
    
};



#endif