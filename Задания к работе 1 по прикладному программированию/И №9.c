#include<stdio.h>
#include <locale.h>

#define N 14 // Размер исходного массива
#define Z 12 // Размер нового массива для уникальных чисел


int is_duplicate(double arr[], int n, double value) {
	for (int i = 0; i < N; i++) {
		if (arr[i] == value) {
			return 1; // Если есть дубликат вернем 1
		}
	}
	return 0; // Если нет дубликата вернем 0
}

int main() {
	double array[N] = { 1.2, 2.3, 3.4, 4.5, 5.6, 6.5, 2.3, 4.5, 6.5};
	double uniqueArr[Z]; //Массив для уникальных значений
	int uniqueCount = 0;

	for (int i = 0; i < N; i++) {
		if (!is_duplicate(uniqueArr, uniqueCount, array[i])) {
			// Если элемента нет в новом массиве, добавляем его
			uniqueArr[uniqueCount++] = array[i];
		}
	}

	setlocale(LC_ALL, "Russian");
	printf("Массив без дубликатов:\n");
	for (int i = 0; i < uniqueCount - 1; i++) {
		printf("%.2f ", uniqueArr[i]);
	}

	return 0;
}