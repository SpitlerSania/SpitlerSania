#include <stdio.h>
#pragma warning (disable: 4996)

int main() {
    int a, k;
    int  b = (sizeof(int) * 8 - 1);

    printf("Введите число a: ");
    scanf("%d", &a);

    printf("Введите количество младших битов k для обнуления: ");
    scanf("%d", &k);

    if (k < 0 || k > b){
        printf("Количество младших битов k должно быть в диапазоне от 0 до %d.\n", b);
        return 1; // если ошибка, то код вернется
    }

    // Создание маски для обнуления младших k битов
    int mask = ~((1 << k) - 1); // или  mask = (-1 << k)
    a &= mask;

    printf("Число a после обнуления младших %d битов: %d\n", k, a);

    return 0;
}

