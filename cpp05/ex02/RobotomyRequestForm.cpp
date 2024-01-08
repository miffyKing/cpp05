#include "RobotomyRequestForm.hpp"
#include <cstdlib> // For rand() function
#include <ctime>   // For std::time function

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
    this->_target = ref.getTarget();
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
  std::srand(std::time(nullptr));
  
  if (std::rand() % 2 == 0)
  {
    std::cout << this->_target << " has been robotomized successfully " << std::endl;
  }
  else
  {
    std::cout << this->_target << " has been robotomized failure." << std::endl;
  }
}

std::string RobotomyRequestForm::getTarget() const
{
  return this->_target;
};