#include <stdio.h>
#include <math.h>
#include <locale.h>

//sign- функция для определения знака числа x.

int sign(double x) {

    if (x > 0) {
        return 1;
    }
    else if (x < 0) {
        return -1;
    }
    else {
        return 0;
    }
};

int checking_for_bulge(int n, double* x, double* y) { // Функция для проверки выпуклости многоугольника
    //n — общее количество вершин многоугольника
    double lastCrossProduct = 0;
    int i;
    int j = 10;
    int l = 10;

    for (i = 0; i < n; ++i) {
        j = (i + 1) % n;
        l = (j + 1) % n;
    }

    // Вычисляем компоненты
    double diff_x1 = x[j] - x[i];
    double diff_x2 = y[j] - y[i];
    double diff_y1 = x[l] - x[j];
    double diff_y2 = y[l] - y[j];

    double vector_product = diff_x1 * diff_x2 - diff_y1 * diff_y2; // Векторное произведение

    if (i == 0) {
        lastCrossProduct = vector_product;
    }
    else {
        if (sign(vector_product) != sign(lastCrossProduct))
            return 0; // Многоугольник не является выпуклым
        lastCrossProduct = vector_product;
    }

    return 1;// Многоугольник является выпуклым
}

int main() {
    setlocale(LC_ALL, "Rus");
    // Пример использования функции
    int n = 4;
    double x[] = { 0, 4, 4, 0 };
    double y[] = { 0, 0, 4, 4 };

    if (checking_for_bulge(n, x, y)) {
        printf("Многоугольник является выпуклым.\n");
    }
    else {
        printf("Многоугольник не является выпуклым.\n");
    }

    return 0;
}