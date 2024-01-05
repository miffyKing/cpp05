#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class Intern
{
private:
  std::string form[3];

public:
  Intern();
  Intern(const Intern &ref);
  Intern &operator=(const Intern &ref);
  ~Intern();

  AForm *makeForm(std::string formName, std::string target);  //AForm 으ㅣ 포인터를 리턴하는 함수
};

#endif