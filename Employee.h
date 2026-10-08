#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
/**
 * @brief Класс должности сотрудника
 * @details Инвариант: уровень (level) не может быть отриц
 */
/**
 * @brief Класс должности сотрудника
 * @details Инвариант: базовая ставка не может быть отрицательной
 */
class Position
{
private:
    std::string title;      ///< Название должности
    double baseSalary;      ///< Минимальная зарплата для этой должности

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Position();

    /**
     * @brief Параметризованный конструктор
     * @param title Название должности
     * @param baseSalary Базовая ставка
     */
    Position(const std::string& title, double baseSalary);

    std::string getTitle() const;    ///< Получить название
    double getBaseSalary() const;    ///< Получить базовую ставку
    void print() const;              ///< Вывод должности
};
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
Employee(const std::string& name, const Position& pos, double salary, int experience);
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
void changePosition(const Position& newPos);
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