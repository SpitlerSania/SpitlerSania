#include <stdio.h>
#pragma warning(disable: 4996)

int main() {
    int a, k;

   
    printf("Enter a number a: ");
    scanf("%d", &a);

    printf("Enter the bit number k: ");
    scanf("%d", &k);

    if (k < 0 || k > sizeof(int) * 8) {
        printf("The bit number k must be between 0 and %d.\n", sizeof(int) * 8 - 1);
        return 1;
    }

    a = a | (1 << k);

    printf("The number after setting the k_th bit: %d\n", a);

    return 0;
}
