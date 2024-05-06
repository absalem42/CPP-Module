#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << "bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return os;
}

std::string Bureaucrat::getName()
{
    return(this->name);
}

int Bureaucrat::getGrade()
{
    return(this->grade);
}