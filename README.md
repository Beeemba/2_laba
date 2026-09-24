# Класс Employee — ООП в C++

Лабораторная работа: моделирование предметной области с использованием классов.

## Сущность: Сотрудник (Employee)

### Поля
- name (std::string) — имя
- position (enum Position) — должность
- salary (double) — зарплата
- experience (int) — стаж

### Методы
- increaseSalary(amount) — повышение зарплаты
- changePosition(pos) — смена должности
- increaseExperience(years) — увеличение стажа
- print() — вывод информации

### Инварианты
- Имя не пустое
- Зарплата >= 0
- Стаж >= 0

## Сборка
g++ -std=c++14 -O2 -Wall Employee.cpp main.cpp -o 2_laba.exe
