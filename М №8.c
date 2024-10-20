#include <stdio.h>
#pragma warning (disable: 4996)

int TheMaximumDegreeOfTwo(int n) {
    if (n % 2 != 0) // Если n НЕчётное, возвращается 0
        return 0;
    return 1 + TheMaximumDegreeOfTwo(n / 2); // Рекурсивный вызов
}

int main() {
    int n;
    printf("Введите целое число: ");
    scanf("%d", &n);

    int result = TheMaximumDegreeOfTwo(n);
    printf("Максимальная степень 2, на которую делится %d: %d\n", n, result);

    return 0;
}