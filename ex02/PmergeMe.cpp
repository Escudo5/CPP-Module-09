/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:49:04 by smarquez          #+#    #+#             */
/*   Updated: 2025/11/10 16:28:07 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


// PmergeMe::~PmergeMe()
// {
    
// }

void PmergeMe::sortDeque(std::deque<int> &data)
{
    
}

void PmergeMe::sortVector(std::vector<int> &data)
{
    
}
size_t PmergeMe::binarySearchVector(const std::vector<int> &data, int value)
{
    size_t left = 0;
    size_t right = data.size();
    while (left < right)
    {
        size_t mid = left + (right - left) / 2; // gestion en caso de left+right > INT_MAX
        if (data[mid] < value)
        {
            left = mid + 1; //buscar en la derecha
        }
        else
        {
            right = mid; // buscar en la izquierda
        }
    }
    return left;
}
//buscar en que parte del array hay que insertar el numero.


void PmergeMe::binaryInsertVector(std::vector<int> &data, int value)
{
    size_t pos = binarySearchVector(data, value);
    data.insert(data.begin() + pos, value);
}

// Inserta el numero en el indice correcto


size_t PmergeMe::binarySearchDeque(const std::deque<int> &data, int value)
{
    size_t left = 0;
    size_t right = data.size();
    while (left < right)
    {
        size_t mid = left + (right - left) / 2; // gestion en caso de left+right > INT_MAX
        if (data[mid] < value)
        {
            left = mid + 1; //buscar en la derecha
        }
        else
        {
            right = mid; // buscar en la izquierda
        }
    }
    return left; 
}


//igual para deque
void PmergeMe::binaryInsertDeque(std::deque<int> &data, int value)
{
    size_t pos = binarySearchDeque(data, value);
    data.insert(data.begin() + pos, value);
}


void PmergeMe::mergeInsertSortVector(std::vector<int> &data)
{
    if (data.size() <= 1)
        return;
    
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < data.size(); i += 2) //recorremos de 2 en 2
    {
        int first = data[i];
        int second = data[i + 1];
        if (first > second)
        {
            pairs.push_back(std::make_pair(second, first)); //swap si first > second 
        }
        else
        {
            pairs.push_back(std::make_pair(first, second));
        }
    }

    bool hasLonely = false;
    int lonely = 0;
    
    if (data.size() % 2 != 0)
    {
        std::cout << "Fuck, lonely number in the array, need to keep coding" << std::endl;
        hasLonely = true;
        lonely = data[data.size() - 1];
    }
    
    std::vector<int> larger;
    std::vector<int> smaller;
    
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::pair<int, int> par = pairs[i];
        smaller.push_back(pairs[i].first);
        larger.push_back(pairs[i].second);
    }
    mergeInsertSortVector(larger);

    std::vector<int> result = larger;
    

    if (!smaller.empty())
    {
        result.insert(result.begin(), smaller[0]); //insertar primer elemento de smaller
    }
    for (size_t i  = 1; i < smaller.size(); i++) //empiezo en 1 porque 0 ya esta smaller[0]
    {
        binaryInsertVector(result, smaller[i]); // insertar el resto de smaller ya ordenado.
    }
    if (hasLonely)
        binaryInsertVector(result, lonely);
    data = result;
}



//pairs = [(3,5), (7,9)]

//menores = [3, 7]
//mayores = [5, 9]


//recorro el vector que me dan de 2 en 2. Guardo las parejas en el vector pairs.
//creo dos vectores nuevos, uno para las parejas mayores y otro para los menores.
//como ya estan ordenados los numeros, siempre pusheo el primero al menor y el segundo al mayor. Sigo iterando parejas.
//comprobamos si hay numeros sueltos.
//ordenamos recusrivo larger porque smaller ya estn ordenados respecto a larger.
//creo un vector resultado y meto todo larger. Inserto el primer elemento de smaller y luego el resto.


void PmergeMe::sortVector(std::vector<int> &data)
{
    mergeInsertSortVector(data);
}

void PmergeMe::sortDeque(std::deque<int> &data)
{
    mergeInsertSortDeque(data);
}

void PmergeMe::mergeInsertSortDeque(std::deque<int> &data)
{
    if (data.size() <= 1)
        return;
    
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < data.size(); i += 2) //recorremos de 2 en 2
    {
        int first = data[i];
        int second = data[i + 1];
        if (first > second)
        {
            pairs.push_back(std::make_pair(second, first)); //swap si first > second 
        }
        else
        {
            pairs.push_back(std::make_pair(first, second));
        }
    }

    bool hasLonely = false;
    int lonely = 0;
    
    if (data.size() % 2 != 0)
    {
        std::cout << "Fuck, lonely number in the array, need to keep coding" << std::endl;
        hasLonely = true;
        lonely = data[data.size() - 1];
    }
    
    std::deque<int> larger;
    std::deque<int> smaller;
    
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::pair<int, int> par = pairs[i];
        smaller.push_back(pairs[i].first);
        larger.push_back(pairs[i].second);
    }
    mergeInsertSortDeque(larger);

    std::deque<int> result = larger;
    

    if (!smaller.empty())
    {
        result.insert(result.begin(), smaller[0]); //insertar primer elemento de smaller
    }
    for (size_t i  = 1; i < smaller.size(); i++) //empiezo en 1 porque 0 ya esta smaller[0]
    {
        binaryInsertDeque(result, smaller[i]); // insertar el resto de smaller ya ordenado.
    }
    if (hasLonely)
        binaryInsertDeque(result, lonely);
    data = result;
}
