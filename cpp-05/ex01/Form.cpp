#include "Form.hpp"

Form::Form() 
    : name("default"), is_signed(false), grade(150), exacute_grade(150) {}

Form::Form(const std::string name, const int grade, const int exeGrade) 
: name(name), 
    is_signed(false),
    grade(grade),
    exacute_grade(exeGrade)
{
    if(grade < 1 || exeGrade < 1)
        throw GradeTooHighException();
    else if(grade > 150 || exeGrade > 150)
        throw GradeTooLowException();  
}

Form::Form(const Form &other)
	: name(other.name), is_signed(false), grade(other.grade), exacute_grade(other.exacute_grade) { }

Form& Form::operator=(const Form& object) 
{
    if (this != &object)
    {
        this->is_signed = object.is_signed;
    }
    return (*this);       
}

Form::~Form() { }



const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

void    Form::beSigned(Bureaucrat &b)
{
    if(b.getGrade() <= this->grade)
        is_signed = true;
    else
        throw GradeTooLowException();
}

int	Form::getSignGrade() const
{
	return (grade);
}

int	Form::getExecuteGrade() const
{
	return (exacute_grade);
}

std::string	Form::getName() const
{
	return (name);
}

bool	Form::isFormSigned() const
{
	return (is_signed);
}

std::ostream	&operator<<(std::ostream &os, const Form &other)
{
	os	<< "FormName: " << other.getName()
		<< ", FormIsSigned: " << other.isFormSigned()
		<< ", FormSignGrade: " << other.getSignGrade()
		<< ", FormExecuteGrade: " << other.getExecuteGrade() << std::endl;
	return (os);
}

