
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

void shrubberyTest(Bureaucrat b1, Bureaucrat b4)
{
  std::cout << "ShrubberyCreateForm test" << std::endl;
  // AForm *f1 = new ShrubberyCreationForm("Christmas");
  // AForm *f2 = new ShrubberyCreationForm("Tree");

  Intern dayhyuk;
  AForm *f1 = dayhyuk.makeForm("shrubbery creation", "f3");
  AForm *f2 = dayhyuk.makeForm("shrubbery creation", "f4");

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
  // AForm *f1 = new RobotomyRequestForm("f1");
  // AForm *f2 = new RobotomyRequestForm("f2");
  // // RobotomyRequestForm *f3 = new ShrubberyCreationForm("f3");

  Intern dayhyuk;
  AForm *f1 = dayhyuk.makeForm("robotomy request", "f1");
  AForm *f2 = dayhyuk.makeForm("robotomy request", "f2");

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Grade 20, can sign Robotomy?" << std::endl;
  b3.signForm(*f1);
  std::cout << std::endl;

  std::cout << "Grade 20, can execute Robotomy?" << std::endl;
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

void presidentialTest(Bureaucrat b1, Bureaucrat b2)
{
  std::cout << "PresidentialForm test" << std::endl;
  // AForm *f1 = new PresidentialPardonForm("f1");
  // AForm *f2 = new PresidentialPardonForm("f2");
  Intern dayhyuk;
  AForm *f1 = dayhyuk.makeForm("presidential pardon", "f1");
  AForm *f2 = dayhyuk.makeForm("presidential pardon", "f2");

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Grade 70, can sign Presidential?" << std::endl;
  b2.signForm(*f1);
  std::cout << std::endl;

  std::cout << "Grade 70, can execute Presidential?" << std::endl;
  b2.executeForm(*f1);
  std::cout << std::endl;

  std::cout << "Not signed, can execute Presidential?" << std::endl;
  b1.executeForm(*f2);
  std::cout << std::endl;

  b1.signForm(*f2);
  std::cout << "Signed, can execute Presidential?" << std::endl;

  b1.executeForm(*f2);

  delete f1;
  delete f2;
}

int main(void)
{
  Bureaucrat yback("yback", 1);
  Bureaucrat ejae("ejae", 140);
  // shrubberyTest(yback, ejae);

  Bureaucrat bcho("bcho", 1);    // 사인, 실행 가능
  Bureaucrat dayun("dayun", 70); // 사인 가능, 실행 불가능
  robotomyTest(bcho, dayun);

  Bureaucrat gsong("gsong", 1);      // 사인, 실행 가능
  Bureaucrat sungsoo("sungsoo", 20); // 사인 가능, 실행 불가능
  presidentialTest(gsong, sungsoo);

  system("leaks a.out");
  return 0;
}