#include "Form.hpp"
#include <iostream>

Form::Form(void) : _name("default"), _signed(false), _signGrade(75), _execGrade(75) {}

Form::Form(const std::string name, const int signGrade, const int executeGrade)
    : _name(name), _signed(false), _signGrade(signGrade), _execGrade(executeGrade)
{
  if (this->_signGrade < 1 || this->_execGrade < 1)
    throw Form::GradeTooHighException();
  if (this->_signGrade > 150 || this->_execGrade > 150)
    throw Form::GradeTooLowException();
}

Form::Form(const Form &bur1eaucrat) : _name(bur1eaucrat._name), _signed(bur1eaucrat._signed), _signGrade(bur1eaucrat._signGrade), _execGrade(bur1eaucrat._execGrade) {}

Form &Form::operator=(const Form &ref)
{
  if (this != &ref)
  {
    *(const_cast<std::string *>(&this->_name)) = ref.getName();
    *(const_cast<int *>(&this->_signGrade)) = ref.getSignGrade();
    *(const_cast<int *>(&this->_execGrade)) = ref.getExecGrade();
    this->_signed = ref.getSigned();
  }
  return *this;
}

Form::~Form() {}

const std::string Form::getName() const
{
  return _name;
}

bool Form::getSigned() const
{
  return _signed;
}

int Form::getSignGrade() const
{
  return _signGrade;
}

int Form::getExecGrade() const
{
  return _execGrade;
}

void Form::beSigned(Bureaucrat bureaucrat)
{
  if (bureaucrat.getGrade() <= this->getSignGrade())
  {
    this->_signed = true;
  }
  else
  {
    throw GradeTooHighException();
  }
}

const char *Form::GradeTooHighException::what() const throw()
{
  return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
  return "Grade is too low";
}
