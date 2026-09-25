#include <iostream>
#include "Employee.h"

int main()
{
    Employee emp1;
    Employee emp2("Василий Пупкин", Position::Middle, 75000.0, 5);
    emp1.print();
    emp2.print();

    return 0;
}