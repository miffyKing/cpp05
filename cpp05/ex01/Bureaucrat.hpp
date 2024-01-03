#ifndef BUREA_H
#define BUREA_H

#include <iostream>
#include <string>
// #include "Form.hpp"

class Form;

class Bureaucrat
{

public:
    Bureaucrat(void);

    Bureaucrat(std::string name, int grade);

    Bureaucrat(const Bureaucrat &bur1eaucrat);
    Bureaucrat &operator=(const Bureaucrat &ref);
    virtual ~Bureaucrat();

    const std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    void signForm(Form &form) const;

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

private:
    const std::string _name;
    int _grade;
};

#endif