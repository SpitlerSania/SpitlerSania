#include <stdio.h>
#include <locale.h>

#pragma warning (disable: 4996)

#define LINE 3
#define COLN 3

// Печать матрицы
void printMatrix(int matrix[LINE][COLN]) {
    for (int i = 0; i < LINE; i++) {
        for (int j = 0; j < COLN; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Перемножения матриц
void multiplyMatrices(int matrix1[LINE][COLN], int matrix2[LINE][COLN], int result[LINE][COLN]) {

    for (int i = 0; i < LINE; i++) {
        for (int j = 0; j < COLN; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLN; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int matrix1[LINE][COLN];
    int matrix2[LINE][COLN];
    int result[LINE][COLN];

    // Данные для первой матрицы
    printf("Введите элементы для первой матрицы (%dx%d):\n", LINE, COLN);
    for (int i = 0; i < LINE; i++) {
        for (int j = 0; j < COLN; j++) {
            printf("Введите элемент [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Данные для второй матрицы
    printf("\nВведите элементы для второй матрицы (%dx%d):\n", LINE, COLN);
    for (int i = 0; i < LINE; i++) {
        for (int j = 0; j < COLN; j++) {
            printf("Введите элемент [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Умножение матриц
    multiplyMatrices(matrix1, matrix2, result);

    printf("\nМатрица 1:\n");
    printMatrix(matrix1);

    printf("\nМатрица 2:\n");
    printMatrix(matrix2);

    printf("\nРезультат перемножения матриц:\n");
    printMatrix(result);

    return 0;
}