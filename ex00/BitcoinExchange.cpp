/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:33:32 by smarquez          #+#    #+#             */
/*   Updated: 2025/11/05 15:03:12 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    // std::cout << "default constructor" << std::endl;
}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
// {
//     //no sense to have a copy of database.
// }

// BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
// {
//     return(*this);
// }

BitcoinExchange::~BitcoinExchange()
{
    
}

bool BitcoinExchange::parseDatabaseLine(const std::string &line, std::string &date, double &price)
{
    size_t pos = line.find(',');
    if (pos == std::string::npos) // ',' not found
        return false;
    date = line.substr(0, pos);
    std::string priceStr = line.substr(pos + 1); // sacar precio
    
    char *end;
    price = std::strtod(priceStr.c_str(), &end);
    if (*end != '\0' && *end != '\n' && *end != '\r')
        return false;
    return true;
}

bool BitcoinExchange::isValidDate(const std::string &date)const
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());


    if (year < 1000 || year > 9999)
        return false;    
    if (month > 12 || month < 1)
        return false;
    if (day > 31 || day < 1)
        return false;
    return true;
}

bool BitcoinExchange::isValidValue(double value)const
{
    if (value < 0 || value > 1000)
        return false;
    return true;
}

bool BitcoinExchange::parseInputLine(std::string &line, std::string &date, double &value)
{
    size_t position = line.find(" | ");
    if (position == std::string::npos)
        return false;
    date = line.substr(0, position);
    std::string valueStr = line.substr(position + 3); // +3 para saltar "|".
    
    char *end;
    value = std::strtod(valueStr.c_str(), &end);
    if (*end != '\0' && *end != '\n' && *end != '\r')
        return false;
    return true;
}

double BitcoinExchange::getPrice(const std::string &date) const
{
    if (_database.empty())
        return -1;
    std::map<std::string, double>::const_iterator it = _database.find(date);
    if (it != _database.end())
    {
        return it->second;
    }
    it = _database.lower_bound(date); // busca el primer eemento >= date
    if (it == _database.begin()) // no hay fecha anterior, ERROR.
        return -1;
    it--;
    return it->second;
}

void BitcoinExchange::calculateAndDisplay(const std::string &date, double value)const
{
    double price = getPrice(date);

    if (price < 0)
    {
        std::cerr << "Error: no price data available for date." << std::endl;
        return;
    }

    double result = value * price;

    std::cout << date << " => " << value << " = " << result << std::endl;
}

void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream file (filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line))
    {
        std::string date;
        double value;
        if (!parseInputLine(line, date, value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input =>" << std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cerr << "Error: not a positive number " << std::endl;
            continue;
        }

        if (!isValidValue(value))
        {
            std::cerr << "Error: too large a number " << std::endl;
            continue;
        }
        calculateAndDisplay(date, value);
        
    }
    file.close();
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
        if (parseDatabaseLine(line, date, price))
            _database[date] = price;
    }
    file.close();
}