#include <iostream>
#include "Bureaucrat.hpp"

int main()
{

    std::cout<<"test start \n";

    Bureaucrat bu1("name1", 3);

    try
    {
         bu1.incrementGrade();
        std::cout<< "bu1 's grade is " << bu1.getGrade() << "\n";
        bu1.incrementGrade();
        std::cout<< "bu1 's grade is " << bu1.getGrade() << "\n";
        bu1.incrementGrade();
        std::cout<< "bu1 's grade is " << bu1.getGrade() << "\n";
        bu1.incrementGrade();
        std::cout<< "bu1 's grade is " << bu1.getGrade() << "\n";

        bu1.decrementGrade();
        std::cout<< "bu1 's grade is " << bu1.getGrade() << "\n";
        bu1.decrementGrade();
        std::cout<< "bu1 's grade is " << bu1.getGrade() << "\n"; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "================================================================\n";
    
    try
    {
        // GradeTooHighException 발생 테스트
        Bureaucrat bu4("name4", 1);
        bu4.incrementGrade(); // 등급 1 감소 (최소 등급은 1이므로 예외 발생)
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "GradeTooHighException caught: " << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unexpected exception caught: " << e.what() << '\n';
    }


    std::cout << "================================================================\n";

    try
    {
        // GradeTooLowException 발생 테스트
        Bureaucrat bu5("name5", 150);
        bu5.decrementGrade(); // 등급 1 증가 (최대 등급은 150이므로 예외 발생)
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "GradeTooLowException caught: " << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unexpected exception caught: " << e.what() << '\n';
    }

    std::cout << "================================================================\n";

    try
    {
        Bureaucrat bu6("name6", 149);
        bu6.decrementGrade(); // 등급 1 증가 (최대 등급은 150이므로 예외 발생)
        bu6.decrementGrade(); // 등급 1 증가 (최대 등급은 150이므로 예외 발생)
    
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "GradeTooLowException caught: " << e.what() << '\n';
    }

    std::cout << "Test end\n";
    

    return 0;
}