#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdint.h>
#include <locale.h>

#include <stdio.h>
#include <stdlib.h>

// Функция перевода числа из десятичной системы счисления в систему счисления с основанием r (r от 2 до 5)
void to_base_r(int n, int r) {
    // Проверка на допустимость основания системы счисления
    if (r < 2 || r > 5) {
        printf("Ошибка: основание должно быть от 2 до 5.\n");
        return;
    }

    // Если число равно 0, то сразу выводим 0
    if (n == 0) {
        printf("0\n");
        return;
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
            remainder = n & 3;
        }
        else if (r == 4) {
            remainder = n & 3;
        }
        else if (r == 5) {
            remainder = n & 4;
        }
        digits[i++] = remainder;

        // Делим на основание r с помощью сдвига
        if (r == 2) {
            n = n >> 1; // Целочисленное деление на 2 с помощью сдвига
        }
        else if (r == 3) {
            n = n >> 3;
        }
        else if (r == 4) {
            n = n >> 4;
        }
    }

    // Вывод цифр результата в обратном порядке
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", digits[j]);
    }
    printf("\n");
}

int main() {
    int n, r;
    printf("Введите число (n) и основание системы счисления (r): ");
    scanf("%d %d", &n, &r);

    to_base_r(n, r);

    return 0;
}
