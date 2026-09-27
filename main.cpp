#include <iostream>
#include "Employee.h"

int main()
{
    std::cout << "Создание объектов";
    Employee emp1;
    Employee emp2("Василий Пупкин", Position::Middle, 75000.0, 5);
    Employee emp3("Степа Светофоров");
    std::cout << "Создано объектов: " << Employee::getObjectCount() << "\n\n";

    std::cout << "Начальное состояние: ";
    emp1.print();
    emp2.print();
    emp3.print();
    std::cout << "\n";

    std::cout << "Корректные операции\n";
    emp1.increaseSalary(30000);
    emp1.changePosition(Position::Junior);
    emp1.increaseExperience(1);

    emp3.increaseSalary(50000);
    emp3.changePosition(Position::Senior);
    emp3.increaseExperience(10);

    std::cout << "После изменений:\n";
    emp1.print();
    emp2.print();
    emp3.print();
    std::cout << "\n";
    std::cout << "Некорректные операции\n";
    emp2.increaseSalary(-10000);
    emp3.increaseExperience(-5);
    std::cout << "\n";

    std::cout << "Состояние после некорректных операций:\n";
    emp2.print();
    emp3.print();
    std::cout << "(Состояние не изменилось - инварианты соблюдены)\n\n";

    std::cout << "Независимость объектов\n";
    std::cout << "До изменения emp1:\n";
    emp2.print();

    emp1.increaseSalary(100000);
    emp1.changePosition(Position::Manager);
    std::cout << "После изменения emp1 (emp2 не должен измениться):\n";
    emp1.print();
    emp2.print();

    std::cout << "\nВсего объектов: " << Employee::getObjectCount() << "\n";

    return 0;
}