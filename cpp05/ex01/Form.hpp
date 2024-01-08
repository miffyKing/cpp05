#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

// class Bureaucrat;

class Form
{
public:
    Form(void);
    Form(const std::string name, const int signGrade, const int executeGrade);
    Form(const Form &bureaucrat);
    Form &operator=(const Form &ref);
    ~Form();

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    const std::string getName() const; // const 는 이 함수에서 변경하지 않겠다는것 의미.
    bool getSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;
    void beSigned(Bureaucrat bureaucrat);

private:
    const std::string _name;
    bool _signed;
    const int _signGrade;
    const int _execGrade;
};

std::ostream &operator<<(std::ostream &os, const Form &form);
#endif