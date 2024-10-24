#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)


void xor_encrypt_decrypt(const char* input_file, const char* output_file, char key) {
    FILE* fin = fopen(input_file, "rb"); // входной файл, который нужно зашифровать или расшифровать.
    FILE* fout = fopen(output_file, "wb");// выходной файл, куда будет записан результат.

    if (!fin || !fout) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    int byte;
    while ((byte = fgetc(fin)) != EOF) {
        // Применяем XOR с ключом и записываем в выходной файл
        fputc(byte ^ key, fout);
    }

    fclose(fin);
    fclose(fout);
}

int main() {
    char input_file[256];
    char output_file[256];
    char key;
    int operation;

    printf("Enter input file name: ");
    scanf("%255s", input_file);

    printf("Enter the output file name: ");
    scanf("%255s", output_file);

    printf("Enter  key: ");
    scanf(" %c", &key);

    printf("Select operation: 1 for Encrypt, 2 for Decrypt: ");
    scanf("%d", &operation);

    if (operation == 1) {
        xor_encrypt_decrypt(input_file, output_file, key);
        printf("File encrypted successfully.\n");
    }
    else if (operation == 2) {
        xor_encrypt_decrypt(input_file, output_file, key);
        printf("File decrypted successfully.\n");
    }
    else {
        printf("Invalid operation selected.\n");
    }

    return 0;
}
