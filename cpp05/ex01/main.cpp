#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "Test Start \n";

    try
    {
        Bureaucrat bu1("Bureaucrat1", 2);
        Form form1("Form1", 3, 3); // 서명 등급과 실행 등급이 3인 양식

        std::cout << "bu1's grade: " << bu1.getGrade() << "\n";
        std::cout << "form1 is signed: " << form1.getSigned() << "\n";

        bu1.signForm(form1); // bu1이 form1에 서명 시도
        std::cout << "After signing attempt, form1 is signed: " << form1.getSigned() << "\n";

        Bureaucrat bu2("Bureaucrat2", 4);
        Form form2("Form2", 3, 3); // 서명 등급과 실행 등급이 3인 양식

        std::cout << "bu2's grade: " << bu2.getGrade() << "\n";
        std::cout << "form2 is signed: " << form2.getSigned() << "\n";

        bu2.signForm(form2); // bu2가 form2에 서명 시도 (실패 예상)
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }

    std::cout << "================================================================\n";

    try
    {
        Form form3("Form3", 0, 5); // 서명 등급이 너무 높음 (예외 발생 예상)
    }
    catch (const Form::GradeTooHighException &e)
    {
        std::cerr << "Form GradeTooHighException caught: " << e.what() << '\n';
    }

    std::cout << "================================================================\n";

    try
    {
        // GradeTooLowException for Form 발생 테스트
        Form form4("Form4", 151, 5); // 서명 등급이 너무 낮음 (예외 발생 예상)
    }
    catch (const Form::GradeTooLowException &e)
    {
        std::cerr << "Form GradeTooLowException caught: " << e.what() << '\n';
    }

    std::cout << "Test End\n";

    return 0;
}
