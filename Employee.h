#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
/**
 * @brief Должности сотрудников
 */
enum class Position
{
    Intern,
    Junior,
    Middle,
    Senior,
    Lead,
    Manager
};
/**
 * @brief Перевод enum в строку
 */
std::string positionToString(Position pos);
/**
 * @brief Класс сотрудника компании
 * @details Инварианты: имя не пустое, зарплата >= 0, стаж >= 0
 */
class Employee 
{
private:
std::string name;
Position position;
double salary;
int experience;

static int objectCount;
/**
     * @brief Проверка инвариантов
     * @return true если корректно
     */
    bool isValid() const;
public:
// --- Конструкторы ---
/**
     * @brief Конструктор по умолчанию
     * @details Создает "Неизвестно", Intern, 0, 0
     */
Employee();
/**
     * @brief Параметризованный конструктор
     * @param name Имя
     * @param pos Должность
     * @param salary Зарплата
     * @param experience Стаж
     * @throws std::invalid_argument если данные некорректны
     */
Employee(const std::string& name, Position pos, double salary, int experience);
/**
     * @brief Конструктор только с именем
     * @param name Имя
     * @throws std::invalid_argument если имя пустое
     */
Employee(const std::string& name);
/**
     * @brief Деструктор
     * @details Уменьшает счетчик объектов
     */
~Employee();
// --- Геттеры ---
std::string getName() const;
Position getPosition() const;
double getSalary() const;
int getExperience() const;
// --- Методы изменения состояния ---

    /**
     * @brief Повысить зарплату
     * @param amount Сумма прибавки (должна быть >= 0)
     * @note Игнорирует отрицательные значения
     */
void increaseSalary(double amount);
/**
     * @brief Сменить должность
     * @param newPos Новая должность
     */
void changePosition(Position newPos);
/**
     * @brief Увеличить стаж
     * @param years Количество лет (должно быть >= 0)
     * @note Игнорирует отрицательные значения
     */
void increaseExperience(int years);
// --- Вывод ---
    /**
     * @brief Вывести информацию о сотруднике
     */
void print() const;
// --- Статические методы ---
    /**
     * @brief Получить количество живых объектов
     * @return Число объектов
     */
static int getObjectCount();
};

#endif