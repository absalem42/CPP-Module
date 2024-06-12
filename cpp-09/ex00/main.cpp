#include "BitcoinExchange.hpp"








int main(int argc, char **argv)
{
    if(argc != 2)
        return (std::cout << "Usage: ./btc <input_file>" << std::endl, 1);
    
    try {
    BitcoinExchange btc;
    btc.loadData("data.csv");
    // btc.printMap();
    btc.exchange(argv[1]);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}