/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:33:32 by smarquez          #+#    #+#             */
/*   Updated: 2025/11/04 16:50:54 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "default constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    //no sense to have a copy of database.
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    
}

bool parseDatabaseLine(const std::string &line, std::string &date, double &price)
{
    size_t pos = line.find(',');
    if (pos == std::string::npos) // ',' not found
        return false;
    date = line.substr(0, pos);
    std::string priceStr = line.substr(pos + 1); // sacar precio


    //convertir string a double.
}


void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }
    std::string line;
    
    std::getline(file, line); //saltar primera linea (header)

    while (std::getline(file, line))
    {
        std::string date;
        double price;
        parseDatabaseLine(line, date, price);
        _database[date] = price;
    }
    file.close();
}