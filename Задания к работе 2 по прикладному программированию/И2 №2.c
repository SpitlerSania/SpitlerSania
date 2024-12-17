#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning(disable: 4996)

size_t my_strlen(const char* str) {
    size_t length = 0;
    while (*str++) {
        length++;
    }

    return length;
}

int my_strcmp(const char* s1, const char* s2) { //-l

    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }

    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

void my_strcat(char* first_word, char* second_word) {

    char* ptr = first_word;
    while (*ptr != '\0') {
        ptr++;
    }

    while ((*ptr++ = *second_word++) != '\0');
}

void reverse_string(char* str) { //-r

    size_t len = my_strlen(str);
    size_t i, j;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

char* my_strcpy(char* dest, const char* src) {
    char* ptr = dest;

    while (*src != '\0') {
        *dest++ = *src++;
    }

    *dest = '\0';

    return ptr;
}

void converting_element(char* str) { //-u
    if (str == NULL || my_strlen(str) == 0) {
        return;
    }

    for (size_t i = 1; str[i] != '\0'; i += 2) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

void rearrange(char* str) { //-n

    if (str == NULL) {
        fprintf(stderr, "Ошибка входной строки\n");
        return;
    }

    char digits[BUFSIZ] = { 0 };
    char letters[BUFSIZ] = { 0 };
    char others[BUFSIZ] = { 0 };
    char* digits_ptr = digits;
    char* letters_ptr = letters;
    char* others_ptr = others;
    char* str_ptr = str;

    while (*str_ptr++) {
        if (isdigit(*str_ptr)) {
            *digits_ptr++ = *str_ptr;
        }
        else if (isalpha(*str_ptr)) {
            *letters_ptr++ = *str_ptr;
        }
        else {
            *others_ptr++ = *str_ptr;
        }
    }

    while (*str_ptr) {
        if (isdigit(*str_ptr)) {
            if (digits_ptr - digits < BUFSIZ - 1) {
                *digits_ptr++ = *str_ptr;
            }
            else {
                fprintf(stderr, "Buffer overflow for digits\n");
                return;
            }
        }
        else if (isalpha(*str_ptr)) {
            if (letters_ptr - letters < BUFSIZ - 1) {
                *letters_ptr++ = *str_ptr;
            }
            else {
                fprintf(stderr, "Buffer overflow for letters\n");
                return;
            }
        }
        else {
            if (others_ptr - others < BUFSIZ - 1) {
                *others_ptr++ = *str_ptr;
            }
            else {
                fprintf(stderr, "Buffer overflow for other characters\n");
                return;
            }
        }
        str_ptr++;
    }

    *digits_ptr = '\0';
    *letters_ptr = '\0';
    *others_ptr = '\0';

    my_strcpy(str, digits);
    my_strcat(str, letters);
    my_strcat(str, others);

}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <flag> <string> [additional args]\n", argv[0]);
        return 1;
    }

    char* flag = argv[1];
    char* str = argv[2];

    if (my_strcmp(flag, "-l") == 0) {
        printf("Length of the string: %zu\n", my_strlen(str));
    }
    else if (my_strcmp(flag, "-r") == 0) {
        reverse_string(str);
        printf("Reversed string: %s\n", str);
    }
    else if (my_strcmp(flag, "-u") == 0) {
        converting_element(str);
        printf("String with alternating uppercase: %s\n", str);
    }
    else if (my_strcmp(flag, "-n") == 0) {
        rearrange(str);
        printf("Rearranged string: %s\n", str);

    }
    else if (my_strcmp(flag, "-c") == 0) {
        if (argc < 4) {
            printf("Usage: %s -c <seed> <strings...>\n", argv[0]);
            return 1;
        }
        for (int i = 3; i < argc; i++) {
            my_strcat(str, argv[i]);
        }
        printf("Concatenated string: %s\n", str);
    }
    else {
        printf("Unknown flag: %s\n", flag);
        return 1;
    }

    return 0;
}
