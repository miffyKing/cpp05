#ifndef Robot_HPP
#define Robot_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

private:
  /* data */
  std::string _target;

  RobotomyRequestForm(); // 기본생성자를 private으로 막아놓음.

public:
  RobotomyRequestForm(std::string target);

  RobotomyRequestForm(const RobotomyRequestForm &ref);

  RobotomyRequestForm &operator=(const RobotomyRequestForm &ref);
  ~RobotomyRequestForm();

  void execute(const Bureaucrat &bureaucrat) const;
};

#endif // Robot_HPP