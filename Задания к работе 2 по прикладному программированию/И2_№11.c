#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STATUS_SUCCESS 0
#define STATUS_NULL_INITIAL 1
#define STATUS_NULL_DETECTOR 2
#define STATUS_NULL_LEXEMS 3
#define STATUS_NULL_LEXEM_COUNT 4
#define STATUS_MEMORY_ERROR 5


// Функция для разделения символов на (хорошие) и (плохие).
int is_space(int c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int tokenize(
    char* initial,// Указатель на строку, из которой необходимо выделить лексемы.
    int (*detector)(int),// Функция для определения (хороших) и (плохих) символов.
    int accept_empty_lexems,// Допускать ли пустые лексемы.
    char*** lexems,// Указатель на массив лексем.
    size_t* lexems_count//Указатель на количество лексем.
) {
    if (!initial) {
        return STATUS_NULL_INITIAL;
    }
    if (!detector) {
        return STATUS_NULL_DETECTOR;
    }
    if (!lexems) {
        return STATUS_NULL_LEXEMS;
    }
    if (!lexems_count) {
        return STATUS_NULL_LEXEM_COUNT;
    }

    size_t current_lexem_size = 0;
    size_t total_lexems = 0;
    size_t capacity = 8;  // Начальная емкость для массива лексем
    *lexems = (char**)malloc(capacity * sizeof(char*));
    if (!(*lexems)) {
        return STATUS_MEMORY_ERROR;
    }

    for (size_t i = 0; initial[i]; ++i) {
        if (detector(initial[i])) {
            if (current_lexem_size > 0 || accept_empty_lexems) {
                (*lexems)[total_lexems] = (char*)malloc((current_lexem_size + 1) * sizeof(char));
                if (!((*lexems)[total_lexems])) {
                    // Освобождаем всю выделенную память и возвращаем ошибку
                    for (size_t j = 0; j < total_lexems; ++j) {
                        free((*lexems)[j]);
                    }
                    free(*lexems);
                    return STATUS_MEMORY_ERROR;
                }
                memcpy((*lexems)[total_lexems], &initial[i - current_lexem_size], current_lexem_size);
                (*lexems)[total_lexems][current_lexem_size] = '\0';
                ++total_lexems;

                // Проверяем, нужна ли дополнительная память для новых лексем
                if (total_lexems >= capacity) {
                    capacity *= 2;
                    void* tmp = realloc(*lexems, capacity * sizeof(char*));
                    if (!tmp) {
                        // Освобождаем всю выделенную память и возвращаемся с ошибкой
                        for (size_t j = 0; j < total_lexems; ++j) {
                            free((*lexems)[j]);
                        }
                        free(*lexems);
                        return STATUS_MEMORY_ERROR;
                    }
                    *lexems = (char**)tmp;
                }

                current_lexem_size = 0;
            }
        }
        else {
            ++current_lexem_size;
        }
    }

    // Обрабатываем последнюю лексему, если она существует
    if (current_lexem_size > 0 || (accept_empty_lexems && current_lexem_size == 0)) {
        (*lexems)[total_lexems] = (char*)malloc((current_lexem_size + 1) * sizeof(char));
        if (!((*lexems)[total_lexems])) {
            // Освобождаем всю выделенную память и возвращаемся с ошибкой
            for (size_t j = 0; j < total_lexems; ++j) {
                free((*lexems)[j]);
            }
            free(*lexems);
            return STATUS_MEMORY_ERROR;
        }
        memcpy((*lexems)[total_lexems], &initial[strlen(initial) - current_lexem_size], current_lexem_size);
        (*lexems)[total_lexems][current_lexem_size] = '\0';
        ++total_lexems;
    }

    *lexems_count = total_lexems;
    return STATUS_SUCCESS;
}

void test_tokenize() {
    char* input = "I\t have no idea\n what to write\r here q w e r t y u i o p";
    char** lexems;
    size_t lexems_count;

    int status = tokenize(input, is_space, 0, &lexems, &lexems_count);
    if (status == STATUS_SUCCESS) {
        printf("Lexemes:\n");
        for (size_t i = 0; i < lexems_count; ++i) {
            printf("%zu: %s\n", i, lexems[i]);
            free(lexems[i]);  // Освобождение памяти для каждой лексемы
        }
        free(lexems);  // Освобождение памяти для массива лексем
    }
    else {
        switch (status) {
        case STATUS_NULL_INITIAL:
            printf("Input string is NULL.\n");
            break;

        case STATUS_NULL_DETECTOR:
            printf("Detector function is NULL.\n");
            break;

        case STATUS_NULL_LEXEMS:
            printf("Lexems pointer is NULL.\n");
            break;

        case STATUS_NULL_LEXEM_COUNT:
            printf("Lexems count pointer is NULL.\n");
            break;

        case STATUS_MEMORY_ERROR:
            printf("Memory allocation error occurred.\n");
            break;

        default:
            printf("Unknown error occurred.\n");
            break;
        }
    }
}

int main() {
    test_tokenize();
    return 0;
}
