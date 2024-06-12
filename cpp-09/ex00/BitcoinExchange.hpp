#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP


#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <exception>
#include <iomanip>
#include <sstream>


class BitcoinExchange 

{
    private:
    
        std::map<std::string, float> map;
        // void loadDatabase(const std::string& filename);
        float customStof(const std::string& str) const;
        bool validKey(const std::string& key);
        bool validDate(const std::string& date) const;
        bool isLeapYear(int year) const;
    
    public:
    
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void loadData(const std::string& data);
        void printMap();
        void exchange(const std::string& string);
        // BitcoinExchange(const std::string& dbFilename);

        // void processInput(const std::string& inputFilename) const;

};



#endif