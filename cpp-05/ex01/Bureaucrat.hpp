#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat{
    private:
        const std::string name;
        int grade; 
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& object);
        Bureaucrat& operator=(const Bureaucrat& object);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        std::string getName();
        int getGrade();
        void increment();
        void decrement();
        void	signForm(Form &other);
};

    std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat);



#endif