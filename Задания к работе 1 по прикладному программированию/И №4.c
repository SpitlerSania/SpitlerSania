#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define ARR_SIZE 52

int main() {

    setlocale(LC_ALL, "Russian");

    srand(time(NULL)); // иницилизирует рандомные числа

    int array[ARR_SIZE];
    int min_value = 10001;  // Max знач. для Min
    int max_value = -10001; // Min знач. для Max
    int max_index = -1;
    int min_index = -1;

    // Заполнение массива случайными числами от -10000 до 10000
    for (int i = 0; i < ARR_SIZE; ++i) {
        array[i] = rand() % 20001 - 10000;

        if (array[i] > max_value) {
            max_value = array[i];
            max_index = i;
        }

        if (array[i] < min_value) {
            min_value = array[i];
            min_index = i;
        }
    }

    printf("Макс элемент: %d, индекс: %d\n", max_value, max_index);
    printf("Мин элемент: %d, индекс: %d\n", min_value, min_index);

    return 0;
}