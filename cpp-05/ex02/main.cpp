#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



int main(void)
{
	try
	{
		Bureaucrat	bureaucrat("john", 40);
		std::cout << bureaucrat;
		

		ShrubberyCreationForm	shrubbery("Home");
		std::cout << shrubbery;

		bureaucrat.signAForm(shrubbery);
		bureaucrat.executeForm(shrubbery);


		// RobotomyRequestForm	robotomy("Robot");
		// std::cout << robotomy;

		// bureaucrat.signAForm(robotomy);
		// bureaucrat.executeAForm(robotomy);


		// PresidentialPardonForm	presidential("President");
		// std::cout << presidential;

		// bureaucrat.signAForm(presidential);
		// bureaucrat.executeAForm(presidential);
		
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}