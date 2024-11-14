#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>  // Научился пользоваться  malloc =)

int binarySearch(int arr[], int size, int target) { //Реализации поиска
    int left = 0, right = size - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (arr[middle] == target) {
            return middle;
        }

        if (arr[middle] > target) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }

    return -1; // вернет если не найдет элемента
}



int main() {
    int n, target;

    // Запрос РАЗМЕРА массива!!!
    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Размер массива должен быть положительным.\n");
        return 1;  // или выдаст ошибку
    }

    int* arr = (int*)malloc(n * sizeof(int));  // Выделяем память для массива

    printf("Введите элементы массива (в отсортированном порядке):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Введите значение для поиска: "); // Что нужно найти?
    scanf("%d", &target);

    int result = binarySearch(arr, n, target); // Вызвал функцию поиска


    if (result != -1) { //РЕЗУЛЬТАТ
        printf("Элемент найден на индексе: %d\n", result);
    }
    else {
        printf("Элемент не найден.\n");
    }

    return 0;
}