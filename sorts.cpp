//Шерстнев Максим ИТС-2
#include <iostream>
#include <ctime>
#include "sort.h"
using namespace std;

// Печать содержимого массива
void print_mass(int* mass, int n) {
    for (int i = 0; i < n; i++)
        cout << mass[i] << " ";
    cout << endl;
}

// Генерация случайного массива
void random_mass(int* mass, int n) {
    for (int i = 0; i < n; i++)
        mass[i] = rand() % 1000;
}

int main() {
    setlocale(LC_ALL, "ru"); // Русификация вывода
    int n, sorts, method;

    // Пользователь вводит количество элементов массива
    cout << "Введите количество элементов массива: ";
    cin >> n;

    // Создание динамического массива и заполнение случайными числами
    int* mass = new int[n];
    random_mass(mass, n);

    // Вывод исходного массива
    cout << "Исходный массив: ";
    print_mass(mass, n);

    // Выбор направления сортировки
    cout << "\nМеню сортировок\n";
    cout << "Выберите направление сортировки:\n";
    cout << "1. По убыванию\n";
    cout << "2. По возрастанию\n";
    cout << "3. Выход\n";
    cin >> method;

    // Выбор типа сортировки
    cout << "Выберите алгоритм сортировки:\n";
    cout << "1. Сортировка парным обменом\n";
    cout << "2. Сортировка простым выбором\n";
    cout << "3. Сортировка простыми вставками\n";
    cout << "4. Сортировка Шелла\n";
    cout << "5. Быстрая сортировка\n";
    cout << "6. Поразрядная сортировка\n";
    cin >> sorts;

    // Выполнение выбранных алгоритмов сортировки
    switch (sorts) {
    case 1:
        if (method == 1) {
            radix_sort_desc(mass, n); // Поразрядная сортировка по убыванию
        }
        else {
            radix_sort_asc(mass, n); // Поразрядная сортировка по возрастанию
        }
        break;
    case 2:
        if (method == 1) {
            odd_even_sort_desc(mass, n); // Парная сортировка по убыванию
        }
        else {
            odd_even_sort_asc(mass, n); // Парная сортировка по возрастанию
        }
        break;
    case 3:
        if (method == 1) {
            insertion_sort_desc(mass, n); // Простые вставки по убыванию
        }
        else {
            insertion_sort_asc(mass, n); // Простые вставки по возрастанию
        }
        break;
    case 4:
        if (method == 1) {
            selection_sort_desc(mass, n); // Простой выбор по убыванию
        }
        else {
            selection_sort_asc(mass, n); // Простой выбор по возрастанию
        }
        break;
    case 5:
        if (method == 1) {
            shell_sort_desc(mass, n); // Сортировка Шелла по убыванию
        }
        else {
            shell_sort_asc(mass, n); // Сортировка Шелла по возрастанию
        }
        break;
    case 6:
        if (method == 1) {
            quick_sort_desc(mass, n); // Быстрая сортировка по убыванию
        }
        else {
            quick_sort_asc(mass, n); // Быстрая сортировка по возрастанию
        }
        break;
    default:
        cout << "Ошибка ввода.\n";
        delete[] mass;
        return 1;
    }

    // Вывод результата сортировки
    cout << "Отсортированный массив: ";
    print_mass(mass, n);

    // Очистка памяти
    delete[] mass;

    return 0;
}

