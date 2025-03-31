#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <C:\Users\spitl\source\repos\laba_1_4\laba_1_4\Working_with_matrices.h>


Working_with_matrices::MatrixIndexError::MatrixIndexError()
	: std::out_of_range("������ ������� ��� ���������� ������!!!") {}

Working_with_matrices::RowProxy::RowProxy(double* row, size_t cols) : row(row), cols(cols) {}

double& Working_with_matrices::RowProxy::operator[](size_t col) {
	if (col >= cols) throw MatrixIndexError();
	return row[col];
}

const double& Working_with_matrices::RowProxy::operator[](size_t col) const {
	if (col >= cols) throw MatrixIndexError();
	return row[col];
}

// ����������
Working_with_matrices::~Working_with_matrices() {
	for (size_t i = 0; i < line; ++i) {
		delete[] data[i];
	}
	delete[] data;
}

// �������� ������������
Working_with_matrices& Working_with_matrices::operator=(const Working_with_matrices& other) {
	if (this != &other) {

		for (size_t i = 0; i < line; ++i) {
			delete[] data[i];
		}
		delete[] data;

		line = other.line;
		column = other.column;
		data = new double* [line];
		for (size_t i = 0; i < line; ++i) {
			data[i] = new double[column];
			for (size_t j = 0; j < column; ++j) {
				data[i][j] = other.data[i][j];
			}
		}
	}
	return *this;
}

Working_with_matrices::Working_with_matrices(size_t line, size_t column) : line(line), column(column) {
	data = new double* [line];
	for (size_t i = 0; i < line; ++i) {
		data[i] = new double[column] {0};
	}
}

double& Working_with_matrices::Access(size_t i, size_t j) {
	// �������� ������ �� ������� �������
	if (i >= line || j >= column) {
		throw MatrixIndexError();
	}
	// ���������� ������ �� �������, �������� ��� �����������
	return data[i][j];
}

const double& Working_with_matrices::Access(size_t i, size_t j) const {
	if (i >= line || j >= column) {
		throw std::out_of_range("������ ������� �� ����� �������� �� �������!!!");
	}
	return data[i][j];
}

Working_with_matrices::RowProxy Working_with_matrices::operator[](size_t row) {
	if (row >= line) {
		throw MatrixIndexError();
	}
	return RowProxy(data[row], column);
}

// ���������� ��������� [] ��� ����������� ��������
const Working_with_matrices::RowProxy Working_with_matrices::operator[](size_t row) const {
	if (row >= line) {
		throw MatrixIndexError();
	}
	return RowProxy(data[row], column);
}

// ����������� �����������
Working_with_matrices::Working_with_matrices(const Working_with_matrices& other) : line(other.line), column(other.column) {
	data = new double* [line];
	for (size_t i = 0; i < line; ++i) {
		data[i] = new double[column];
		for (size_t j = 0; j < column; ++j) {
			data[i][j] = other.data[i][j];
		}
	}
}


//__________________________________���������__________________________________

//�������� ��������
Working_with_matrices Working_with_matrices::operator+(const Working_with_matrices& other) const {
	if (line != other.line || column != other.column) {
		throw std::invalid_argument("������� ������ ���� ����������� �������!!! ");
	}

	Working_with_matrices result(line, column);

	for (size_t i = 0; i < line; ++i) {
		for (size_t j = 0; j < column; ++j) {
			result.data[i][j] = data[i][j] + other.data[i][j];
		}
	}
	return result;
}

//�������� ���������
Working_with_matrices Working_with_matrices::operator*(const Working_with_matrices& other) const {
	if (column != other.line) {
		throw std::invalid_argument("���������� �������� ������ ������� ������ ���� = ����������� ����� ������ �������!!! ");
	}

	Working_with_matrices result(line, column);

	for (size_t i = 0; i < line; ++i) {
		for (size_t j = 0; j < column; ++j) {
			double sum = 0;
			for (size_t k = 0; k < column; ++k) {
				sum += data[i][k] * other.data[k][j];
			}
			result.data[i][j] = sum;
		}
	}
	return result;
}

