#include <stdio.h>
#include <string.h>
#define EMPTY_STRING 1

char Revers_String(char* str) {
	int len = strlen(str);

	int i, temp;

	if (str == NULL) {
		printf("Error");
		return EMPTY_STRING;
	}

	for (i = 0; i < len / 2; ++i) {
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}

	return str;
}

int main() {
	char str[] = "Hello World";

	Revers_String(str);
	printf("%s", str);

	return 0;
}
