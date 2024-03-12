#include <iostream>
#include "macierz.h"

int main() {
    // Przyk³ady u¿ycia klasy macierz
    macierz A;
    A.set(0, 0, 9);
    A.set(0, 1, 8);
    A.set(1, 0, 3);
    A.set(1, 1, 3);

    macierz B;
    B.set(0, 0, 3);
    B.set(0, 1, 2);
    B.set(1, 0, 7);
    B.set(1, 1, 7);

    std::cout << "Macierz A:\n" << A << std::endl;
    std::cout << "Macierz B:\n" << B << std::endl;

    macierz C = A * B;
    std::cout << "Wynik mno¿enia A i B:\n" << C << std::endl;

    return 0;
}
