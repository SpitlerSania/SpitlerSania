//Поменять местами 𝑖−ый и 𝑗−ый биты в числе 𝑎. Числа 𝑖 и 𝑗 предварительно считать с клавиатуры.
#include <stdio.h>
#pragma warning (disable: 4996)

int main() {
    int a, i, j, c = sizeof(int) * 8 - 1;

    printf("Enter a number a: ");
    scanf("%d", &a);

    printf("Enter the number of the first bit i: ");
    scanf("%d", &i);

    printf("Enter the number of the second bit j: ");
    scanf("%d", &j);

    if (i < 0 || i >= sizeof(int) * 8 || j < 0 || j >= sizeof(int) * 8) {
        printf("The bit numbers i and j must be in the range from 0 to %d.\n", c);
        return 1;

        int ith_bit = (a >> i) & 1;
        int jth_bit = (a >> j) & 1;

        if (ith_bit != jth_bit) {
            a ^= (1 << i);
            a ^= (1 << j);
        }

        printf("The number a after exchanging %d and %d bits: %d\n", i, j, a);
        return 0;
    }
}

