#ifndef AFORM_HPP
#define AFORM_HPP


#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
        const std::string name;
        bool is_signed;
        const int grade;
        const int exacute_grade;
    public:
        AForm();
        AForm(const std::string name, const int grade, const int exeGrade);
        AForm(const AForm &other);
        AForm& operator=(const AForm& object);
        virtual ~AForm();
        
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
        class FormNotSignedException : public std::exception
        {
            public:
	            virtual const char	*what() const throw();
        };

        class FormFileException : public std::exception
        {
            public:
	            virtual  const char	 *what() const throw();
        };
        void    beSigned(Bureaucrat &b);
        int			getSignGrade() const;
	    int			getExecuteGrade() const;
        std::string	getName() const;
        bool	isFormSigned() const;

       virtual void execute(Bureaucrat const& executor) const = 0;
};


std::ostream& operator<<(std::ostream& o, const AForm& form);

#endif
