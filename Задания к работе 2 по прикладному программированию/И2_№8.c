#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void reverse_string(char* str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char* column_addition(char* first, char* second, int base) {

    size_t max_len = strlen(first) > strlen(second) ? strlen(first) + 1 : strlen(second) + 1;

    char* result = malloc(max_len + 2);
    if (result == NULL) {
        fprintf(stderr, "Ошибка выделения памяти");
        return NULL;
    }

    reverse_string(first);
    reverse_string(second);

    int temp = 0;
    for (size_t i = 0; i < max_len; ++i) {

        int digit_first;
        if (i < strlen(first)) {
            digit_first = first[i] - '0';
        }
        else {
            digit_first = 0;
        }

        int digit_second;
        if (i < strlen(second)) {
            digit_second = second[i] - '0';
        }
        else {
            digit_second = 0;
        }

        int sum = digit_first + digit_second + temp;
        temp = sum / base;
        result[i] = (sum % base) + '0';
    }

    if (temp != 0) {
        result[max_len] = temp + '0';
    }

    result[max_len + 1] = '\0';

    // Переворачиваем строку обратно
    reverse_string(result);

    return result;
}

char* sum_numbers(int count, char** numbers, int base) {
    if (count == 0) {
        return NULL;
    }

    char* result = numbers[0];

    for (int i = 1; i < count; ++i) {
        char* temp = column_addition(result, numbers[i], base);
        free(result);
        result = temp;
    }

    while (*result == '0' && *result != '\0') {
        memmove(result, result + 1, strlen(result));
    }

    return result;
}

int main() {

    int base = 16;  // Основание системы счисления
    int n = 4;      // Количество чисел
    char* numbers[] = { "C", "15", "35", "ME" };  // Шестнадцатиричная система

    char* result = sum_numbers(n, numbers, base);

    if (result) {
        printf("Сумма чисел в системе счисления с основанием %d равна %s.\n", base, result);
        free(result);
    }
    else {
        printf("Error.\n");
    }

    return 0;
}