#include <C:\Users\spitl\source\repos\laba_1_2\laba_1_2\logical_values_array.h>


int test_logical_values_array(int argc, char **argv) {
	try {
		setlocale(LC_ALL, "Russian");

		// ������ �������������
		logical_values_array arr1(0b10101010101);
		logical_values_array arr2(0b110011101);

		// ����� ��������� �������������
		char buffer[33]; // 32 ���� + 1 ��� �������� �������
		arr1.to_binary_string(buffer);
		std::cout << "arr1: " << buffer << std::endl;

		arr2.to_binary_string(buffer);
		std::cout << "arr2: " << buffer << std::endl;
		
		// ������� ������������� ��������
		logical_values_array result;

		result = arr1 & arr2;
		result.to_binary_string(buffer);
		std::cout << "arr1 AND arr2: " << buffer << std::endl;
		
		result = arr1 | arr2;
		result.to_binary_string(buffer);
		std::cout << "arr1 OR arr2: " << buffer << std::endl;

		result = arr1 ^ arr2;
		result.to_binary_string(buffer);
		std::cout << "arr1 XOR arr2: " << buffer << std::endl;

		result = ~arr1;
		result.to_binary_string(buffer);
		std::cout << "NOT arr1: " << buffer << std::endl;

		result = arr1.implication(arr2);
		result.to_binary_string(buffer);
		std::cout << "arr1 IMPLICATION arr2: " << buffer << std::endl;

		result = arr1.equivalence(arr2);
		result.to_binary_string(buffer);
		std::cout << "arr1 EQUIVALENCE arr2: " << buffer << std::endl;

		// ������������� ��������� []
		std::cout << "Bit at index 1 of arr1: " << arr1[1] << std::endl;

		// ������������� ������������ ������ equals
		std::cout << "arr1 equals arr2: " << std::boolalpha << logical_values_array::equals(arr1, arr2) << std::endl;
	}
	catch (const std::invalid_argument& ex) {
		std::cerr << "������: " << ex.what() << std::endl;
	}
	catch (const std::exception& ex) {
		std::cerr << "����������� ������: " << ex.what() << std::endl;
	}

	return 0;
}