#include <C:\Users\spitl\source\repos\laba_1_3\laba_1_3\complex_number.h>

int test_Complex_number(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");

	try {
		
		double ap_1;
		double ip_1;
		double ap_2;
		double ip_2;

		std::cout << "������� ������ ����� ������������ �����: " << std::endl;
		std::cin >> ap_1;
		std::cout << "������� ������ ����� ������������ �����: " << std::endl;
		std::cin >> ip_1;

		std::cout << "������� ������ ����� ������������ �����: " << std::endl;
		std::cin >> ap_2;
		std::cout << "������� ������ ����� ������������ �����: " << std::endl;
		std::cin >> ip_2;


		Complex_number a(ap_1, ip_1);
		Complex_number b(ap_2, -ip_2);

		// ����� ����������� �����
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

		// ��������
		Complex_number sum = a + b;
		std::cout << "a + b = " << sum << std::endl;

		// ���������
		Complex_number diff = a - b;
		std::cout << "a - b = " << diff << std::endl;

		// ���������
		Complex_number prod = a * b;
		std::cout << "a * b = " << prod << std::endl;

		// �������
		Complex_number quot = a / b;
		std::cout << "a / b = " << quot << std::endl;

		// ������ ����� a
		std::cout << "|a| = " << a.magnitude() << std::endl;

		// �������� ����� a
		std::cout << "�������� a = " << a.argument() << " ������" << std::endl;

		// ���� ������������ ����� � ����������
		Complex_number c;
		std::cin >> c;
		std::cout << "��������� �����: " << c << std::endl;

		return 0;
	}
	catch (const std::invalid_argument& ex) {
		std::cerr << "������: " << ex.what() << std::endl;
	}
	catch (const std::exception& ex) {
		std::cerr << "����������� ������: " << ex.what() << std::endl;

		return 0;
	}
}