#include "Employee.h"

std::string positionToString(Position pos)
{
    switch (pos)
    {
        case Position::Intern: return "Стажер";
        case Position::Junior: return "Младший специалист";
        case Position::Middle: return "Средний специалист";
        case Position::Senior: return "Старший специалист";
        case Position::Lead: return "Ведущий специалист";
        case Position::Manager: return "Менеджер";
        default: return "Неизвестно";
    }
}

Employee::Employee() : name("Неизвестно"), position(Position::Intern), salary(0.0), experience(0)
{

}
Employee::Employee(const std::string& name, Position pos, double salary, int experience) : name(name), position(pos), salary(salary), experience(experience)
{

}
void Employee::print() const
{
    std::cout << "Сотрудник" << name
    << ", Зарплата: " << salary
    << ", Стаж: " << experience << "\n";
}
