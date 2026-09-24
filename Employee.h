#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

class Employee 
{
private:
std::string name;
double salary;
int experience;

public:
Employee();
void print() const;
};

#endif