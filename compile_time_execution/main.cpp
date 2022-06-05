#include <iostream>
#include <array>
#include <cmath>
#include <gtest/gtest.h>

template<int Point, int Degree>
struct m_pow {
    static const int value = m_pow<Point, Degree - 1>::value * Point;
};

template<int Point>
struct m_pow<Point, 0> {
    static const int value = 1;
};

template<int Point, int Length, typename Polynomial, Polynomial polynomial>
struct m_polynomial {
    static const int value = polynomial[Length].first * m_pow<Point, polynomial[Length].second>::value +
                             m_polynomial<Point, Length - 1, Polynomial, polynomial>::value;

    friend std::ostream &
    operator<<(std::ostream &out, const m_polynomial<Point, Length, Polynomial, polynomial>) {
        for (int i = 0; i <= Length; ++i) {
            if (polynomial[i].first == 0)
                continue;
            if (i != 0) {
                if (polynomial[i].first >= 0) {
                    out << " + ";
                } else {
                    out << " - ";
                }
            } else {
                if (polynomial[i].first < 0) {
                    out << "-";
                }
            }
            out << abs(polynomial[i].first) << "x^" << polynomial[i].second;
        }
        return out;
    }
};

template<int Point, typename Polynomial, Polynomial polynomial>
struct m_polynomial<Point, 0, Polynomial, polynomial> {
    static const int value = polynomial[0].first * m_pow<Point, polynomial[0].second>::value;
};

template<int T>
int calculate(const std::array<int, T> &pow, const std::array<int, T> &coefficient, int point) {
    int res = 0;
    for (int i = 0; i < T; ++i) {
        res += std::pow(point, pow[i]) * coefficient[i];
    }
    return res;
}



int main() {
    const int n = 4;

//    constexpr std::array<int, n> polynomial = {6, 7, 8, 9};
//    constexpr std::array<int, n> Coefficients = {1, 2, 3, 4};
    constexpr std::array< std::pair<int, int>, 4> Pow = {{{1, 6}, {2, 7}, {3, 8}, {4, 9}}};

    m_polynomial<5, n - 1, std::array<std::pair<int, int>, n>, Pow> qw;
//    int d = calculate<n>(polynomial, Coefficients, 12);
    std::cout << qw << "\n";

}