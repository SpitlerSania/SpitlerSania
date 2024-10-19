#include <stdio.h>
#pragma warning (disable: 4996)

#define SIZE 10 // Размер исходного массива

int main() {
    int array[SIZE], even_index_array[SIZE / 1 + 2]; // Новый массив
    int new_size = 0; // Размер нового массива

    printf("Введите %d чисел:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < SIZE; i += 2) {
        even_index_array[new_size++] = array[i]; // Записываем в новый массив
    }

    // Вывод нового массива
    printf("Числа на нечётных позициях:\n");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", even_index_array[i]);
    }

    printf("\n");

    return 0;
}
