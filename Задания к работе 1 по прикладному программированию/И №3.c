/*Реализовать функцию, меняющую местами значения двух чисел типа int.Входными
параметрами функции являются указатели типа int* .на с и*/
#include <stdio.h>
#pragma warning (disable: 4996)

void swap(int* a, int* b) {
    int temp = *a; // Сохраняем значение a во временной переменной temp
    *a = *b;       // Меняем значение a на значение b
    *b = temp;     // Присваиваем temp значение a
}

int main() {
    int num1, num2;

    printf("Введите первое число: "); //a
    scanf("%d", &num1);

    printf("Введите второе число: "); //b
    scanf("%d", &num2);

    printf("До обмена числами: num1 = %d, num2 = %d\n", num1, num2);

    swap(&num1, &num2);
    printf("После обмена числами: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
