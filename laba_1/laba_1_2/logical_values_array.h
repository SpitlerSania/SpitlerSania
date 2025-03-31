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


	// ЛОГИЧЕСКИЕ ОПЕРАЦИИ

		// Инверсия (NOT)
	logical_values_array operator~() const;

	// Конъюнкция (AND)
	logical_values_array operator&(const logical_values_array& other) const;

	// Дизъюнкция (OR)
	logical_values_array operator|(const logical_values_array& other) const;

	// Сложение по модулю 2 (XOR)
	logical_values_array operator^(const logical_values_array& other) const;

	// Импликация (A -> B) = ~A | B
	logical_values_array implication(const logical_values_array& other) const;

	// Коимпликация (A <- B) = A | ~B
	logical_values_array coimplication(const logical_values_array& other) const;

	// Эквивалентность (A == B) = ~(A ^ B)
	logical_values_array equivalence(const logical_values_array& other) const;

	// Стрелка Пирса (NOR) = ~(A | B)
	logical_values_array pierce_arrow(const logical_values_array& other) const;

	// Штрих Шеффера (NAND) = ~(A & B)
	logical_values_array sheffer_stroke(const logical_values_array& other) const;

	// Статический метод сравнения двух объектов по эквивалентности
	static bool equals(const logical_values_array& a, const logical_values_array& b);

	~logical_values_array() = default;

	logical_values_array(const logical_values_array& other) = default;

	logical_values_array& operator=(const logical_values_array& other) = default;
};


#endif
