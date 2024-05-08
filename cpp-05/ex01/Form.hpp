#ifndef FORM_HPP
#define FORM_HPP


#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        const std::string name;
        bool is_signed;
        const int grade;
        const int exacute_grade;
    public:
        Form();
        Form(const std::string name, const int grade, const int exeGrade) 
        ~Form();
        Form(const Form& object);
        Form& operator=(const Form& object);
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
        void    beSigned(Bureaucrat &b);
};


std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat);

#endif
