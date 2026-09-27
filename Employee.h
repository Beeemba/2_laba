#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

enum class Position
{
    Intern,
    Junior,
    Middle,
    Senior,
    Lead,
    Manager
};
std::string positionToString(Position pos);

class Employee 
{
private:
std::string name;
Position position;
double salary;
int experience;

public:
Employee();
Employee(const std::string& name, Position pos, double salary, int experience);
Employee(const std::string& name);

std::string getName() const;
Position getPosition() const;
double getSalary() const;
int getExperience() const;
void increaseSalary(double amount);
void changePosition(Position newPos);
void increaseExperience(int years);
void print() const;
};

#endif