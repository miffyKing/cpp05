#ifndef Shrub_HPP
#define Shrub_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
  /* data */
  static const std::string _treeOfAscii;
  std::string _target;

  ShrubberyCreationForm();

public:
  ShrubberyCreationForm(std::string target);

  ShrubberyCreationForm(const ShrubberyCreationForm &ref);

  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ref);
  ~ShrubberyCreationForm();

  void execute(const Bureaucrat &bureaucrat) const;
};

#endif // Shrub_HPP
