#include <stdio.h>
#include <ctype.h>
#include <locale.h>


int main(void) {
	char str[] = "i wrote almost the entire program myself, getting smarter";
	char* ptr = str;

	for (int i = 0; *ptr != '\0'; ++i, ++ptr) {
		if (i % 2 == 1) {
			*ptr = (char)toupper((unsigned char)*ptr);
		}
	}

	setlocale(LC_ALL, "Russian");

	printf("Результат: %s", str);

	return 0;
}