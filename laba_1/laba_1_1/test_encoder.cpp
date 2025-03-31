#include "encoder.h"


int test_encoder(int argc, char **argv) {
	try {

		setlocale(LC_ALL, "Russian");

		unsigned char key[] = { 0x52, 0x1488, 0x2001, 0x1941, 0x1945 };
		size_t key_length = sizeof(key);

		Encoder encoder(key, key_length);

		encoder.Encode("test1.txt", "encrypted_text.bin", true);
		encoder.Encode("encrypted_text.bin", "decrypted_text.txt", false);
		std::cout << "Текстовый файл успешно обработан!" << std::endl;

		encoder.Encode("h3.jpg", "encrypted_image.bin", true);
		encoder.Encode("encrypted_image.bin", "decrypted_image.jpg", false);
		std::cout << "Графический файл успешно обработан!" << std::endl;

		encoder.Encode("vechno_molodoi.mp3", "encrypted_audio.bin", true);
		encoder.Encode("encrypted_audio.bin", "decrypted_audio.mp3", false);
		std::cout << "Аудиофайл успешно обработан!" << std::endl;

		encoder.Encode("Repo.mp4", "encrypted_video.bin", true);
		encoder.Encode("encrypted_video.bin", "decrypted_video.mp4", false);
		std::cout << "Видеофайл успешно обработан!" << std::endl;

		encoder.Encode("REPO.exe", "encrypted_program.bin", true);
		encoder.Encode("encrypted_program.bin", "decrypted_program.exe", false);
		std::cout << "Исполняемый файл успешно обработан!" << std::endl;
	}

	catch (const std::invalid_argument& ex) {
		std::cerr << "Ошибка: " << ex.what() << std::endl;
	}
	catch (const std::exception& ex) {
		std::cerr << "Неизвестная ошибка: " << ex.what() << std::endl;
	}
	
	return 0;
}