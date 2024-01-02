#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>

class Form
{
public:
    Form(void);

    Form(std::string name, int grade);

    Form(const Form &bur1eaucrat);
    Form &operator=(const Form &ref);
    virtual ~Form();

    
    class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
    };

private:
    const std::string _name;
    int _grade;

};

#endif