#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdint.h>
#include <locale.h>

#include <stdio.h>
#include <stdlib.h>

#define ErRoR 2
#define ErRoR MeMoRy 3

char *to_base_r(int n, int r) {
    // Проверка на допустимость основания системы счисления
    if (r < 2 || r > 5) {
        fprintf(stderr, "Ошибка: основание должно быть от 2 до 5.\n");
        return ErRoR;
    }

    // Если число равно 0, возвращаем строку "0"
    if (n == 0) {
        char *result = malloc(2); // Один символ + '\0'
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    // Массив для хранения цифр результата
    int digits[32];
    int i = 0;

    // Перевод числа в систему счисления с основанием r
    while (n > 0) {
        // Для вычисления остатка от деления на r
        int remainder;
        if (r == 2) {
            remainder = n & 1;
        }
        else if (r == 3) {
            remainder = n % 3;
        }
        else if (r == 4) {
            remainder = n % 4;
        }
        else if (r == 5) {
            remainder = n % 5;
        }
        digits[i++] = remainder;

        // Делим на основание r с помощью целочисленного деления
        n /= r;
    }

    // Выделение памяти под результат
    char *result = malloc(i + 1); // i символов + '\0'
    if (!result) {
        perror("Не удалось выделить память");
        return ErRoR;
    }

    // Заполнение строки цифрами в обратном порядке
    int j = 0;
    for (int k = i - 1; k >= 0; k--) {
        result[j++] = '0' + digits[k]; // Преобразуем целое число в ASCII-символ
    }
    result[j] = '\0'; // Завершаем строку нулевым символом

    return result;
}

int main() {
    int n, r;
    printf("Введите число (n) и основание системы счисления (r): ");
    scanf("%d %d", &n, &r);

    to_base_r(n, r);

    return 0;
}
