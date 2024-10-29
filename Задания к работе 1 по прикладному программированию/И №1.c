#include<stdio.h>
// Главная функция
int main() {
	int array[5] = { 5,4,2,1,3 };
	int i, j, temp;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4 - i; j++) {
			if (array[j] > array[j + 1]) { //Сравневаем
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < 5; i++) {
		printf("%d ", array[i]);//Выводим
	}
	return 0;
}