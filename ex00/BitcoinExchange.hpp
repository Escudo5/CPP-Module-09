/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:06:46 by smarquez          #+#    #+#             */
/*   Updated: 2025/11/05 13:29:04 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cctype>
#include <cstdlib>



class BitcoinExchange
{
    public: 
        BitcoinExchange();
        ~BitcoinExchange();
        
        void loadDatabase(const std::string &filename);
        void processInput(const std::string &filename);
        
        
        private:

        
        //constructores privados para evitar que se usen.
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);

        
        //map
        std::map<std::string, double> _database;

        
        double getPrice(const std::string &date)const; //const porque el metodo no modifica la clase
        bool parseDatabaseLine(const std::string &line, std::string &date, double &price); //cada linea de DB, separa fecha y precio.
        bool parseInputLine(std::string &line, std::string &date, double &value); //validar entrada "date | value"
        bool isValidDate(const std::string &date)const; //fecha correcta
        bool isValidValue(double value)const; // valor entre 0-1000.
        void calculateAndDisplay(const std::string &date, double value)const;
        
        
    };


#endif