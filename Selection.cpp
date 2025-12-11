#include <iostream>
using namespace std;

//сортировка выбором
//по возрастанию
void selection_sort_asc(int* mass, int n) {
    for (int i = 0; i < n - 1; i++) { // Проходим по всем элементам массива
        int min_index = i; // Предполагаемый минимум - текущий элемент

        for (int j = i + 1; j < n; j++) { // Проверяем оставшиеся элементы
            if (mass[j] < mass[min_index]) { // Если нашли элемент меньше текущего минимума
                min_index = j; // Обновляем индекс минимального элемента
            }
        }

        if (min_index != i) { // Если нашли новый минимум
            int temp = mass[i]; // Меняем местами текущий элемент и минимум
            mass[i] = mass[min_index];
            mass[min_index] = temp;
        }
    }
}

//по убыванию
void selection_sort_desc(int* mass, int n) {
    for (int i = 0; i < n - 1; i++) { // Проходим по всем элементам массива
        int max_index = i; // Предполагаемый максимум - текущий элемент

        for (int j = i + 1; j < n; j++) { // Проверяем оставшиеся элементы
            if (mass[j] > mass[max_index]) { // Если нашли элемент больше текущего максимума
                max_index = j;                              // Обновляем индекс максимального элемента
            }
        }

        if (max_index != i) { // Если нашли новый максимум
            int temp = mass[i]; // Меняем местами текущий элемент и максимум
            mass[i] = mass[max_index];
            mass[max_index] = temp;
        }
    }
}
