#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


void return_of_resources(int flag, ...) {
    va_list args;
    va_start(args, flag);

    while (1) {
        void* resource = va_arg(args, void*);
        if (resource == NULL) {
            break;
        }

        int action_flag = va_arg(args, int);

        if (action_flag == 1) { // Возврат в кучу
            free(resource);
            printf("Resource at %p freed\n", resource);
        }

        else if (action_flag == 2) { // Закрытие файла
            fclose((FILE*)resource);
            printf("File at %p closed\n", resource);
        }

        else {
            printf("Unknown flag: %d\n", action_flag);
        }
    }
    va_end(args);
}


int main() {
    char* memory = (char*)malloc(100 * sizeof(char));
    if (memory == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    FILE* file = fopen("File_bag.txt", "w"); // чтение файла
    if (file == NULL) {
        printf("File opening error\n");
        return_of_resources(memory, 1, NULL);
        return 1;
    }
    return_of_resources(memory, 1, file, 2, NULL);

    return 0;
}