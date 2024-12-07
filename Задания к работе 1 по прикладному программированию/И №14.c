#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>
#pragma warning (disable: 4996)

#define SIZE_LINE 100



int main() {
    setlocale(LC_ALL, "Russian");

    FILE* fPoint = fopen("taskse.txt", "r"); // 1 2 3 4 434 5 6 52 7  9 1243
    if (fPoint == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    char line[SIZE_LINE];
    int num, count = 0;
    int max_value = INT_MIN, min_value = INT_MAX;

    while (fscanf(fPoint, "%d", &num) == 1) {
        if (count < SIZE_LINE) {

            if (num > max_value) {
                max_value = num;
            }

            if (num < min_value) {
                min_value = num;
            }
            count++;
        }
    }

    fseek(fPoint, 0, SEEK_SET);

    printf("Содержимое файла:\n");

    while (fgets(line, SIZE_LINE, fPoint)) {
        printf("%s\n", line);
    }
    printf("Мaксимальное значение файла = %d\n", max_value);
    printf("Минимальное значение файла = %d", min_value);
    
    fclose(fPoint);
    
    return 0;
    }
