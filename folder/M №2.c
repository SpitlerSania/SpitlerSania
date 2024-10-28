#include <stdio.h>
#pragma warning (disable: 4996)

int main() {
    int a, k;

    printf("Enter the number a: ");
    scanf("%d", &a);

    printf("Enter the bit number k: ");
    scanf("%d", &k);

    int k_bit = (a >> k) & 1;

    printf("%d-th bit number %d: %d\n", k, a, k_bit);

    return 0;
}
