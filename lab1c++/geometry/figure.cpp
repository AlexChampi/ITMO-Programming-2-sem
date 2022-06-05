#include "figure.h"

void Point::swap(Point &point) {
    std::swap(x, point.x);
    std::swap(y, point.y);
}


Point::Point() = default;

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point(const Point &point) : Point(point.x, point.y) {}

Point &Point::operator=(const Point &point) {
    if (this == &point) {
        return *this;
    }
    Point newPoint = point;
    swap(newPoint);
    return *this;
}

double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}

Point Point::getPoint() {
    return *this;
}



void Polyline::swap(Polyline &polyline) {
    std::swap(verices, polyline.verices);
    std::swap(sz, polyline.sz);
}

Polyline::Polyline(const std::initializer_list <Point> &lst) : sz(lst.size()), verices(new Point[sz]) {
    std::copy(lst.begin(), lst.end(), verices);
}

Polyline::Polyline(const Polyline &pol) {
    sz = pol.sz;
    verices = new Point[sz];
    std::copy(&pol.verices[0], &pol.verices[pol.sz], verices);
}

Polyline &Polyline::operator=(const Polyline &polyline) {
    if (this == &polyline) {
        return *this;
    }
    Polyline newPolyline = polyline;
    swap(newPolyline);
    return *this;
}

double Polyline::size(int first = 0, int last = -1) {

    double result = 0;
    last = (last == -1) ? sz : last;
    if (first == (sz - 1) && last == 0) {

        result += sqrt(pow((verices[last].getX() - verices[first].getX()), 2) +
                       pow((verices[last].getY() - verices[first].getY()), 2));
    } else {
        for (size_t i = first + 1; i <= last; ++i) {

            result += sqrt(pow((verices[i].getX() - verices[i - 1].getX()), 2) +
                           pow((verices[i].getY() - verices[i - 1].getY()), 2));
        }
    }
    return result;
}


Polyline::~Polyline() {
    delete[] verices;
}



void ClosedPolygonal::swap(ClosedPolygonal &closedPolygonal) {
    std::swap(sz, closedPolygonal.sz);
    std::swap(verices, closedPolygonal.verices);
}

ClosedPolygonal::ClosedPolygonal(const std::initializer_list <Point> &lst) : Polyline(lst) {
    sz = lst.size();
    verices = new Point[sz];
    std::copy(lst.begin(), lst.end(), verices);
}

ClosedPolygonal::ClosedPolygonal(const ClosedPolygonal &closedPolygonal) : Polyline(closedPolygonal) {
    sz = closedPolygonal.sz;
    verices = new Point[sz];
    std::copy(&verices[0], &verices[sz], closedPolygonal.verices);
}


ClosedPolygonal &ClosedPolygonal::operator=(const ClosedPolygonal &closedPolygonal) {
    if (this == &closedPolygonal) {
        return *this;
    }
    ClosedPolygonal newClosedPolygonal = closedPolygonal;
    swap(newClosedPolygonal);
    return *this;
}

double ClosedPolygonal::size() {
    return this->Polyline::size() + this->Polyline::size(sz - 1, 0);
}

ClosedPolygonal::~ClosedPolygonal() {
    delete[] verices;
}



void Polygon::swap(Polygon &Polygon) {
    std::swap(this->sz, Polygon.sz);
    std::swap(this->verices, Polygon.verices);
}


Polygon::Polygon(const std::initializer_list <Point> &lst) : ClosedPolygonal(lst) {
    sz = lst.size();
    verices = new Point[sz];
    std::copy(lst.begin(), lst.end(), verices);
}

Polygon::Polygon(const Polygon &polygon) : ClosedPolygonal(polygon) {
    sz = polygon.sz;
    verices = new Point[sz];
    std::copy(&verices[0], &verices[sz], polygon.verices);
}

Polygon &Polygon::operator=(const Polygon &polygon) {
    if (this == &polygon) {
        return *this;
    }
    Polygon newPolygon = polygon;
    swap(newPolygon);
    return *this;
}

double Polygon::square() {
    double result = verices[sz - 1].getX() * verices[0].getY() - verices[0].getX() * verices[sz - 1].getY();
    for (size_t i = 0; i < sz - 1; ++i) {
        Point p1 = verices[i].getPoint(), p2 = verices[i + 1].getPoint();
        result += p1.getX() * p2.getY();
        result -= p2.getX() * p1.getY();
    }
    return 0.5 * abs(result);
}

