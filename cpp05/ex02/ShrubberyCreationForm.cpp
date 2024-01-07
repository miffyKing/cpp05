#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::_treeOfAscii = "\
  ,      ,      ,,   ,\n\
      ,  *      ,     ,\n\
,       * *       ,   \n\
    o *  * * *  ,     ,\n\
  * **o * . * **    ,\n\
  **|*** . . * **     ,\n\
 , **** .| |. ****     \n\
     * **| |**   ,\n\
         | |      , \n\
-^-o^-o----^-^-o----^--\n\
";

/*
 * A default constructor
 */
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("shrubbery", 145, 137), _target("noTarget")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("shrubbery", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref)
    : AForm(ref), _target(ref._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
  if (this != &ref)
  {
    this->_target = ref.getTarget();
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget() const
{
  return this->_target;
};

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
  this->isExecutable(bureaucrat);
  std::ofstream writeFile((_target + "_shrubbery").c_str(), std::ios::out | std::ios::app);
  if (writeFile.is_open())
  {
    writeFile << this->_treeOfAscii;
    writeFile.close();
  }
}