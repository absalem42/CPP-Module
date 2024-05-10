#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
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

Bureaucrat::Bureaucrat() : name("default") , grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) 
{
    if(grade < 1)
        throw GradeTooHighException();
    else if(grade > 150)
        throw GradeTooLowException();  
    else
        this->grade = grade;
}

Bureaucrat::~Bureaucrat() { }

Bureaucrat::Bureaucrat(const Bureaucrat& object) : name(object.name) , grade(object.grade) { }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& object) 
{
    if (this != &object)
    {
        this->grade = object.grade;
        std::cout << "copy succsuful" << std::endl;
    }
    return (*this);       
}


void Bureaucrat::increment()
{
    if(grade > 1)
        grade--;
    else
        throw GradeTooHighException();
}

void Bureaucrat::decrement()
{
    if(grade < 150)
        grade++;
    else
        throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

void	Bureaucrat::signForm(Form &other)
{
	try
	{
		other.beSigned(*this);
		std::cout << name << " signed " << other.getName() << std::endl;

	}
	catch(std::exception &e)
	{
		std::cout << name << " couldn't sign " << other.getName() << " because: " << e.what() << std::endl;
	}
}

