#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#pragma warning (disable: 4996)

#define DIGIT(q) ((q) >= '0' && (q) <= '9')
#define UPP(q) (((q) >= 'a' && (q) <= 'z') ? ((q) - ('a' - 'A')) : (q))
#define LOW(q) (((q) >= 'A' && (q) <= 'Z') ? ((q) + ('a' - 'A')) : (q))

void int_to_roman(int num, char* str) {
    const char* symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            num -= values[i];
            strcat(str, symbols[i]);
        }
    }
}

void сekendorf(char* buffer, size_t buffer_size, unsigned int num) {
    if (num == 0 || buffer_size == 0) return;

    unsigned int fibonachi[32];
    fibonachi[0] = 1;
    fibonachi[1] = 1;
    int index = 2;
    while (fibonachi[index - 1] <= num) {
        fibonachi[index] = fibonachi[index - 1] + fibonachi[index - 2];
        index++;
    }

    // Цекендорфово представление
    for (int i = index - 1; i > 0; i--) {
        if (num >= fibonachi[i]) {
            num -= fibonachi[i];
            strncat(buffer, "1", buffer_size - strlen(buffer) - 1);
        }
        else {
            strncat(buffer, "0", buffer_size - strlen(buffer) - 1);
        }
    }
    strncat(buffer, "1", buffer_size - strlen(buffer) - 1);
}

void to_base(char* buffer, size_t buffer_size, int num, int base) {
    if (base < 2 || base > 36 || buffer_size == 0) return;

    char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    int is_negative = 0;

    if (num < 0) {
        is_negative = 1;
        num = -num;
    }

    do {
        int digit = num % base;
        *(buffer++) = digits[digit];
        num /= base;
    } while (num != 0);

    if (is_negative) {
        *(buffer++) = '-';
    }

    *buffer = '\0'; // Завершение строки

    size_t len = strlen(buffer);
    for (size_t i = 0; i < len / 2; ++i) {
        char temp = buffer[i];
        buffer[i] = buffer[len - i - 1];
        buffer[len - i - 1] = temp;
    }
}

unsigned long from_base(const char* str, int base) {
    if (base < 2 || base > 36) return 0;

    unsigned long result = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        ++str;
    }

    while (*str) {
        int digit = DIGIT(*str) ? *str - '0' : LOW(*str) - 'a' + 10;

        if (digit >= base) break;

        result = result * base + digit;
        ++str;
    }

    return sign * result;
}

void dump_memory(char* buffer, size_t buffer_size, void* ptr, size_t size) { //size_t size: Количество байт
    if (buffer_size == 0) {
        return;
    }

    unsigned char* z = (unsigned char*)ptr;
    for (size_t i = 0; i < size; ++i) {
        snprintf(buffer, buffer_size, "%02X ", z[i]); //%02X вывод целых чисел в шестнадцатеричном формате c особенностями
        buffer += 3;
        buffer_size -= 3;
    }
    buffer[-1] = '\0'; // Удаление последнего пробела!!!
}

void voverprintf(FILE* stream, const char* format, va_list args) {
    const char* ptr = format;
    while (*ptr) {
        if (*ptr == '%') {
            ++ptr;

            switch (*ptr) {
            case 'R': // Римское число
            {
                int num = va_arg(args, int);
                char roman_buffer[64];
                int_to_roman(roman_buffer, sizeof(roman_buffer), num);
                fputs(roman_buffer, stream);
            }
            break;

            case 'Z':
            {
                unsigned int num = va_arg(args, unsigned int);
                char сekendorf_buffer[33];
                сekendorf(сekendorf_buffer, sizeof(сekendorf_buffer), num);
                fputs(сekendorf_buffer, stream);
            }
            break;

            case 'C':
            {
                int num = va_arg(args, int);
                int base = va_arg(args, int);

                if (*(ptr + 1) == 'v') {
                    char cv_buffer[65];
                    to_base(cv_buffer, sizeof(cv_buffer), num, base);
                    fputs(cv_buffer, stream);
                }
                else if (*(ptr + 1) == 'V') {
                    char CV_buffer[65];
                    to_base(CV_buffer, sizeof(CV_buffer), num, base);
                    for (char* p = CV_buffer; *p; ++p) {
                        *p = UPP(*p);
                    }
                    fputs(CV_buffer, stream);
                }
            }
            break;

            case 't':
            {
                const char* str = va_arg(args, const char*);
                int base = va_arg(args, int);

                if (*(ptr + 1) == 'o') {
                    unsigned long num = from_base(str, base);
                    fprintf(stream, "%lu", num);
                }
                else if (*(ptr + 1) == 'O') {
                    unsigned long num = from_base(str, base);
                    fprintf(stream, "%lX", num);
                }
            }
            break;

            case 'm':
            {
                void* ptr = va_arg(args, void*);
                size_t size = 0;

                if (*(ptr + 1) == 'i') {
                    size = sizeof(int);
                }
                else if (*(ptr + 1) == 'u') {
                    size = sizeof(unsigned int);
                }
                else if (*(ptr + 1) == 'd') {
                    size = sizeof(double);
                }
                else if (*(ptr + 1) == 'f') {
                    size = sizeof(float);
                }

                char memory_dump[1024];
                dump_memory(memory_dump, sizeof(memory_dump), ptr, size);
                fputs(memory_dump, stream);
            }
            break;

            default:
                putc('%', stream);
                putc(*ptr, stream);
                break;
            }

            ++ptr;
        }
        else {
            putc(*ptr++, stream);
        }
    }
}

void overprintf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    voverprintf(stdout, format, args);
    va_end(args);
}

void overfprintf(FILE* stream, const char* format, ...) {
    va_list args;
    va_start(args, format);
    voverprintf(stream, format, args);
    va_end(args);
}

char* oversprintf(char* str, size_t size, const char* format, ...) {
    FILE* file = fmemopen(str, size, "w");
    if (!file) return NULL;

    va_list args;
    va_start(args, format);
    voverprintf(file, format, args);
    va_end(args);

    fclose(file);
    return str;
}

int main() {
    overprintf("Римское число: %Ro\n", 552);
    overprintf("Цекендорфово представление: %Zr\n", 52);
    overprintf("Базовое преобразование (low): %Cv\n", 228, 16);
    overprintf("Базовое преобразование (upp): %CV\n", 227, 16);
    overprintf("Пеобразование в десятичную %to\n", "ff", 16);
    overprintf("Memory dump (int): %mi\n", 42);
    overprintf("Memory dump (float): %mf\n", 3.14f);

    return 0;
}