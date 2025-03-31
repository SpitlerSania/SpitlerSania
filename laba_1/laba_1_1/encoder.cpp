#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <stdexcept> // runtime_error
#include <string.h>
#include "encoder.h"

void Encoder::my_swap(unsigned char &a, unsigned char &b) {
	unsigned char temp = a;
	a = b;
	b = temp;
}

void Encoder::RC4(unsigned char* data, size_t data_length) {

	unsigned char S[256];
	int i = 0, j = 0;

	//Инициализация S-блока (KSA) key-scheduling algorithm (алгоритм планирования ключей)
	for (i = 0; i < 256; i++) {
		S[i] = i;
	}

	for (i = 0; i < 256; i++) {
		j = (j + S[i] + key[i % key_length]) % 256;
		my_swap(S[i], S[j]);
	}

	//pseudo-random generation algorithm (PRGA)
	for (int k = 0; k < data_length; ++k) {
		i = (i + 1) % 256;
		j = (j + S[i]) % 256;
		my_swap(S[i], S[j]);
		data[k] ^= S[(S[i] + S[j]) % 256];
	}
}

void Encoder::Clone(const Encoder& other) {
	key = new unsigned char[other.key_length];

	std::strcpy(reinterpret_cast<char*>(key), reinterpret_cast<char*>(other.key));

	key_length = other.key_length;

}

Encoder::Encoder(const Encoder& other) {

	Clone(other);

}

Encoder& Encoder::operator=(const Encoder& other) {
	if (&other == this) {
		return *this;
	}

	delete[] key;

	Clone(other); 

	return *this;

}

Encoder::Encoder(const unsigned char* key_data, size_t key_size) : key_length(key_size) {
	if (key_data == NULL) {
		throw std::invalid_argument("Ключ не может быть nullptr!!!!!!!");
	}

	key = new unsigned char[key_length];
	//std::copy(key_data, key_data + key_length, key);
	std::memcpy(key, key_data, key_size);
}

Encoder::~Encoder() {
	delete[] key;
}

void Encoder::Set_Key(const unsigned char* key_data, size_t key_size) {
	if (key_data == NULL) {
		throw std::invalid_argument("Ключ не может быть nullptr!!!!!!!");
	}

	delete[] key;
	key_length = key_size;
	key = new unsigned char[key_length];
	std::memcpy(key, key_data, key_size);
}

void Encoder::Encode(const char* input_file, const char* output_file, bool encryption) { //nulptr in out

	if (input_file == nullptr) {
		throw std::invalid_argument("Файл не может быть nullptr!!!!!!!");
	}
	std::ifstream inp_f(input_file, std::ios::binary);

	if (output_file == nullptr) {
		throw std::invalid_argument("Файл не может быть nullptr!!!!!!!");
	}
	std::ofstream out;
	out.open(output_file, std::ios::binary);

	unsigned char buffer[BUFSIZ];

		while (inp_f) {
			inp_f.read(reinterpret_cast<char*>(buffer), BUFSIZ);
			size_t bytes_read = inp_f.gcount();

			try {

			RC4(buffer, bytes_read);

			out.write(reinterpret_cast<char*>(buffer), bytes_read);

			}
			catch (const std::exception& ex) {

				inp_f.close();
				out.close();
				throw; // Повторно выбрасываем исключение
			}
		}

	inp_f.close(); // закрывается сам, можно не писать
	out.close(); // закрывается сам, можно не писать
}