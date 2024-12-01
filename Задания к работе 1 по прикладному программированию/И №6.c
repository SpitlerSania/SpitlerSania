#include <stdio.h>
#include <locale.h>


#pragma warning (disable: 4996)


int determinant(int matrix[3][3]) { // Функция для вычисления определителя матрицы 3x3
    int x;

    x = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) //формула для вычисления определителя 3 * 3
        - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
        + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

    return x;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int matrix[3][3];

    printf("Введите элементы матрицы 3х3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int det = determinant(matrix);

    printf("Определителем матрицы является: %d\n", det);

    return 0;
}
