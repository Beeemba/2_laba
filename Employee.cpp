#include "Employee.h"

Employee::Employee() : name("Неизвестно"), salary(0.0), experience(0)
{

}
void Employee::print() const
{
    std::cout << "Сотрудник" << name
    << ", Зарплата: " << salary
    << ", Стаж: " << experience << "\n";
}
