#include <stdio.h>
#define EMPTY_ARRAY 1

int Bouble_Sort(int arr[], int n) {

	if (arr == NULL) {
		printf("Error");
		return EMPTY_ARRAY;
	}
	int i, j, temp;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void Arr_Printf(int arr[], int size) {
	int i;

	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
}

int main() {

	int arr[] = {1, 3, 5, 2, 4, 6, 9, 7, 8, 10};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Не отсортированный массив: ");
	Arr_Printf(arr, n);

	Bouble_Sort(arr, n);
	printf("\nОтсортированный массив: ");

	Arr_Printf(arr, n);

	return 0;
}
