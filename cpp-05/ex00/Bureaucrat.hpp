#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>


class Bureaucrat{
    private:
        std::string const name;
        int grade; 
    public:
        std::string getName();
        int getGrade();
        
};

    std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat);






#endif