#include <stdio.h>
#include <string.h>
#include <locale.h>


char *my_strcat( char* first_word, char* second_word) {
	char* ptr = first_word;
	while (*ptr != '\0'){
		ptr++;
	}
	
	while ((*ptr++ = *second_word++) != '\0');

	return 1;
}

int main() {
	setlocale(LC_ALL, "Russian");
	char word_1[30] = "love ";
	char word_2[] = "programming";

	my_strcat(word_1, word_2);

	printf("Соединенные строки: %s", word_1);

	return 0;
}