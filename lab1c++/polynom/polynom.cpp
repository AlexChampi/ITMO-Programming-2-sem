#include "polynom.h"

void Polynomial::swap(Polynomial &polynomial) {
    std::swap(coefficients, polynomial.coefficients);
}


Polynomial::Polynomial() = default;

Polynomial::Polynomial(std::map<int, int> lst) {
    coefficients = lst;
}


Polynomial::Polynomial(const Polynomial &polynomial) {
    coefficients = polynomial.coefficients;
}

Polynomial &Polynomial::operator=(const Polynomial &polynomial) {
    if (this == &polynomial) {
        return *this;
    }
    Polynomial newPolynomial = polynomial;
    swap(newPolynomial);
    return *this;
}

Polynomial &Polynomial::operator+=(const Polynomial &polynomial) {

    for (auto &item: polynomial.coefficients) {
        coefficients[item.first] += item.second;
    }
    return *this;
}

Polynomial &Polynomial::operator-=(const Polynomial &polynomial) {
    for (auto &item: polynomial.coefficients) {
        coefficients[item.first] -= item.second;
    }
    return *this;
}


Polynomial Polynomial::operator+() {
    return *this;
}

Polynomial Polynomial::operator-() {
    for (auto &item: coefficients) {
        coefficients[item.first] *= -1;
    }
    return *this;
}

Polynomial &Polynomial::operator*=(const double &d) {
    for (auto &item: coefficients) {
        coefficients[item.first] *= d;
    }
    return *this;
}

Polynomial &Polynomial::operator/=(const double &d) {
    for (auto &item: coefficients) {
        coefficients[item.first] /= d;
    }
    return *this;
}

int Polynomial::operator[](int i) {
    return coefficients[i];
}

bool Polynomial::operator==(const Polynomial &a) {
    for (auto &item: coefficients) {
        if (coefficients[item.first] != a.coefficients.find(item.first)->second) {
            return 0;
        }
    }
    return 1;
}

bool Polynomial::operator!=(const Polynomial &a) {
    return (*this == a) ? 0 : 1;
}


Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    Polynomial sum = a;
    sum += b;
    return sum;
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    Polynomial sub = a;
    sub -= b;
    return sub;
};


Polynomial operator*(const Polynomial &a, const double &b) {
    Polynomial mul = a;
    mul *= b;
    return mul;
};


Polynomial operator/(const Polynomial &a, const double &d) {
    Polynomial div = a;
    div /= d;
    return div;
}

std::istream &operator>>(std::istream &in, Polynomial &a) {
    int n;
    in >> n;
    for (int i = 0; i < n; ++i) {
        int f, s;
        in >> f >> s;
        a.coefficients[f] = s;
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const Polynomial &a) {
    out << a.coefficients.size() << '\n';

    for (auto &item: a.coefficients) {
        out << item.first << " " << item.second << "\n";

    }
    return out;
}

