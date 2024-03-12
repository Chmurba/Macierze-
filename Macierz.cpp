#include "macierz.h"

macierz::macierz() {
    // Inicjalizacja zerami
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            dane[i][j] = 0.0;
        }
    }
}

macierz::macierz(const macierz& copy) {
    // Konstruktor kopiuj¹cy
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            dane[i][j] = copy.dane[i][j];
        }
    }
}

macierz::~macierz() {
    // Destruktor
}

macierz macierz::operator*(const macierz& copy) const {
    // Mno¿enie macierzy
    macierz result;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result.dane[i][j] = 0.0;
            for (int k = 0; k < 2; ++k) {
                result.dane[i][j] += dane[i][k] * copy.dane[k][j];
            }
        }
    }
    return result;
}

macierz macierz::operator+(const macierz& copy) const {
    // Dodawanie macierzy
    macierz result;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result.dane[i][j] = dane[i][j] + copy.dane[i][j];
        }
    }
    return result;
}

macierz macierz::operator*(const double x) const {
    // Mno¿enie macierzy przez sta³¹
    macierz result;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result.dane[i][j] = dane[i][j] * x;
        }
    }
    return result;
}

macierz& macierz::operator=(const macierz& copy) {
    // Przypisanie
    if (this != &copy) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                dane[i][j] = copy.dane[i][j];
            }
        }
    }
    return *this;
}

bool macierz::operator==(const macierz& copy) const {
    // Porównanie macierzy
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (dane[i][j] != copy.dane[i][j]) {
                return false;
            }
        }
    }
    return true;
}

macierz& macierz::operator+=(const macierz& copy) {
    // Dodawanie i przypisanie
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            dane[i][j] += copy.dane[i][j];
        }
    }
    return *this;
}

macierz& macierz::operator*=(const macierz& copy) {
    // Mno¿enie i przypisanie
    *this = *this * copy;
    return *this;
}

macierz& macierz::operator*=(const double x) {
    // Mno¿enie przez sta³¹ i przypisanie
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            dane[i][j] *= x;
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& s, const macierz& m) {
    // Wypisywanie macierzy
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            s << m.dane[i][j] << " ";
        }
        s << std::endl;
    }
    return s;
}

void macierz::set(int i, int j, double x) {
    // Ustawianie wartoœci w macierzy
    dane[i][j] = x;
}

double macierz::get(int i, int j) const {
    // Pobieranie wartoœci z macierzy
    return dane[i][j];
}

void macierz::transpozycja() {
    // Transpozycja macierzy
    double temp;
    for (int i = 0; i < 2; ++i) {
        for (int j = i + 1; j < 2; ++j) {
            temp = dane[i][j];
            dane[i][j] = dane[j][i];
            dane[j][i] = temp;
        }
    }
}
