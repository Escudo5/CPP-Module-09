/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:06:46 by smarquez          #+#    #+#             */
/*   Updated: 2025/11/04 14:01:07 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>



class BitcoinExchange
{
    public: 
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        ~BitcoinExchange();
        
        void loadDatabase(const std::string &filename);
        void processInput(std::string &filename);
        
        
        private:
        std::map<std::string, double> _database;

        
        double getPrice(std::string &date)const; //const porque el metodo no modifica la clase
        bool parseDataseLine(const std::string &line, std::string &date, double &price); //cada linea de DB, separa fecha y precio.
        
        
        bool parseInputLine(std::string &line, std::string &date, double &value); //validar entrada "date | value"
        bool isValidDate(const std::string &date); //fecha correcta
        bool isValidValue(double value); // valor entre 0-1000.
        void calculateAndDisplay(const std::string &date, double value)const;
        
        
    };


#endif