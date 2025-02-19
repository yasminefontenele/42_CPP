#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _prices;
        boll isValidDate(const std::string &date);
        float getClosestPrice(const std::string &date);

    public:
        BitcoinExchange();
        ~BitcoinExchange();

        void loadPrices(std::string filename);// Load prices from a file
        void processInput(std::string input);// Process input from the file
};

#endif