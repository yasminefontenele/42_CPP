#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadPrices(std::string filename)
{
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        float price;

        if (std::getline(ss, date, ',') && ss >> price)
            _prices[date] = price;
    }
    file.close();
}

void BitcoinExchange::processInput(std::string input)
{
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: could not open input file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, separator;
        float value;

        if (!(std::getline(ss, date, ' ') && std::getline(ss, separator, '|') && ss >> value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        float price = getClosestPrice(date);
        std::cout << date << " => " << value << " = " << (value * price) << std::endl;
    }
    file.close();
}

/*
lower_bound é um método de std::map que retorna um iterador para o primeiro elemento cuja chave
não é menor que a chave fornecida.
*/
float BitcoinExchange::getClosestPrice(const std::string& date)
{
    std::map<std::string, float>::iterator it = _prices.lower_bound(date);
    if (it == _prices.begin() && it->first != date)
    {
        std::cerr << "Error: no available exchange rate for date " << date << std::endl;
        return 0.0;
    }
    if (it == _prices.end() || it->first != date)
        --it;
    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')// Verifica se a data tem o formato yyyy-mm-dd
        return false;

    // Extraindo ano, mês e dia
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;

    // Verifica os dias válidos para cada mês
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Ajusta fevereiro para anos bissextos
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}
