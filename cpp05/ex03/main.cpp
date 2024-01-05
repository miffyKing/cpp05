
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

void shrubberyTest(Bureaucrat b1, Bureaucrat b4)
{
  std::cout << "ShrubberyCreateForm test" << std::endl;
  AForm *f1 = new ShrubberyCreationForm("Christmas");
  AForm *f2 = new ShrubberyCreationForm("Tree");

  std::cout << std::endl;

  std::cout << "Grade 140, can sign Shrubbery?" << std::endl;
  b4.signForm(*f1);
  std::cout << std::endl;
  std::cout << "Grade 140, can execute Shrubbery?" << std::endl;
  b4.executeForm(*f1);
  std::cout << std::endl;
  std::cout << "Not signed, can execute Shrubbery?" << std::endl;
  b1.executeForm(*f2);
  std::cout << std::endl;

  b1.signForm(*f2);
  std::cout << "Signed, can execute Shrubbery?" << std::endl;
  b1.executeForm(*f2);

  delete f1;
  delete f2;
}

void robotomyTest(Bureaucrat b1, Bureaucrat b3) // 1,140
{
  std::cout << "RobotomyRequestForm test" << std::endl;
  AForm *f1 = new RobotomyRequestForm("f1");
  AForm *f2 = new RobotomyRequestForm("f2");
  // RobotomyRequestForm *f3 = new ShrubberyCreationForm("f3");

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Grade 70, can sign Robotomy?" << std::endl;
  b3.signForm(*f1);
  std::cout << std::endl;

  std::cout << "Grade 70, can execute Robotomy?" << std::endl;
  b3.executeForm(*f1);
  std::cout << std::endl;

  std::cout << "Not signed, can execute Robotomy?" << std::endl;
  b1.executeForm(*f2);
  std::cout << std::endl;
  std::cout << "Signed, can execute Robotomy?" << std::endl;
  b1.signForm(*f2);
  b1.executeForm(*f2);

  delete f1;
  delete f2;
}

int main(void)
{
  Bureaucrat yback("yback", 1);
  Bureaucrat ejae("ejae", 140);
  // shrubberyTest(b1, b4);

  Bureaucrat bcho("bcho", 1);
  Bureaucrat dayun("dayun", 70);
  robotomyTest(bcho, dayun);

  system("leaks a.out");
  return 0;
}