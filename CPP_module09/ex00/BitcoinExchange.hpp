#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _prices;
        bool isValidDate(const std::string &date);
        float getClosestPrice(const std::string &date);

    public:
        BitcoinExchange();
        ~BitcoinExchange();

        void loadPrices(std::string filename);
        void processInput(std::string input);
};

#endif