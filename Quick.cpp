#include <iostream>
using namespace std;

//Быстрая сортировка
void vremen(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int LeftRight(int* mass, int low, int high) {
    int pivot = mass[high]; // Опорный элемент выбирается последним элементом массива
    int i = low - 1;       // Индекс перед первым элементом

    for (int j = low; j < high; j++) { // Проход по массиву от начала до предпоследнего элемента
        if (mass[j] <= pivot) {      // Если текущий элемент меньше или равен опорному
            i++;                    // Увеличиваем индекс
            vremen(mass[i], mass[j]); // Меняем местами элементы 
        }
    }
    vremen(mass[i + 1], mass[high]); // Ставим опорный элемент на своё место
    return i + 1;                   // Возвращаем позицию опорного элемента
}

int RightLeft(int* mass, int low, int high) {
    int pivot = mass[high]; // Опорный элемент также последний элемент массива
    int i = low - 1;       // Начальное значение индекса

    for (int j = low; j < high; j++) { // Цикл по массиву
        if (mass[j] >= pivot) {     // Здесь условие противоположное: элементы больше или равные опорному
            i++;
            vremen(mass[i], mass[j]); // Обмен элементов
        }
    }
    vremen(mass[i + 1], mass[high]); // Перемещение опорного элемента
    return i + 1;                  // Возврат нового положения опорного элемента
}

void quickSortAscRecursive(int* mass, int low, int high) {
    if (low < high) {
        int pivotIndex = LeftRight(mass, low, high); 
        quickSortAscRecursive(mass, low, pivotIndex - 1);
        quickSortAscRecursive(mass, pivotIndex + 1, high);
    }
}

void quickSortDescRecursive(int* mass, int low, int high) {
    if (low < high) {
        int pivotIndex = RightLeft(mass, low, high);
        quickSortDescRecursive(mass, low, pivotIndex - 1);
        quickSortDescRecursive(mass, pivotIndex + 1, high);
    }
}

void quick_sort_asc(int* mass, int n) {
    if (n <= 1) return;
    quickSortAscRecursive(mass, 0, n - 1);
}

void quick_sort_desc(int* mass, int n) {
    if (n <= 1) return;
    quickSortDescRecursive(mass, 0, n - 1);
}
