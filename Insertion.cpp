#include <iostream>
using namespace std;
//Сортировка вставками
void insertion_sort_asc(int* mass, int n) {
    for (int i = 1; i < n; i++) {
        int key = mass[i]; 
        int j = i - 1;

        while (j >= 0 && mass[j] > key) {
            mass[j + 1] = mass[j];
            j--;
        }
        mass[j + 1] = key;
    }
}


void insertion_sort_desc(int* mass, int n) {
    for (int i = 1; i < n; i++) {
        int key = mass[i];  
        int j = i - 1;

        while (j >= 0 && mass[j] < key) {
            mass[j + 1] = mass[j];
            j--;
        }
        mass[j + 1] = key;
    }
}
