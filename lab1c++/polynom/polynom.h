#include <iostream>
#include <map>
#include <iterator>

class Polynomial {
private:
    std::map<int, int> coefficients;
    void swap(Polynomial&);
    friend std::istream& operator>>(std::istream& in, Polynomial& a);
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& a);
public:
    Polynomial();
    Polynomial(std::map<int, int>);
    Polynomial(const Polynomial&);
    Polynomial& operator=(const Polynomial&);
    Polynomial& operator+=(const Polynomial&);
    Polynomial& operator-=(const Polynomial&);

    Polynomial operator+();
    Polynomial operator-();
    Polynomial& operator*=(const double&);
    Polynomial& operator/=(const double&);
    int operator[](int);
    bool operator==(const Polynomial&);
    bool operator!=(const Polynomial&);
};
Polynomial operator+(const Polynomial& ,const  Polynomial& );
Polynomial operator-(const Polynomial& ,const Polynomial& );
Polynomial operator*(const Polynomial& , const double&);
Polynomial operator/(const Polynomial&, const double&);

std::istream& operator>>(std::istream&, Polynomial&);
std::ostream& operator<<(std::ostream&, const Polynomial&);
