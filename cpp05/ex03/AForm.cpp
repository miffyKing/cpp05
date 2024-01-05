#include "AForm.hpp"
#include <iostream>

AForm::AForm(void) : _name("default"), _signed(false), _signGrade(75), _execGrade(75) {}

AForm::AForm(const std::string name, const int signGrade, const int executeGrade)
    : _name(name), _signed(false), _signGrade(signGrade), _execGrade(executeGrade)
{
  if (this->_signGrade < 1 || this->_execGrade < 1)
    throw AForm::GradeTooHighException();
  if (this->_signGrade > 150 || this->_execGrade > 150)
    throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &bur1eaucrat) : _name(bur1eaucrat._name), _signed(bur1eaucrat._signed), _signGrade(bur1eaucrat._signGrade), _execGrade(bur1eaucrat._execGrade) {}

AForm &AForm::operator=(const AForm &ref)
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

AForm::~AForm() {}

const std::string AForm::getName() const
{
  return this->_name;
}

bool AForm::getSigned() const
{
  return this->_signed;
}

int AForm::getSignGrade() const
{
  return this->_signGrade;
}

int AForm::getExecGrade() const
{
  return this->_execGrade;
}

void AForm::beSigned(Bureaucrat bureaucrat)
{
  if (bureaucrat.getGrade() <= this->getSignGrade())
  {
    std::cout << "Signing AForm ...\n";
    this->_signed = true;
  }
  else
  {
    throw GradeTooHighException();
  }
}

void AForm::isExecutable(const Bureaucrat &bureaucrat) const
{
  if (this->getSigned() == false)
    throw AForm::NotSignedException();
  if (this->getExecGrade() < bureaucrat.getGrade())
    throw AForm::CouldNotExecuteException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
  return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
  return "Grade is too low";
}

const char *AForm::NotSignedException::what() const throw()
{
  return "Form is not signed";
}

const char *AForm::CouldNotExecuteException::what() const throw()
{
  return "Could not execute. Grade Too Low";
}
