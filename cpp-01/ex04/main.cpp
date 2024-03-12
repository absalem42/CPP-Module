#include <iostream>
#include <fstream>
#include <string>

// void    strReplace(char **argv)
// {
//     std::ifstream	fileIn;
    
//     std::string filename = argv[1];
//     std::string s1 = argv[2];
//     std::string s2 = argv[3];
//     std::string fileReplace = filename + ".replace";
//     std::string line;
//     fileIn.open(filename, std::ios::in);
//     if(!fileIn.is_open())
//         return (std::cerr << "Error: Unable to open the file\n");
//     std::string fileContent;
//     std::getline(fileIn, line);
//     fileContent += line;
//     while(!fileIn.eof())
//     {
//         std::getline(fileIn, line);
//         fileContent += "\n" + line;
//     }
//     // std::cout << fileContent ;
    
//     int position = fileContent.find(s1);
//     while (position != std::string::npos)
//     {
//         fileContent.erase(position, s1.length());
//         fileContent.insert(position,s2);
//         position = fileContent.find(s1);
       
//     }
//      std::cout << "\n" << fileContent << std::endl;
//     // else 
//     //     std::cout << "String not find" << std::endl;

//     fileIn.close();
// }

// int main(int argc, char **argv)
// {

//     if (argc == 4)
//         strReplace(argv);
//     else
//         return(std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n", 1);

    
// }




void replaceOccurrences(std::string& content, const std::string& s1, const std::string& s2) {
    size_t position = content.find(s1);

    while (position != std::string::npos)
    {
        content.erase(position, s1.length());
        content.insert(position,s2);
        position = content.find(s1);
    }
}

std::string readFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    
    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open the file\n";
        exit(1); 
    }
    std::string line;
    // std::string content;
    std::getline(inFile, line, '\0');
    // content += line;
    // while(!inFile.eof() )
    // {
    //     std::getline(inFile, line);
    //     content += "\n" + line;
    // }
    inFile.close();

    return line;
}

void writeToFile(const std::string& filename, const std::string& content) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to create the output file\n";
        exit(1); // indicate error
    }

    outFile << content;
    outFile.close();
}

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return 1; // indicate error
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty())
	{
		std::cout << "Error: Empty string" << std::endl;
		return (1);
	}
    if (s2.empty())
	{
		std::cout << "Error: Empty string" << std::endl;
		return (1);
	}
    // Read content from the input file
    std::string content = readFromFile(filename);

    // Replace occurrences of s1 with s2
    replaceOccurrences(content, s1, s2);

    // Write the modified content to the output file
    std::string outFile = filename + ".replace";
    writeToFile(outFile, content);

    std::cout << "Replacement completed. Output written to: " << outFile << std::endl;

    return 0; // indicate success
}