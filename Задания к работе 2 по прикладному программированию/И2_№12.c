#include <stdio.h>
#include <stdlib.h>

// Коды возврата
#define SUCCESS             0
#define RESULT_DECOMP_NULL  1
#define COUNT_DECOMP_NULL   2
#define VALUE_NOT_NATURAL   3
#define MEMORY_ERROR        4

// Функция для выделения памяти под РЕЗУЛЬТАТ
void allocate_result(int*** result_decompositions, size_t* result_decompositions_count, size_t new_size) {
    if (*result_decompositions == NULL || *result_decompositions_count != new_size) {
        free(*result_decompositions); // Освобождаем СТАРУЮ память
        *result_decompositions = (int**)malloc(new_size * sizeof(int*));
        if (*result_decompositions == NULL) {
            printf("Ошибка выделения памяти\n");
            exit(MEMORY_ERROR);
        }
        *result_decompositions_count = new_size;
    }
}

void find_decompositions(int value, int current_sum, int current_component, int** current_decomp, int index, int allowed_equal_sum_components, int*** result_decompositions, size_t* result_decompositions_count, size_t* result_index) {
    if (value == current_sum) { // Если сумма текущих компонент равна исходному числу
        // Выделяем память под новое разложение
        allocate_result(result_decompositions, result_decompositions_count, *result_index + 1);

        // Копируем текущее разложение в результирующий массив
        (*result_decompositions)[*result_index] = (int*)malloc((index + 1) * sizeof(int));
        if ((*result_decompositions)[*result_index] == NULL) {
            printf("Ошибка выделения памяти\n");
            exit(MEMORY_ERROR);
        }
        (*result_decompositions)[*result_index][0] = index;
        for (size_t i = 0; i < index; ++i) {
            (*result_decompositions)[*result_index][i + 1] = current_decomp[i];
        }
        (*result_index)++;
    }
    else if (value > current_sum && current_component <= value - current_sum) {

        current_decomp[index++] = current_component;

        // Продолжаем рекурсию с тем же компонентом, если разрешено
        if (allowed_equal_sum_components) {
            find_decompositions(value, current_sum + current_component, current_component, current_decomp, index, allowed_equal_sum_components, result_decompositions, result_decompositions_count, result_index);
        }

        // Продолжаем рекурсию со следующим компонентом
        find_decompositions(value, current_sum + current_component, current_component + 1, current_decomp, index, allowed_equal_sum_components, result_decompositions, result_decompositions_count, result_index);

        // Убираем последний добавленный компонент
        index--;
    }
}

// Основная функция для нахождения разложений
int sums_decomposition(int value, int*** result_decompositions, size_t* result_decompositions_count, int allowed_equal_sum_components) {
    if (result_decompositions == NULL) return RESULT_DECOMP_NULL;
    if (result_decompositions_count == NULL) return COUNT_DECOMP_NULL;
    if (value <= 0) return VALUE_NOT_NATURAL;

    // Инициализация переменных
    *result_decompositions = NULL;
    *result_decompositions_count = 0;
    size_t result_index = 0;

    // Массив для хранения текущего разложения
    int* current_decomp = (int*)malloc(value * sizeof(int));
    if (current_decomp == NULL) {
        printf("Ошибка выделения памяти\n");
        return MEMORY_ERROR;
    }

    // Запускаем поиск разложений
    find_decompositions(value, 0, 1, current_decomp, 0, allowed_equal_sum_components, result_decompositions, result_decompositions_count, &result_index);

    // Освобождаем временный массив
    free(current_decomp);

    return SUCCESS;
}

int main() {
    int value = 6;
    int*** result_decompositions = NULL;
    size_t result_decompositions_count = 0;
    int allowed_equal_sum_components = 1;

    int status_code = sums_decomposition(value, result_decompositions, &result_decompositions_count, allowed_equal_sum_components);

    switch (status_code) {
    case SUCCESS:
        printf("Разложений найдено: %zu\n", result_decompositions_count);
        for (size_t i = 0; i < result_decompositions_count; ++i) {
            printf("%d: ", i + 1);
            for (size_t j = 0; j < (*result_decompositions)[i][0]; ++j) {
                printf("%d ", (*result_decompositions)[i][j + 1]);
            }
            printf("\n");
        }
        break;
    case RESULT_DECOMP_NULL:
        printf("result_decompositions is NULL\n");
        break;
    case COUNT_DECOMP_NULL:
        printf("result_decompositions_count is NULL\n");
        break;
    case VALUE_NOT_NATURAL:
        printf("Значение value должно быть положительным\n");
        break;
    case MEMORY_ERROR:
        printf("Ошибка выделения памяти\n");
        break;
    default:
        printf("Неизвестная ошибка\n");
        break;
    }

    // Освобождение ПАМЯТИ
    for (size_t i = 0; i < result_decompositions_count; ++i) {
        free((*result_decompositions)[i]);
    }
    free(*result_decompositions);

    return 0;
}