#include <iostream>
using namespace std;

//чет-нечет сортировка
//по возрастанию
void odd_even_sort_asc(int* mass, int n) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        // Нечетные пары
        for (int i = 1; i < n - 1; i += 2)
            if (mass[i] > mass[i + 1]) {
                swap(mass[i], mass[i + 1]);
                sorted = false;
            }
        // Чётные пары
        for (int i = 0; i < n - 1; i += 2)
            if (mass[i] > mass[i + 1]) {
                swap(mass[i], mass[i + 1]);
                sorted = false;
            }
    }
}

//по убыванию
void odd_even_sort_desc(int* mass, int n) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        // Нечетные пары
        for (int i = 1; i < n - 1; i += 2)
            if (mass[i] < mass[i + 1]) {
                swap(mass[i], mass[i + 1]);
                sorted = false;
            }
        // Чётные пары
        for (int i = 0; i < n - 1; i += 2)
            if (mass[i] < mass[i + 1]) {
                swap(mass[i], mass[i + 1]);
                sorted = false;
            }
    }
}