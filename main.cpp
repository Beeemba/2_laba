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
    return 0;
}