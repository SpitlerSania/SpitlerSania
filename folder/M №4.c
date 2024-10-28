#include <stdio.h>
#pragma warning(disable: 4996)

int main() {
	int a, k;

	printf("Enter a number a: ");
	scanf("%d", &a);

	printf("Enter the bit number k (starting from 0): ");
	scanf("%d", &k);

	int kth_bit = (a >> k) & 1;

	printf("The kth bit of the number a is equal to: %d\n", kth_bit);

	return 0;
}
