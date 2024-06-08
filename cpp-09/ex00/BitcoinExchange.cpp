#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { };

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : map(other.map) {}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		map.clear();
		map = other.map;
	}
	return (*this);
}

void BitcoinExchange::loadData(const std::string& data)
{
	std::ifstream read(data);
	if(!read.is_open())
	{
		std::cerr << "File not found" << std::endl;
		exit(1);
	}

	std::string line;
	if (!std::getline(read, line)) 
	{
        std::cerr << "Error reading header" << std::endl;
        return;
    }
	while(std::getline(read,line))
	{
		std::string key;
		float value;
		std::stringstream is(line);
		if(std::getline(is,key,',') && is >> value)
			map[key] = value;
		else
			std::cerr << "Bad input" << std::endl;
	}
	
	read.close();
}

void BitcoinExchange::printMap()
{
	for(std::map<std::string, float>::iterator it = map.begin(); it != map.end(); it++ )
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

BitcoinExchange::~BitcoinExchange() { }