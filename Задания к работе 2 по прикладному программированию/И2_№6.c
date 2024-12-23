#include<stdio.h>
#include<locale.h>
#include <stdarg.h>
#pragma warning (disable: 4996)

double valuepo_lynomial(int degree, double z, ...) {
	double result = 0;
	va_list args;


	va_start(args, z);

	for (int i = degree; i >= 0; i--) {
		double coeff = va_arg(args, double);
		result = result * z + coeff;
	}
	
	va_end (args);

	return result;
}

int main() {
	setlocale(LC_ALL, "Rus");

	double x;
	int degree;
	double coefficients[15];

	printf("Введите точку для вычисления многочлена: ");
	scanf("%lf", &x);

	printf("Введите степень многочлена: ");
	scanf("%d", &degree);

	if (degree < 0 || degree > 15) {
		printf("Error: The degree should be in the range from 0 to 14.\n");
		return 1;
	}

	printf("Введите %d коэффициентов многочлена (начиная с старшего):\n", degree + 1);
	for (int i = 0; i <= degree; i++) {
		scanf("%lf", &coefficients[i]);
	}

	double value = valuepo_lynomial(degree, x);
	for (int i = degree; i >= 0; i--) {
		value = valuepo_lynomial(i, x, coefficients[i]);

		printf("Значение многочлена в точке =  %.2f\n", value);

		return 0;
	}
}