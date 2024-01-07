
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), _target("noTarget")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) : AForm(ref), _target(ref._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
  if (this == &ref)
    return (*this);
  // 캐스팅해서 넣기
  this->_target = ref.getTarget();
  return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
  this->isExecutable(bureaucrat);
  std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
  return this->_target;
};