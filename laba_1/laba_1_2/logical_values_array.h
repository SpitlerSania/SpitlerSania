#ifndef ENCODER_H
#define ENCODER_H
#include <iostream>
#include <fstream>
#include <stdexcept> // runtime_error

class logical_values_array final {

private:
	int _value;

public:

	logical_values_array(unsigned int value = 0) : _value(value) {}

	unsigned int get_value() const;

	bool get_bit(size_t index) const;

	bool operator[](size_t index) const;

	void to_binary_string(char* buffer) const;


	// ���������� ��������

		// �������� (NOT)
	logical_values_array operator~() const;

	// ���������� (AND)
	logical_values_array operator&(const logical_values_array& other) const;

	// ���������� (OR)
	logical_values_array operator|(const logical_values_array& other) const;

	// �������� �� ������ 2 (XOR)
	logical_values_array operator^(const logical_values_array& other) const;

	// ���������� (A -> B) = ~A | B
	logical_values_array implication(const logical_values_array& other) const;

	// ������������ (A <- B) = A | ~B
	logical_values_array coimplication(const logical_values_array& other) const;

	// ��������������� (A == B) = ~(A ^ B)
	logical_values_array equivalence(const logical_values_array& other) const;

	// ������� ����� (NOR) = ~(A | B)
	logical_values_array pierce_arrow(const logical_values_array& other) const;

	// ����� ������� (NAND) = ~(A & B)
	logical_values_array sheffer_stroke(const logical_values_array& other) const;

	// ����������� ����� ��������� ���� �������� �� ���������������
	static bool equals(const logical_values_array& a, const logical_values_array& b);

	~logical_values_array() = default;

	logical_values_array(const logical_values_array& other) = default;

	logical_values_array& operator=(const logical_values_array& other) = default;
};


#endif
