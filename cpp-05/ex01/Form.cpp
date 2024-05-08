#include "Form.h"

Form::Form() : name("default") , grade(1) {}

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
    else
        this->grade = grade;
}



Form::Form(const Form& object) 
: name(object.name),
     grade(object.grade),
    is_signed(object.is_signed),
    exacute_grade(other.exacute_grade)  { }

Form& Form::operator=(const Form& object) 
{
    if (this != &object)
    {
        this->grade = object.grade;
        this->is_signed = object.is_signed;
    }
    return (*this);       
}

Form::~Form() { }

std::ostream& operator<<(std::ostream& os, Form& Form)
{
    os << Form.getName() << ", Form grade " << Form.getGrade() << std::endl;
    return os;
}



