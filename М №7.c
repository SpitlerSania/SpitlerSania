/*7)Поменять местами байты в заданном 32 - х разрядном целом числе.
Перестановка задаётся пользователем.*/
#include <stdio.h>
#pragma warning (disable: 4996) 

//Функция swap_bytes
int swap_bytes(int num, int order[4]) {
    unsigned char bytes[4];

    // Извлекаем байты числа
    for (int i = 0; i < 4; i++) {
        bytes[i] = (num >> (i * 8)) & 0xFF;
    }

    // Переставляем байты согласно заданному порядку
    int result = 0;
    for (int i = 0; i < 4; i++) {
        result |= (bytes[order[i]] << (i * 8));
    }

    return result;
}

int main() {
    int num;
    int order[4];

    printf("Введите 32-разрядное целое число: ");
    scanf("%d", &num);

    printf("Введите порядок перестановки байтов: ");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &order[i]);
    }

    int swap_num = swap_bytes(num, order);

    printf("Число после перестановки байтов: %d\n", swap_num);

    return 0;
}
