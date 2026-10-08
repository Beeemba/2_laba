#include "Employee.h"

int Employee::objectCount = 0;

Position::Position() : title("Не указана"), baseSalary(0.0) 
{
}

Position::Position(const std::string& title, double baseSalary) 
    : title(title), baseSalary(baseSalary) 
{
    // Защита инварианта: базовая ставка не может быть отрицательной
    if (baseSalary < 0.0) baseSalary = 0.0;  
}

std::string Position::getTitle() const { return title; }
double Position::getBaseSalary() const { return baseSalary; }

void Position::print() const 
{
    std::cout << title << " (базовая ставка: " << baseSalary << ")";
}


bool Employee::isValid() const 
{
    // Проверка инвариантов
    return !name.empty() && salary >= 0 && experience >= 0;
}
Employee::Employee() : name("Неизвестно"), position(), salary(0.0), experience(0)
{
    ++objectCount;
}
Employee::Employee(const std::string& name, const Position& pos, double salary, int experience) : name(name), position(pos), salary(salary), experience(experience)
{
    if (!isValid())
    {
        throw std::invalid_argument("Некорректные данные");
    }
    ++objectCount;
}
Employee::Employee(const std::string& name):name(name), position(), salary(0.0), experience(0)
{
    if (name.empty())
    {
        throw std::invalid_argument("Имя пустое");
    }
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
    if (amount < 0) 
    {
        std::cout << "Ошибка! Нельзя уменьшить зарплату через increaseSalary\n";
        return;
    }
    salary += amount;
}

void Employee::changePosition(const Position& newPos) 
{
    position = newPos;
}

void Employee::increaseExperience(int years) 
{
    if (years < 0) 
    {
        std::cout << "Ошибка! Стаж не может быть отрицательным\n";
        return;
    }
    experience += years;
}

void Employee::print() const
{
    std::cout << "Сотрудник: " << name
    << ", Должность: ";
    position.print();
    std::cout << ", Зарплата: " << salary
    << ", Стаж: " << experience << " лет\n";
}
