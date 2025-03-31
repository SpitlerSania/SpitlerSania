#include "Working_with_matrices.h"
#include <iostream>


int test_Working_with_matrices(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");

    try {
        std::cout << "Создание матрицы и доступ к элементам\n";
        Working_with_matrices m1(2, 3);
        m1.Access(0, 0) = 1; m1.Access(0, 1) = 2; m1.Access(0, 2) = 3;
        m1.Access(1, 0) = 4; m1.Access(1, 1) = 5; m1.Access(1, 2) = 6;

        // Вывод через метод Access()
        for (size_t i = 0; i < 2; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                std::cout << m1.Access(i, j) << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";

        std::cout << "Использование оператора[]\n";
        m1[0][0] = 10; m1[1][2] = 60;
        for (size_t i = 0; i < 2; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                std::cout << m1[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";

        std::cout << "Матричные операции\n";
        Working_with_matrices m2(2, 3);
        m2[0][0] = 2; m2[0][1] = 3; m2[0][2] = 4;
        m2[1][0] = 5; m2[1][1] = 6; m2[1][2] = 7;

        auto m3 = m1 + m2;
        std::cout << "Сложение матриц:\n";
        for (size_t i = 0; i < 2; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                std::cout << m3[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";

        std::cout << "Скалярное умножение\n";
        auto m4 = m1 * 2.5;
        for (size_t i = 0; i < 2; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                std::cout << m4[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";

        std::cout << "Матричное умножение\n";
        Working_with_matrices m5(3, 2);
        m5[0][0] = 1; m5[0][1] = 2;
        m5[1][0] = 3; m5[1][1] = 4;
        m5[2][0] = 5; m5[2][1] = 6;

        auto m6 = m1 * m5;
        std::cout << "Результат умножения матрицы (2x2):\n";
        for (size_t i = 0; i < 2; ++i) {
            for (size_t j = 0; j < 2; ++j) {
                std::cout << m6[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";

        std::cout << "Определитель и обратная матрица\n";
        Working_with_matrices m7(2, 2);
        m7[0][0] = 4; m7[0][1] = 7;
        m7[1][0] = 2; m7[1][1] = 6;

        double det = m7.Determinant();
        std::cout << "Determinant: " << det << "\n";

        if (det != 0) {
            auto inv = m7.Reverse();
            std::cout << "Обратная матрица:\n";
            for (size_t i = 0; i < 2; ++i) {
                for (size_t j = 0; j < 2; ++j) {
                    std::cout << inv[i][j] << " ";
                }
                std::cout << "\n";
            }
        }

        std::cout << "\nОшибка обращения\n";
        try {
            std::cout << "Попытка получить доступ к недопустимому элементу: ";
            std::cout << m1[5][2] << "\n";  // Вызовет исключение
        }
        catch (const Working_with_matrices::MatrixIndexError& e) {
            std::cerr << "Перехваченное исключение: " << e.what() << "\n";
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}