/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:28:28 by smarquez          #+#    #+#             */
/*   Updated: 2025/11/10 17:18:03 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool validParse(const std::string &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void printVector(std::vector<int> &vec, const std::string &label)
{
    std::cout << label;
    size_t limit = vec.size();
    bool showElipsis = false;

    if (vec.size() > 10)
    {
        limit = 5;
        showElipsis = true;
    }
    
    for (size_t i = 0; i < limit; i++)
    {
        std::cout << vec[i];
        if (i < limit - 1)
            std::cout << " ";
    }
    if (showElipsis)
        std::cout << " [...] " ;
    std::cout << std::endl;
}

int main (int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    std::vector<int> vec;
    std::deque<int> deque;

    for (int i = 1; i < argc; i++)
    {
        if (!validParse(argv[i]))
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        int num = std::atoi(argv[i]);
        if (num <= 0)
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        vec.push_back(num);
        deque.push_back(num);
    }
    printVector(vec, " Before: ");
    
    clock_t start_vec = clock();
    PmergeMe::sortVector(vec);
    clock_t end_vec = clock();
    double time_vec = (double)(end_vec- start_vec) / CLOCKS_PER_SEC * 1000000;


    clock_t start_deque = clock();
    PmergeMe::sortDeque(deque);
    clock_t end_deque = clock();
    double time_deq = (double)(end_deque - start_deque) / CLOCKS_PER_SEC * 1000000;
    
    printVector(vec, " After: ");
    std::cout << " Time to process range of " << vec.size() << " elements with std::vector: " << time_vec << " us" << std::endl;
    std::cout << " Time to process range of " << deque.size() << " elements with std::deque: " << time_deq << " us" << std::endl;

    
    return 0;
}