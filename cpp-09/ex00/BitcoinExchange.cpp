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
	std::ifstream read(data.c_str());
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

void BitcoinExchange::exchange(const std::string& string)
{
	std::ifstream input(string.c_str());

	if(!input.is_open())
		std::cerr << "File not found" << std::endl;
	
	std::string line;
	std::getline(input, line);

	while(getline(input, line))
	{

	std::istringstream iss(line);
    std::string key, delimiter, numberStr;

    // Extract the date, delimiter, and number parts
	float value = 0.0;
    iss >> key >> delimiter >> numberStr;

	if (delimiter != "|")
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		continue;
	}
	try 
    {
        value = customStof(numberStr);
    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << line << std::endl;
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

	if (key.length() != 10 ) 
    {
        std::cerr << "Error: invalid date => " << line << std::endl;
        continue;
    }
	if (validKey(key) == false || validDate(key) == false) 
	{
		std::cerr << "Error: invalid date => " << line << std::endl;
		continue;
	}

	std::map<std::string, float>::const_iterator it = map.lower_bound(key);
        if (it != map.end() && it->first == key) 
            std::cout << key << " => " << value << " = " << value * it->second << std::endl;
        
        else if (it != map.begin()) 
        {
            --it;
            std::cout << key << " => " << value << " = " << value * it->second << std::endl;
        } 
        else
            std::cerr << "Error: key not found in database." << std::endl;
	}
	input.close();
}

bool BitcoinExchange::validDate(const std::string& date) const 
{
	std::stringstream ss(date);

	int year, month, day;
    year = std::atof(date.substr(0, 4).c_str());
    month = std::atof(date.substr(5, 2).c_str());
    day = std::atof(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1) 
		return false;

    const int daysInMonth[] = {31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day > daysInMonth[month - 1]) return false;

    return true;
}

bool BitcoinExchange::isLeapYear(int year) const 
{
    if (year % 4 != 0) 
		return false;
    if (year % 100 != 0) 
		return true;
    if (year % 400 != 0) 
		return false;
    return true;
}
bool BitcoinExchange::validKey(const std::string& key)
{
	for (size_t i = 0; i < key.length(); i++) 
	{
		if (i == 4 || i == 7) 
		{
			if (key[i] != '-') 
			{
				return false;
			}
		} 
		else if (!std::isdigit(key[i])) 
		{
			return false;
		}
	}
	return true;
}

float BitcoinExchange::customStof(const std::string& str) const 
{
    std::string processedStr = str;

    // Remove the trailing 'f' if it exists
    if (!processedStr.empty() && processedStr[processedStr.size() - 1] == 'f') 
    {
        processedStr.erase(processedStr.size() - 1); // Use erase instead of pop_back for C++98
    }

    std::istringstream iss(processedStr);
    float result;
    iss >> result;

    // Check for any remaining characters after the float value
    if (iss.fail() || !iss.eof()) 
    {
        throw std::invalid_argument("Error: bad float input => " + str);
    }
    return result;
}

void BitcoinExchange::printMap()
{
	for(std::map<std::string, float>::iterator it = map.begin(); it != map.end(); it++ )
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

BitcoinExchange::~BitcoinExchange() { }