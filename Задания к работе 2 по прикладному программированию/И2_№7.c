#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#pragma warning (disable: 4996)


int search_for_positive_integers(const char* str, int base) {
    size_t i = 0;
    int result = 0;
    for (size_t i; str[i]; ++i) {
        if ('0' <= str[i] && str[i] <= '9') {
            result = result * base + (str[i] - '0');
            //123
            //На первом шаге : result = 0 * 10 + ('1' - '0') = 1
            //На втором шаге : result = 1 * 10 + ('2' - '0') = 12
            //На третьем шаге : result = 12 * 10 + ('3' - '0') = 123
        }
        else if ('a' <= str[i] && str[i] <= 'z') {
            result = result * base + (str[i] - 'a' + 10);
            //1ab
            //На первом шаге: result = 0 * 16 + ('1' - '0') = 1
            //На втором шаге : result = 1 * 16 + ('a' - 'a' + 10) = 16 + 10 = 26
            //На третьем шаге : result = 26 * 16 + ('b' - 'a' + 10) = 416 + 11 = 427
        }


        else if ('A' <= str[i] && str[i] <= 'Z') {
            result = result * base + (str[i] - 'A' + 10);
        }
    }
    return 0;
}


int checking_number_kaprekar(int num, int base) {
    long square_num = (long)num * num; //квадрат числа

    char buffer[252];
    sprintf(buffer, "%ld", square_num);

    size_t len = strlen(buffer);
    size_t split_index = len / 2;

    char left_part[50], right_part[50];

    memset(left_part, 0, sizeof(left_part)); //memset обнуляет буферы
    memset(right_part, 0, sizeof(right_part));
    strncpy(left_part, buffer, split_index);// Прототипchar: *strncpy (char *dst, const char *src, size_t len);
    strcpy(right_part, &buffer[split_index]);

    int left_num = search_for_positive_integers(left_part, base); // Преобразование левой части
    int right_num = search_for_positive_integers(right_part, base); // Преобразование правой части

    if (left_num == 0 || right_num == 0) {
        return 0;
    }
    else {
        return (left_num + right_num == num);
    }
}

void clear_memory() {
    char* ptr = NULL;
    size_t size = 0;
    while (ptr != NULL && size < sizeof(ptr)) {
        *(ptr + size) = 0;
        ptr++;
        size += sizeof(*ptr);
    }
    free(ptr);
}

void search_kaprekars(int base, const char** strings, size_t count) { //count количество сто=рок в массиве
    printf("Основание системы исчисления: %d \n", base);
    printf("Числа Капрекера: \n");

    for (size_t i = 0; i < count; ++i) {
        int num = search_for_positive_integers(strings[i], base);

        if (checking_number_kaprekar(num, base)) {
            printf("%s ", strings[i]);
        }
    }

    printf("\n");

    void clear_memory();
}

int main() {
    setlocale(LC_ALL, "Rus");
    const char* strings[] = { "2234", "5869", "5542", "5525", "9", "45", "297", "100", "147", "10110", "121" };
    size_t count = sizeof(strings) / sizeof(strings[0]);

    search_kaprekars(10, strings, count);

    return 0;
}