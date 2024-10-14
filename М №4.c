#include <stdio.h>
#pragma warning(disable: 4996)

int main() {
	int a, k;

	printf("Введите число a: ");
	scanf("%d", &a);

	printf("Введите номер бита k (начиная с 0): ");
	scanf("%d", &k);

	int kth_bit = (a >> k) & 1;

	printf("k-ый бит числа a равен: %d\n", kth_bit);

	return 0;
}