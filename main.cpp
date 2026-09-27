#include <iostream>
#include "Employee.h"

int main()
{
    Employee emp1;
    Employee emp2("Василий Пупкин", Position::Middle, 75000.0, 5);
    Employee emp3("Степа Светофоров");

    emp1.print();
    emp2.print();
    emp3.print();

    std::cout << "\nИмя emp3: " << emp3.getName() << "\n";
        std::cout << "\n--- Корректные операции ---\n";
    emp1.increaseSalary(30000);
    emp1.changePosition(Position::Junior);
    emp1.increaseExperience(1);
    emp1.print();
    
    std::cout << "\n--- Некорректные операции ---\n";
    emp2.increaseSalary(-10000);
    emp3.increaseExperience(-5);
    emp2.print();
    emp3.print();
    return 0;
}