#ifndef WORKING_WITH_MATRICES_H 
#define WORKING_WITH_MATRICES_H 
#include <iostream>
#include <stdexcept>
#include <cmath>

class Working_with_matrices final{

private:
	double** data;
	size_t line;
	size_t column;

public:
	// Вложенный класс-исключение
	class MatrixIndexError : public std::out_of_range {
	public:
		MatrixIndexError();
	};

	// Прокси-класс для реализации [][]
	class RowProxy {
	private:
		double* row;
		size_t cols;
	public:
		RowProxy(double* row, size_t cols);
		double& operator[](size_t col);
		const double& operator[](size_t col) const;
	};

	// Конструкторы и деструктор
	Working_with_matrices(size_t line, size_t column);
	Working_with_matrices(const Working_with_matrices& other);
	~Working_with_matrices();

	    // Оператор присваивания
    Working_with_matrices& operator=(const Working_with_matrices& other);

	// Методы доступа
	double& Access(size_t i, size_t j);
	const double& Access(size_t i, size_t j) const;
	RowProxy operator[](size_t row);
	const RowProxy operator[](size_t row) const;

	//__________________________________ОПЕРАТОРЫ__________________________________
	// Арифметические операторы
	Working_with_matrices operator+(const Working_with_matrices& other) const;
	Working_with_matrices operator-(const Working_with_matrices& other) const;
	Working_with_matrices operator*(const Working_with_matrices& other) const;
	Working_with_matrices operator*(double scalar) const;
	friend Working_with_matrices operator*(double scalar, const Working_with_matrices& matrices);
	
	// Операции с матрицами
	double Determinant() const;
	Working_with_matrices Reverse() const;
};

#endif  WORKING_WITH_MATRICES_H 