Polygon::~Polygon() {
    delete[] verices;
}

void Triangle::swap(Triangle &triangle) {
    std::swap(this->sz, triangle.sz);
    std::swap(this->verices, triangle.verices);
}

Triangle::Triangle(const std::initializer_list <Point> &lst) : Polygon(lst) {
    sz = lst.size();
    verices = new Point[sz];
    std::copy(lst.begin(), lst.end(), verices);
}

Triangle::Triangle(const Triangle &triangle) : Polygon(triangle) {
    sz = triangle.sz;
    verices = new Point[sz];
    std::copy(&verices[0], &verices[sz], triangle.verices);
}

Triangle &Triangle::operator=(const Triangle &triangle) {
    if (this == &triangle) {
        return *this;
    }
    Triangle newTriangle = triangle;
    swap(newTriangle);
    return *this;
}

bool Triangle::isRight() {
    double A = Polyline::size(0, 1);
    //std::cout << A;
    double B = Polyline::size(1, 2);
    double C = Polyline::size(2, 0);
    //std::cout << " " <<B << " " << C;
    return (A * A + B * B == C * C || A * A + C * C == B * B || B * B + C * C == A * A) ? true : false;

}

Triangle::~Triangle() {
    delete[] verices;
}


void Trapeze::swap(Trapeze &trapeze) {
    std::swap(this->sz, trapeze.sz);
    std::swap(this->verices, trapeze.verices);
}

double Trapeze::vectorProduct(Point &a, Point &b) {
    return a.getX() * b.getY() - a.getY() * b.getX();
}

bool Trapeze::isTrapeze() {
    Point A = verices[0], B = verices[1], C = verices[2], D = verices[3];
    Point p1 = Point(A.getX() - B.getX(), A.getY() - B.getY());
    Point p2 = Point(C.getX() - D.getX(), C.getY() - D.getY());
    Point p3 = Point(A.getX() - D.getX(), A.getY() - D.getY());
    Point p4 = Point(B.getX() - C.getX(), B.getY() - C.getY());
    double first = vectorProduct(p1, p2);
    double second = vectorProduct(p3, p4);
    return (first != second && first == 0 || second == 0) ? 1 : 0;
}


Trapeze::Trapeze(const std::initializer_list <Point> &lst) : Polygon(lst) {
    sz = lst.size();
    verices = new Point[sz];
    std::copy(lst.begin(), lst.end(), verices);
    if (!isTrapeze()) {
        std::cout << "Incorrect input";
        exit(-1);
    }
}

Trapeze::Trapeze(const Trapeze &trapeze) : Polygon(trapeze) {
    sz = trapeze.sz;
    verices = new Point[sz];
    std::copy(&verices[0], &verices[sz], trapeze.verices);
}

Trapeze &Trapeze::operator=(const Trapeze &trapeze) {
    if (this == &trapeze) {
        return *this;
    }
    Trapeze newTrapeze = trapeze;
    swap(newTrapeze);
    return *this;
}

Trapeze::~Trapeze() {
    delete[] verices;
}


void RegularPolygon::swap(RegularPolygon &regularPolygon) {
    std::swap(this->sz, regularPolygon.sz);
    std::swap(this->verices, regularPolygon.verices);
}

RegularPolygon::RegularPolygon(const std::initializer_list <Point> &lst) : Polygon(lst) {
    sz = lst.size();
    verices = new Point[sz];
    std::copy(lst.begin(), lst.end(), verices);
}

RegularPolygon::RegularPolygon(const RegularPolygon &trapeze) : Polygon(trapeze) {
    sz = trapeze.sz;
    verices = new Point[sz];
    std::copy(&verices[0], &verices[sz], trapeze.verices);
}

RegularPolygon &RegularPolygon::operator=(const RegularPolygon &regularPolygon) {
    if (this == &regularPolygon) {
        return *this;
    }
    RegularPolygon newRegularPolygon = regularPolygon;
    swap(newRegularPolygon);
    return *this;
}

double RegularPolygon::size() {
    return sz * Polyline::size(0, 1);
}

RegularPolygon::~RegularPolygon() {
    delete[] verices;
}
