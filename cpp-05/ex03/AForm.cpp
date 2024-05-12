#include "AForm.hpp"

AForm::AForm() 
    : name("default"), is_signed(false), grade(150), exacute_grade(150) {}

AForm::AForm(const std::string name, const int grade, const int exeGrade) 
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

AForm::AForm(const AForm &other)
	: name(other.name), is_signed(false), grade(other.grade), exacute_grade(other.exacute_grade) { }

AForm& AForm::operator=(const AForm& object) 
{
    if (this != &object)
    {
        this->is_signed = object.is_signed;
    }
    return (*this);       
}

AForm::~AForm() { }



const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char* AForm::FormNotSignedException:: what() const throw()
{
    return "The form is not signed";
}

const char* AForm::FormFileException:: what() const throw()
{
    return "The file is not open";
}

void    AForm::beSigned(Bureaucrat &b)
{
    if(b.getGrade() <= this->grade)
        is_signed = true;
    else
        throw GradeTooLowException();
}

int	AForm::getSignGrade() const
{
	return (grade);
}

int	AForm::getExecuteGrade() const
{
	return (exacute_grade);
}

std::string	AForm::getName() const
{
	return (name);
}

bool	AForm::isFormSigned() const
{
	return (is_signed);
}

// void AForm::execute(Bureaucrat const& executor) const 
// {
//     if (this->isFormSigned() == false)
//         throw FormNotSignedException();
//     if (executor.getGrade() > this->getExecuteGrade())
//         throw GradeTooLowException();
// }

std::ostream	&operator<<(std::ostream &os, const AForm &other)
{
	os	<< "FormName: " << other.getName()
		<< ", FormIsSigned: " << other.isFormSigned()
		<< ", FormSignGrade: " << other.getSignGrade()
		<< ", FormExecuteGrade: " << other.getExecuteGrade() << std::endl;
	return (os);
}

