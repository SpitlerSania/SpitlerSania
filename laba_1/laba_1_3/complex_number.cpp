#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string.h>
#include <cmath> 
#include <C:\Users\spitl\source\repos\laba_1_3\laba_1_3\complex_number.h>


double Complex_number::getReal() const { return actual_part; }
double Complex_number::getImag() const { return imaginary_part; }

void Complex_number::setReal(double r) { actual_part = r; }
void Complex_number::setImag(double i) { imaginary_part = i; }

// �������� �������� (+)
Complex_number Complex_number::operator+(const Complex_number& other) const {
    return Complex_number(actual_part + other.actual_part, imaginary_part + other.imaginary_part);
}

// �������� �������� (+=)
Complex_number& Complex_number::operator+=(const Complex_number& other) {
    actual_part += other.actual_part;
    imaginary_part += other.imaginary_part;
    return *this;
}

// �������� ��������� (-)
Complex_number Complex_number::operator-(const Complex_number& other) const {
    return Complex_number(actual_part - other.actual_part, imaginary_part - other.imaginary_part);
}

// �������� ��������� � ������������� (-=)
Complex_number& Complex_number::operator-=(const Complex_number& other) {
    actual_part -= other.actual_part;
    imaginary_part -= other.imaginary_part;
    return *this;
}

// �������� ��������� (*)
Complex_number Complex_number::operator*(const Complex_number& other) const {
    return Complex_number(actual_part * other.actual_part - imaginary_part * other.imaginary_part,
        actual_part * other.imaginary_part + imaginary_part * other.actual_part);
}

// �������� ��������� � ������������� (*=)
Complex_number& Complex_number::operator*=(const Complex_number& other) {
    double newReal = actual_part * other.actual_part - imaginary_part * other.imaginary_part;
    double newImag = actual_part * other.imaginary_part + imaginary_part * other.actual_part;
    actual_part = newReal;
    imaginary_part = newImag;
    return *this;
}

// �������� ������� (/)
Complex_number Complex_number::operator/(const Complex_number& other) const {
    double denominator = other.actual_part * other.actual_part + other.imaginary_part * other.imaginary_part;
    return Complex_number((actual_part * other.actual_part + imaginary_part * other.imaginary_part) / denominator,
        (imaginary_part * other.actual_part - actual_part * other.imaginary_part) / denominator);
}

// �������� ������� � ������������� (/=)
Complex_number& Complex_number::operator/=(const Complex_number& other) {
    double denominator = other.actual_part * other.actual_part + other.imaginary_part * other.imaginary_part;
    double newReal = (actual_part * other.actual_part + imaginary_part * other.imaginary_part) / denominator;
    double newImag = (imaginary_part * other.actual_part - actual_part * other.imaginary_part) / denominator;
    actual_part = newReal;
    imaginary_part = newImag;
    return *this;
}

// ����� ��� ���������� ������ ������������ �����
double Complex_number::magnitude() const {
    return std::sqrt(actual_part * actual_part + imaginary_part * imaginary_part);
}

// ����� ��� ���������� ��������� ������������ ����� (� ��������)
double Complex_number::argument() const {
    return std::atan2(imaginary_part, actual_part);
}

// ������������� �������� ������� � ����� (<<)
std::ostream& operator<<(std::ostream& os, const Complex_number& c) {
    if (c.imaginary_part >= 0) {
        os << c.actual_part << " + " << c.imaginary_part << "i";
    }
    else {
        os << c.actual_part << " - " << -c.imaginary_part << "i";
    }
    return os;
}

// ������������� �������� �������� �� ������ (>>)
std::istream& operator>>(std::istream& is, Complex_number& c) {
    std::cout << "������� �������������� �����: ";
    is >> c.actual_part;
    std::cout << "������� ������ �����: ";
    is >> c.imaginary_part;
    return is;
}