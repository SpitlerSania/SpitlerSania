#include <stdio.h>


const char* str_in_str(const char* line, const char* word) {
	if (*word == '\0') {
		return (char*)line;
	}

	while (*line != '\0') {
		const char* l = line;
		const char* w = word;

		while (*l && *w && *l == *w) {
			l++;
			w++;
		}
		if (*w == '\0') {
			return word;
		}
		line++;
	}
	return NULL; //если строка не найдениа
}

int main() {
	const char* line = "Find a substring in a string";
	const char* word = "substring";

	const char* result = str_in_str(line, word);

	if (result) {
		long index = result - line;
		printf("The word in the string is found = %s", word);
	}
	else {
		printf("The word '%s' was not found", word);
	}
	return 0;
}
