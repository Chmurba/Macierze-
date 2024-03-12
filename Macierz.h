#ifndef MACIERZ
#define MACIERZ

#include <iostream>

class macierz {
private:
    double dane[2][2];

public:
    // Konstruktory i destruktor
    macierz();
    macierz(const macierz& copy);
    ~macierz();

    // Przeci¹¿one operatory
    macierz operator*(const macierz& copy) const;
    macierz operator+(const macierz& copy) const;
    macierz operator*(const double x) const;
    macierz& operator=(const macierz& copy);
    bool operator==(const macierz& copy) const;
    macierz& operator+=(const macierz& copy);
    macierz& operator*=(const macierz& copy);
    macierz& operator*=(const double x);
    friend std::ostream& operator<<(std::ostream& s, const macierz& m);

    // Metody dostêpu do elementów
    void set(int i, int j, double x);
    double get(int i, int j) const;

    // Metoda transpozycji
    void transpozycja();
};

#endif // MACIERZ_HPP
