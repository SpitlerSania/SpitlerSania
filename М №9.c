#include <stdio.h>
#pragma warning (disable: 4996)

int xorAllBits(int n) {
    int result = 0; // Инициализируем результат
    while (n) {
        result ^= (n & 1); // XOR с последним битом числа
        n >>= 1; // Сдвигаем число вправо на 1 бит
    }
    return result;
}

int main() {
    int n;
    printf("Введите целое число: ");
    scanf("%d", &n);

    int result = xorAllBits(n);
    printf("Результат поксоривания всех битов числа %d: %d\n", n, result);

    return 0;
}
