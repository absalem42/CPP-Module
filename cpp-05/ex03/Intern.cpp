#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern() { }

Intern::Intern(const Intern &other) 
{
    (void)other; 
}

Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() { }

const char*   Intern::UnknownFormNameException::what() const throw()
{
	return "Unknown form name";
}

AForm *Intern::makePresidentialPardonForm(const std::string formTarget)
{
	return (new PresidentialPardonForm(formTarget));
}

AForm *Intern::makeRobotomyRequestForm(const std::string formTarget)
{
	return (new RobotomyRequestForm(formTarget));
}

AForm *Intern::makeShrubberyCreationForm(const std::string formTarget)
{
	return (new ShrubberyCreationForm(formTarget));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
    AForm*(Intern::*formFuncs[])(const std::string) = 
    {
		&Intern::makeRobotomyRequestForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makeShrubberyCreationForm
	};
	
	std::string names[] = {
		"presidential pardon", "robotomy request", "shrubbery creation"
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (names[i] == formName)
        {
            std::cout << "Intern creates " << formName << " form" << std::endl;
			return (this->*(formFuncs[i]))(formTarget);
        }
	}
	return (NULL);
}