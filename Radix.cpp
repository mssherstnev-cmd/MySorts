#include <iostream>
using namespace std;

//поразрядная сортировка
int getMax(int* mass, int n) {
    int max = mass[0];
    for (int i = 1; i < n; i++) {
        if (mass[i] > max) {
            max = mass[i];
        }
    }
    return max;
}

void radix_sort_asc(int* mass, int n) { //возрастание
    if (n <= 1) return;              // Выход, если массив пустой или содержит один элемент

    int max = getMax(mass, n);       // Максимальное число в массиве
    int* temp = new int[n];          // Вспомогательный массив

    // Сортировка по каждому разряду (от единицы до старшего разряда)
    for (int exp = 1; max / exp > 0; exp *= 10) {
        int count[10] = { 0 };       // Частоты цифр от 0 до 9

        // Подсчет частот цифр в текущем разряде
        for (int i = 0; i < n; i++)
            count[(mass[i] / exp) % 10]++;

        // Накопление частичных сумм
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Запись элементов в вспомогательный массив
        for (int i = n - 1; i >= 0; i--)
            temp[count[(mass[i] / exp) % 10]--] = mass[i];

        // Копируем обратно в основной массив
        for (int i = 0; i < n; i++)
            mass[i] = temp[i];
    }
    delete[] temp;                 // Освобождаем память
}

void radix_sort_desc(int* mass, int n) {  // убывание
    if (n <= 1) return;               // Выход, если массив пустой или содержит один элемент

    int max = getMax(mass, n);        // Максимальное число в массиве
    int* temp = new int[n];           // Вспомогательный массив

    // Сортировка по каждому разряду (от единицы до старшего разряда)
    for (int exp = 1; max / exp > 0; exp *= 10) {
        int count[10] = { 0 };        // Частоты цифр от 0 до 9

        // Подсчет частот цифр в текущем разряде
        for (int i = 0; i < n; i++)
            count[(mass[i] / exp) % 10]++;

        // Накопление частичных сумм в обратном порядке
        for (int i = 8; i >= 0; i--)
            count[i] += count[i + 1];

        // Запись элементов в вспомогательный массив
        for (int i = n - 1; i >= 0; i--)
            temp[count[(mass[i] / exp) % 10]--] = mass[i];

        // Копируем обратно в основной массив
        for (int i = 0; i < n; i++)
            mass[i] = temp[i];
    }
    delete[] temp;                   // Освобождаем память
}
