#include <stdio.h>

#pragma warning (disable: 4996)

#define SIZE 10 // Размер массива

int main() {
    int array[SIZE], evenArray[SIZE];

    int newSize = 0;

    // Ввод элементов в массив
    printf("Введите %d чисел:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &array[i]);
    }

    // Переписываем четные числа в НОВЫЙ массив
    for (int i = 0; i < SIZE; i++) {
        if (array[i] % 2 == 0) { // Проверка на четность
            evenArray[newSize++] = array[i]; // Записываем четное число в НОВЫЙ массив
        }
    }

    // Вывод НОВОГО массива
    printf("Четные числа:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", evenArray[i]);
    }
    printf("\n");

    return 0;
}
