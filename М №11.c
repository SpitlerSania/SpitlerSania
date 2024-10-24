#include <stdio.h>

#pragma warning(disable: 4996)

int main() {
    unsigned int n, i_1, i_2, result_beg_end, resmid;
    int len, i;
/*
n — это целое неотрицательное число, которое вводит пользователь.
i_1 — переменная для хранения первых i битов.
i_2 — переменная для хранения последних i битов.
result_beg_end — переменная для хранения результата склеивания первых и последних битов.
resmid — переменная для хранения битов между первыми и последними битами.
len — длина представления числа в битах.
i — количество битов, с которыми мы хотим работать.*/

    printf("Enter integer value: ");
    scanf("%u", &n);
    printf("\nEnter length: ");
    scanf("%d", &len);
    printf("\nEnter amount of bits: ");
    scanf("%d", &i);

    i_1 = (n >> (len - i)) & ((1 << i) - 1);
    i_2 = n & ((1 << i) - 1);

    result_beg_end = (i_1 << i) | i_2;

    resmid = (n >> i) & ((1 << (len - 2 * i)) - 1);

    printf("\nGlued bits result = %u", result_beg_end);
    printf("\nBits between glued bits result = %u\n", resmid);

    return 0;
}