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
			throw std::out_of_range("Индекс вне диапазона");
		}
		return (_value >> index) & 1; // Возвращаем значение бита
	}

    bool logical_values_array::operator[](size_t index) const {
        return get_bit(index);
    }

    void logical_values_array::to_binary_string(char* buffer) const {
        if (!buffer) {
            throw std::invalid_argument("Значение буфера == NULL");
        }

        for (size_t i = 0; i < sizeof(unsigned int) * 8; ++i) {
            buffer[i] = ((_value >> (sizeof(unsigned int) * 8 - 1 - i)) & 1) ? '1' : '0';
        }
        buffer[sizeof(unsigned int) * 8] = '\0';
    }
    

	// ЛОГИЧЕСКИЕ ОПЕРАЦИИ

        // Инверсия (NOT)
    logical_values_array logical_values_array::operator~() const {
        return logical_values_array(~_value);
    }

    // Конъюнкция (AND)
    logical_values_array logical_values_array::operator&(const logical_values_array& other) const {
        return logical_values_array(_value & other._value);
    }

    // Дизъюнкция (OR)
    logical_values_array logical_values_array::operator|(const logical_values_array& other) const {
        return logical_values_array(_value | other._value);
    }

    // Сложение по модулю 2 (XOR)
    logical_values_array logical_values_array::operator^(const logical_values_array& other) const {
        return logical_values_array(_value ^ other._value);
    }

    // Импликация (A -> B) = ~A | B
    logical_values_array logical_values_array::implication(const logical_values_array& other) const {
        return logical_values_array(~_value | other._value);
    }

    // Коимпликация (A <- B) = A | ~B
    logical_values_array logical_values_array::coimplication(const logical_values_array& other) const {
        return logical_values_array(_value | ~other._value);
    }

    // Эквивалентность (A == B) = ~(A ^ B)
    logical_values_array logical_values_array::equivalence(const logical_values_array& other) const {
        return logical_values_array(~(_value ^ other._value));
    }

    // Стрелка Пирса (NOR) = ~(A | B)
    logical_values_array logical_values_array::logical_values_array::pierce_arrow(const logical_values_array& other) const {
        return logical_values_array(~(_value | other._value));
    }

    // Штрих Шеффера (NAND) = ~(A & B)
    logical_values_array logical_values_array::sheffer_stroke(const logical_values_array& other) const {
        return logical_values_array(~(_value & other._value));
    }

    // Статический метод сравнения двух объектов по эквивалентности
    bool logical_values_array::equals(const logical_values_array& a, const logical_values_array& b) {
        return a._value == b._value;
    }
