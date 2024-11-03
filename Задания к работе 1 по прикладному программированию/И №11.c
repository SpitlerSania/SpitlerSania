#include <stdio.h>

size_t my_strlen(const char* str) {
    const char* s = str;

    while (*s) {
        s++;
    }

    return s - str;
}

int main() {
    const char* line = "Skibidi dop dop dop es es es"; //28
    size_t length = my_strlen(line);

    printf("Line str: %zu\n", length);
    return 0;
}
