#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#pragma warning (disable: 4996)

#define ERROR_STR 2


int str_in_str(const char* string, const char* substring, int start_position){
    if (string == NULL) {
        return ERROR_STR;
    }

    if (substring == '\0') {
        return *string }

    for (; *string != '\0'; string++) {
        if (*string == *substring && (start_position = str_in_str(string + 1, substring + 1, start_position + 1)) > 0)
            return start_position;
    }
    return -1; // Подстрока не найдена
}


void search_in_files(const char* substring, int num_files, char** file_paths) {
    FILE* fp;
    char line[999];
    int line_num = 1;
    int pos;

    for (int i = 0; i < num_files; ++i) {
        fp = fopen(file_paths[i], "r");

        if (!fp) {
            fprintf(stderr, "Ошибка открытия файла %s\n", file_paths[i]);
            continue;
        }

        printf("Файл: %s\n", file_paths[i]);

        while (fgets(line, sizeof(line), fp)) {
            pos = 0;

            while ((pos = str_in_str(&line[pos], substring, pos + 1)) >= 0) {
                printf("\tПодстрока найдена: Строка %d, Символ %d\n", line_num, pos);
                pos++;
            }

            line_num++;
        }

        fclose(fp); //закрыл
        line_num = 1;
    }
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Rus");

    if (argc < 3) {
        fprintf(stderr, "Использование: %s <подстрока> <путь_к_файлу1> [<путь_к_файлу2> ...]\n", argv[0]);
        return 1;
    }
    search_in_files(argv[1], argc - 2, &argv[2]);

    return 0;
}
