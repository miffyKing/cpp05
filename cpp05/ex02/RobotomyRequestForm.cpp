#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("robotomy", 72, 45), _target("noTarget")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("robotomy", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref)
    : AForm(ref), _target(ref._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
  if (this != &ref)
  {
    dynamic_cast<AForm &>(*this) = dynamic_cast<const AForm &>(ref);
    this->_target = ref._target;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
  this->isExecutable(bureaucrat);
  std::cout << "DRILL" << std::endl;

  std::time_t currentTime = std::time(NULL);
  if (currentTime % 2 == 0)
  {
    std::cout << this->_target << " has been robotomized successfully " << std::endl;
  }
  else
  {
    std::cout << this->_target << " has been robotomized failure." << std::endl;
  }
}