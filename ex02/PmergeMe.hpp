/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:09:25 by smarquez          #+#    #+#             */
/*   Updated: 2025/11/10 16:47:56 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>


class PmergeMe
{
    public:
        static void sortVector(std::vector<int> &data);
        static void sortDeque(std::deque<int> &data);
    
    
    private:
        PmergeMe(); // lo pongo en privado porque no quiero que sea instanciable.
        // PmergeMe(const PmergeMe &copy);
        // PmergeMe &operator=(const PmergeMe &copy);
        // ~PmergeMe();

        static void createPairsVector(const std::vector<int> &data, std::vector<std::pair<int, int> > &pairs);
        static void separateVector(const std::vector<std::pair<int, int> > &pairs, std::vector<int> &larger, std::vector<int> &smaller);
       
        static void mergeInsertSortVector(std::vector<int> &data);
        static void binaryInsertVector(std::vector<int> &data, int value);
        static size_t binarySearchVector(const std::vector<int> &data, int value);

        static void mergeInsertSortDeque(std::deque<int> &data);
        static void binaryInsertDeque(std::deque<int> &data, int value);
        static size_t binarySearchDeque(const std::deque<int> &data, int value);

        
        static void printVector(std::vector<int> &vec, const std::string &label);
    
    
};


#endif


