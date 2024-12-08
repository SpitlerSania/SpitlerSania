#include <stdio.h>

#define N 3

void matrix_transposition(int matrix[N][N]) {
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
}

void printMatrix(int matrix[N][N]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int matrix[N][N] =
	{ {1, 2, 3},
	{4, 5, 6},
	{7, 8, 9} };

    printf("Original matrix:\n");
    printMatrix(matrix);

    matrix_transposition(matrix);

    printf("Transposed matrix:\n");
    printMatrix(matrix);

    return 0;
}