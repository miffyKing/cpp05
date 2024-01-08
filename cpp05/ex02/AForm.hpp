#ifndef AForm_H
#define AForm_H

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

// class Bureaucrat;

class AForm
{
public:
    AForm(void);
    AForm(const std::string name, const int signGrade, const int executeGrade);
    AForm(const AForm &bureaucrat);
    AForm &operator=(const AForm &ref);
    virtual ~AForm();

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
    class NotSignedException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class CouldNotExecuteException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    const std::string getName() const; // const 는 이 함수에서 변경하지 않겠다는것 의미.
    bool getSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;
    void beSigned(Bureaucrat bureaucrat);
    void isExecutable(const Bureaucrat &bureaucrat) const;

    virtual void execute(const Bureaucrat &executor) const = 0;

private:
    const std::string _name;
    bool _signed;
    const int _signGrade;
    const int _execGrade;
};

std::ostream &operator<<(std::ostream &os, const AForm &aform);
#endif