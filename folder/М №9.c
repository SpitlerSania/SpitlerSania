#include <stdio.h>
#pragma warning (disable: 4996)

int xor_bits(int num) {
    int result = 0;
    while (num > 0) {
        result ^= num & 1; // XOR последнего бита
        num >>= 1;// Сдвиг в право
    }
    return result;
}

int main() {
    int num;

    printf("Введите целое число: ");
    scanf("%d", &num);

    int result = xor_bits(num);

    printf("Результат поксора всех битов: %d\n", result);

    return 0;
}