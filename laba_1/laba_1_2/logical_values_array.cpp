#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string.h>
#include <C:\Users\spitl\source\repos\laba_1_2\laba_1_2\logical_values_array.h>

unsigned int logical_values_array::get_value() const {
    return _value;
}

	bool logical_values_array::get_bit(size_t index) const {
		if (index >= sizeof(unsigned int) * 8) {
			throw std::out_of_range("������ ��� ���������");
		}
		return (_value >> index) & 1; // ���������� �������� ����
	}

    bool logical_values_array::operator[](size_t index) const {
        return get_bit(index);
    }

    void logical_values_array::to_binary_string(char* buffer) const {
        if (!buffer) {
            throw std::invalid_argument("�������� ������ == NULL");
        }

        for (size_t i = 0; i < sizeof(unsigned int) * 8; ++i) {
            buffer[i] = ((_value >> (sizeof(unsigned int) * 8 - 1 - i)) & 1) ? '1' : '0';
        }
        buffer[sizeof(unsigned int) * 8] = '\0';
    }
    

	// ���������� ��������

        // �������� (NOT)
    logical_values_array logical_values_array::operator~() const {
        return logical_values_array(~_value);
    }

    // ���������� (AND)
    logical_values_array logical_values_array::operator&(const logical_values_array& other) const {
        return logical_values_array(_value & other._value);
    }

    // ���������� (OR)
    logical_values_array logical_values_array::operator|(const logical_values_array& other) const {
        return logical_values_array(_value | other._value);
    }

    // �������� �� ������ 2 (XOR)
    logical_values_array logical_values_array::operator^(const logical_values_array& other) const {
        return logical_values_array(_value ^ other._value);
    }

    // ���������� (A -> B) = ~A | B
    logical_values_array logical_values_array::implication(const logical_values_array& other) const {
        return logical_values_array(~_value | other._value);
    }

    // ������������ (A <- B) = A | ~B
    logical_values_array logical_values_array::coimplication(const logical_values_array& other) const {
        return logical_values_array(_value | ~other._value);
    }

    // ��������������� (A == B) = ~(A ^ B)
    logical_values_array logical_values_array::equivalence(const logical_values_array& other) const {
        return logical_values_array(~(_value ^ other._value));
    }

    // ������� ����� (NOR) = ~(A | B)
    logical_values_array logical_values_array::logical_values_array::pierce_arrow(const logical_values_array& other) const {
        return logical_values_array(~(_value | other._value));
    }

    // ����� ������� (NAND) = ~(A & B)
    logical_values_array logical_values_array::sheffer_stroke(const logical_values_array& other) const {
        return logical_values_array(~(_value & other._value));
    }

    // ����������� ����� ��������� ���� �������� �� ���������������
    bool logical_values_array::equals(const logical_values_array& a, const logical_values_array& b) {
        return a._value == b._value;
    }
