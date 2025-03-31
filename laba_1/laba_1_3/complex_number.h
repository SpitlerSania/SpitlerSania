#ifndef COMPLEX_NAMBER
#define COMPLEX_NAMBER
#include <iostream>
#include <fstream>
#include <stdexcept> // runtime_error

class Complex_number final {

private:

	double actual_part;

	double imaginary_part;


public:

    Complex_number(double r = 0.0, double i = 0.0) : actual_part(r), imaginary_part(i) {}

	// ������� � �������
    double getReal() const;
    double getImag() const;

    void setReal(double r);
	void setImag(double i);

    // �������� ��������� (+)
    Complex_number operator+(const Complex_number& other) const;

    // �������� ��������� (+=)
    Complex_number& operator+=(const Complex_number& other);

    // �������� ��������� (-)
    Complex_number operator-(const Complex_number& other) const;

    // �������� ��������� � ������������� (-=)
    Complex_number& operator-=(const Complex_number& other);

    // �������� ��������� (*)
    Complex_number operator*(const Complex_number& other) const;

    // �������� ��������� � ������������� (*=)
    Complex_number& operator*=(const Complex_number& other);

    // �������� ������� (/)
    Complex_number operator/(const Complex_number& other) const;

    // �������� ������� � ������������� (/=)
    Complex_number& operator/=(const Complex_number& other);

    // ����� ��� ���������� ������ ������������ �����
    double magnitude() const;

    // ����� ��� ���������� ��������� ������������ ����� (� ��������)
    double argument() const;

    // ������������� �������� ������� � ����� (<<)
    friend std::ostream& operator<<(std::ostream& os, const Complex_number& c);

    // ������������� �������� �������� �� ������ (>>)
    friend std::istream& operator>>(std::istream& is, Complex_number& c);

    ~Complex_number() = default;

    Complex_number(const Complex_number& other) = default;

    Complex_number& operator=(const Complex_number& other) = default;
};

#endif