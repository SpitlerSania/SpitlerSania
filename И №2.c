#include <stdio.h>
#include <string.h>

void reverse_string(char* str) { //Функция переворота строки
    int len = strlen(str);
    int i, j;

    for (i = 0, j = len - 1; i < j; i++, j--) { //Обмен значений между символами
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
//Главная функция
int main() {
    char str[] = "Ilya Sergeevich is a great teacher";

    printf("Original line: %s\n", str);
    reverse_string(str);
    printf("Inverted line: %s\n", str);

    return 0;
}
