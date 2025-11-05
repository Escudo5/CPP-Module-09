/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:59:15 by smarquez          #+#    #+#             */
/*   Updated: 2025/11/05 15:05:52 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: invalid argument number " << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    btc.loadDatabase("data.csv");
    btc.processInput(argv[1]);
    return 0;
}