// ��������� ������� �� �����
Working_with_matrices Working_with_matrices::operator*(double scalar) const {
	Working_with_matrices result(line, column);

	for (size_t i = 0; i < line; ++i) {
		for (size_t j = 0; j < column; ++j) {
			result.data[i][j] = data[i][j] * scalar;
		}
	}
	return result;
}

// ��������� ����� �� �������
Working_with_matrices operator*(double scalar, const Working_with_matrices& matrices) {
	return matrices * scalar;
}

//�������� ���������
Working_with_matrices Working_with_matrices::operator-(const Working_with_matrices& other) const {
	if (line != other.line || column != other.column) {
		throw std::invalid_argument("������� ������ ���� ����������� �������!!! ");
	}

	Working_with_matrices result(line, column);

	for (size_t i = 0; i < line; ++i) {
		for (size_t j = 0; j < column; ++j) {
			result.data[i][j] = data[i][j] - other.data[i][j];
		}
	}
	return result;
}

// ���������������� �������
double Working_with_matrices::Determinant() const {
	if (line != column) {
		throw std::logic_error("������� ������ ���� ����������!!!");
	}

	Working_with_matrices temp(*this); // ����� �������
	double det = 1.0;

	for (size_t k = 0; k < line; ++k) {
		// ����� �������� ��������
		size_t max_row = k;
		for (size_t i = k + 1; i < line; ++i) {
			if (std::abs(temp.Access(i, k)) > std::abs(temp.Access(max_row, k))) {
				max_row = i;
			}
		}

		// ������������ �����
		if (max_row != k) {
			for (size_t j = 0; j < line; ++j) {
				std::swap(temp.Access(k, j), temp.Access(max_row, j));
			}
			det = -det;
		}

		// �������� �� �������������
		if (std::abs(temp.Access(k, k)) < 1e-12) {
			return 0.0;
		}

		// ���������� � ������������ ����
		for (size_t i = k + 1; i < line; ++i) {
			double factor = temp.Access(i, k) / temp.Access(k, k);
			for (size_t j = k; j < line; ++j) {
				temp.Access(i, j) -= factor * temp.Access(k, j);
			}
		}

		det *= temp.Access(k, k);
	}
	return det;
}

Working_with_matrices Working_with_matrices::Reverse() const {
	if (line != column) {
		throw std::invalid_argument("������� ������ ���� ����������!!!");
	}

	double det = this->Determinant();
	if (std::abs(det) < 1e-12) {
		throw std::invalid_argument("������� �������� ����������� � �� ����� ���� �������������!!!");
	}

	Working_with_matrices temp(line, column * 2);

	// ������������� ����������� ������� [A|I]
	for (size_t i = 0; i < line; ++i) {
		for (size_t j = 0; j < column; ++j) {
			temp.Access(i, j) = data[i][j];
		}
		temp.Access(i, column + i) = 1.0;
	}


	// ������ ��� ������ ������
	for (size_t i = 0; i < line; ++i) {
		// ����� �������� ��������
		size_t pivot = i;
		for (size_t j = i + 1; j < line; ++j) {
			if (std::abs(temp.Access(j, i)) > std::abs(temp.Access(pivot, i))) {
				pivot = j;
			}
		}

		if (pivot != i) {
			for (size_t j = 0; j < column * 2; ++j) {
				std::swap(temp.Access(i, j), temp.Access(pivot, j));
			}
		}

		// ���������� ������
		double factor = temp.Access(i, i);
		for (size_t j = 0; j < column * 2; ++j) {
			temp.Access(i, j) /= factor;
		}

		// ��������� �������
		for (size_t j = 0; j < line; ++j) {
			if (j != i) {
				double factor = temp.Access(j, i);
				for (size_t k = 0; k < column * 2; ++k) {
					temp.Access(j, k) -= factor * temp.Access(i, k);
				}
			}
		}
	}

	// ���������� �������� �������
	Working_with_matrices result(line, column);
	for (size_t i = 0; i < line; ++i) {
		for (size_t j = 0; j < column; ++j) {
			result.Access(i, j) = temp.Access(i, column + j);
		}
	}

	return result;
}