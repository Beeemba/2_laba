/**
 * @file main.cpp
 * @brief Демонстрация классов Employee и Position
 * @details Тестирование конструкторов, методов, инвариантов и композиции
 */
#include <iostream>
#include "Employee.h"

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    std::cout << "Создание объектов\n";
    
    // Создаем объекты должностей с названием и базовой ставкой
    Position posMiddle("Средний специалист", 60000.0);
    Position posSenior("Старший специалист", 90000.0);

    Employee emp1;
    // Зарплата 75000 корректна, т.к. она >= 60000 (базовой ставки posMiddle)
    Employee emp2("Василий Пупкин", posMiddle, 75000.0, 5);
    Employee emp3("Степа Светофоров");
    
    std::cout << "Создано объектов: " << Employee::getObjectCount() << "\n\n";

    std::cout << "Начальное состояние: \n";
    emp1.print();
    emp2.print();
    emp3.print();
    std::cout << "\n";

    std::cout << "Корректные операции\n";
    emp1.increaseSalary(30000);
    emp1.changePosition(Position("Младший специалист", 40000.0)); 
    emp1.increaseExperience(1);

    emp3.increaseSalary(50000);
    emp3.changePosition(posSenior);
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
    emp1.changePosition(Position("Менеджер", 120000.0));
    std::cout << "После изменения emp1 (emp2 не должен измениться):\n";
    emp1.print();
    emp2.print();

    std::cout << "\nВсего объектов: " << Employee::getObjectCount() << "\n";

    return 0;
}