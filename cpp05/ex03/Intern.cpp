#include "Intern.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
  form[0] = "shrubbery creation";
  form[1] = "robotomy request";
  form[2] = "presidential pardon";
}

Intern::Intern(const Intern &ref)
{
  form[0] = ref.form[0];
  form[1] = ref.form[1];
  form[2] = ref.form[2];
}

Intern &Intern::operator=(const Intern &ref)
{
  if (this != &ref)
  {
    form[0] = ref.form[0];
    form[1] = ref.form[1];
    form[2] = ref.form[2];
  }

  return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
  int i;
  for (i = 0; i < 3; ++i)
  {
    if (form[i] == formName)
      break;
  }
  switch (i)
  {
  case 0:
    std::cout << "Intern creates " << formName << " form" << std::endl;
    return (new ShrubberyCreationForm(target));
  case 1:
    std::cout << "Intern creates " << formName << " form" << std::endl;
    return (new RobotomyRequestForm(target));
  case 2 :
  	std::cout << "Intern creates " << formName << " form" << std::endl;
  	return (new PresidentialPardonForm(target));
  default:
    std::cout << "check form name" << std::endl;
  }
  return (NULL);
}