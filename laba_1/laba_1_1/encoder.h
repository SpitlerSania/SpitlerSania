#ifndef ENCODER_H
#define ENCODER_H
#include <iostream>
#include <fstream>
#include <stdexcept> // runtime_error

class Encoder final { 

private:
	unsigned char* key;
	size_t key_length;

	void RC4(unsigned char* data, size_t data_length);

	void Clone(const Encoder& other);

	//template <typename T>
	void my_swap(unsigned char &a, unsigned char &b);

public:


	Encoder(const unsigned char* key_data, size_t key_size);

	Encoder(const Encoder& other);

	Encoder& operator=(const Encoder& other);

	~Encoder() noexcept; // â cpp

	void Set_Key(const unsigned char* key_data, size_t key_size);

	void Encode(const char* input_file, const char* output_file, bool encryption);
};


#endif