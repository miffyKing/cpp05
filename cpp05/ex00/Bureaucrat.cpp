#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void)
    : _name("Bureaucrat"), _grade(1)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name), _grade(grade)
{
  if (grade < 1)
  {
    throw Bureaucrat::GradeTooHighException();
  }
  if (grade > 150)
  {
    throw Bureaucrat::GradeTooLowException();
  }
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
    : _name(bureaucrat.getName()), _grade(bureaucrat.getGrade())
{
  if (_grade < 1)
  {
    throw Bureaucrat::GradeTooHighException();
  }
  if (_grade > 150)
  {
    throw Bureaucrat::GradeTooLowException();
  }
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref)
{
  if (this != &ref)
  {
    /* insert */
    *(const_cast<std::string *>(&_name)) = ref.getName();
    this->_grade = ref.getGrade();
  }
  return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName() const
{
  return this->_name;
}

int Bureaucrat::getGrade() const
{
  return this->_grade;
}

void Bureaucrat::incrementGrade()
{
  if (this->_grade < 2)
  {
    throw Bureaucrat::GradeTooHighException();
  }
  else
    --this->_grade;
}

void Bureaucrat::decrementGrade()
{
  if (this->_grade > 149)
  {
    throw Bureaucrat::GradeTooLowException();
  }
  else
    ++this->_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
  return "Grade is too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
  return "Grade is too low.";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << "Bureaucrat: " << bureaucrat.getName() << ", Grade: " << bureaucrat.getGrade();
    return os;
}