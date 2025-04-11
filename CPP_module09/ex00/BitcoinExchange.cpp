#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

// Load prices from a file into a map
void BitcoinExchange::loadPrices(std::string filename)
{
    std::ifstream file(filename.c_str());

    if (!file)
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip the header line
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

// Process input from a file and calculate the exchange rate
void BitcoinExchange::processInput(std::string filename)
{
    std::ifstream file(filename.c_str());

    if (!file)
    {
        std::cerr << "Error: could not open input file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
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


float BitcoinExchange::getClosestPrice(const std::string& date)
{
    std::map<std::string, float>::iterator it = _prices.lower_bound(date);

    if (it == _prices.begin() && it->first != date)
        return it->second;

    if (it == _prices.end() || it->first != date)
        --it;

    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    // check if the date is in the format YYYY-MM-DD
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    char sep1, sep2;
    std::istringstream iss(date);
    iss >> year >> sep1 >> month >> sep2 >> day;

    if (sep1 != '-' || sep2 != '-' || iss.fail() || !iss.eof())
        return false;

    if (year < 0 || month < 1 || month > 12 || day < 1)
        return false;

    // check the number of days in the month
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Adjust February for leap years
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}
