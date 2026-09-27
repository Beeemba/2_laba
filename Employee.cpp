#include "Employee.h"

int Employee::objectCount = 0;

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
    ++objectCount;
}
Employee::Employee(const std::string& name, Position pos, double salary, int experience) : name(name), position(pos), salary(salary), experience(experience)
{
    ++objectCount;
}
Employee::Employee(const std::string& name):name(name), position(Position::Intern), salary(0.0), experience(0)
{
    ++objectCount;
}
Employee::~Employee() 
{
    --objectCount;
}

int Employee::getObjectCount() 
{
    return objectCount;
}

std::string Employee::getName() const { return name;}
Position Employee::getPosition() const { return position; }
double Employee::getSalary() const { return salary; }
int Employee::getExperience() const { return experience; }

void Employee::increaseSalary(double amount) 
{
    if (amount < 0) {
        std::cout << "Ошибка! Нельзя уменьшить зарплату через increaseSalary\n";
        return;
    }
    salary += amount;
}

void Employee::changePosition(Position newPos) 
{
    position = newPos;
}

void Employee::increaseExperience(int years) 
{
    if (years < 0) {
        std::cout << "!Ошибка! Стаж не может быть отрицательным\n";
        return;
    }
    experience += years;
}

void Employee::print() const
{
    std::cout << "Сотрудник" << name
    << ", Зарплата: " << salary
    << ", Стаж: " << experience << "\n";
}
