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

	// Геттеры и сеттеры
    double getReal() const;
    double getImag() const;

    void setReal(double r);
	void setImag(double i);

    // Оператор вычитания (+)
    Complex_number operator+(const Complex_number& other) const;

    // Оператор вычитания (+=)
    Complex_number& operator+=(const Complex_number& other);

    // Оператор вычитания (-)
    Complex_number operator-(const Complex_number& other) const;

    // Оператор вычитания с присваиванием (-=)
    Complex_number& operator-=(const Complex_number& other);

    // Оператор умножения (*)
    Complex_number operator*(const Complex_number& other) const;

    // Оператор умножения с присваиванием (*=)
    Complex_number& operator*=(const Complex_number& other);

    // Оператор деления (/)
    Complex_number operator/(const Complex_number& other) const;

    // Оператор деления с присваиванием (/=)
    Complex_number& operator/=(const Complex_number& other);

    // Метод для вычисления модуля комплексного числа
    double magnitude() const;

    // Метод для вычисления аргумента комплексного числа (в радианах)
    double argument() const;

    // Перегруженный оператор вставки в поток (<<)
    friend std::ostream& operator<<(std::ostream& os, const Complex_number& c);

    // Перегруженный оператор выгрузки из потока (>>)
    friend std::istream& operator>>(std::istream& is, Complex_number& c);

    ~Complex_number() = default;

    Complex_number(const Complex_number& other) = default;

    Complex_number& operator=(const Complex_number& other) = default;
};

#endif