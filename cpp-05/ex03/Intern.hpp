#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
class AForm;

class Intern{
    public:
        Intern();
	    Intern(const Intern &other);
	    Intern	&operator=(const Intern &other);
	    ~Intern();
        class UnknownFormNameException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        AForm *makePresidentialPardonForm(const std::string formTarget);
		AForm *makeRobotomyRequestForm(const std::string formTarget);
		AForm *makeShrubberyCreationForm(const std::string formTarget);

        AForm* makeForm(const std::string& formName, const std::string& target);


};






#endif