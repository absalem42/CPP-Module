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

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
  std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
  for (int i = 0; i < 3; i++)
  {
    if (formName == names[i])
    {
      std::cout << "Intern creates " << names[i] << " form" << std::endl;
      switch (i)
      {
        case 0:
          return new ShrubberyCreationForm(formTarget);
        case 1:
          return new RobotomyRequestForm(formTarget);
        case 2:
          return new PresidentialPardonForm(formTarget);
        default:
          return NULL;
      }
    }
  }
  throw UnknownFormNameException();
}