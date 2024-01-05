#ifndef Presi_HPP
#define Presi_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
  /* data */
  std::string _target;

  PresidentialPardonForm(); // 기본생성자를 private으로 막아놓음.

public:
  PresidentialPardonForm(std::string target);

  PresidentialPardonForm(const PresidentialPardonForm &ref);

  PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);
  ~PresidentialPardonForm();

  void execute(const Bureaucrat &bureaucrat) const;
};

#endif